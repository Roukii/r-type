//
// Created by Samy on 10/01/2018.
//

#include "GameState.hpp"
#include "SplashState.hpp"
#include "OptionsState.hpp"
#include "ConnexionState.hpp"
#include "LobbyState.hpp"


void	GameState::splash(std::shared_ptr<IState> &state) {
    state = std::make_shared<SplashState>(_info, engine);
}

void	GameState::menu(std::shared_ptr<IState> &state) {
    state = std::make_shared<MenuState>(_info, engine);
}

void	GameState::options(std::shared_ptr<IState> &state) {
    state = std::make_shared<OptionsState>(_info, engine);
}

void	GameState::game(std::shared_ptr<IState> &state) {
}

void	GameState::connexion(std::shared_ptr<IState> &state) {
    state = std::make_shared<ConnexionState>(_info, engine);
}

void	GameState::lobby(std::shared_ptr<IState> &state) {
    state = std::make_shared<LobbyState>(_info, engine);
}

int    GameState::exec() {
    auto previous = std::chrono::system_clock::now();
    std::chrono::duration<double> lag = std::chrono::seconds(0);
	//TODO: Delete ligne suivante:
	//Entities[1] = engine->_factory->create(RTypeProtocol::types::SHIP, engine->_libGraph);
    while (true)
    {
        auto current = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = current - previous;
        previous = current;
        lag += elapsed;

        if (processInput())
            return 1;

        update();
        while (lag.count() >= MS_PER_UPDATE)
        {
            update();
            lag -= std::chrono::seconds(MS_PER_UPDATE);
        }

        render(lag.count() / MS_PER_UPDATE);
    }
}

void   GameState::init(std::shared_ptr<ILib> &lib) {
    CoreInfo::RoomInfo choosenRoom = _info.getRooms()[lib->getJoin()];
    _roomSocket = std::make_shared<ClientUdp>(_info.getHost(), choosenRoom.port, _info.getRandomPort(), _messageQueue);
    _roomSocket.get()->runWithThread();
    RTypeProtocol::Message startMsg;
    startMsg._msg.get()->_header._code = RTypeProtocol::PLAYER_JOIN_ROOM;
    _roomSocket.get()->SendToServer(startMsg);
    startMsg._msg.get()->_header._code = RTypeProtocol::PLAYER_READY;
    _roomSocket.get()->SendToServer(startMsg);

    this->lib = lib;
}

int GameState::processInput()
{
    std::vector<char> actions = lib->handleClientAction();
    RTypeProtocol::Message msg;
    msg._msg.get()->_header._code = RTypeProtocol::ACTION;


    for (auto e : actions) {
        std::cout << "get action" << std::endl;
        if (e == 27)
            return 1;
            //TODO : interpret the action and get UP, DOWN, RIGHT, LEFT, SHOOT, LEAVE
            // il faut faire une récupération des touches dans le state option
        if (myKeys->down)
        {
            std::cout << "it is a down" << std::endl;
            msg._msg.get()->data._action._action = RTypeProtocol::DOWN;
        }
        else if (myKeys->up)
            msg._msg.get()->data._action._action = RTypeProtocol::UP;
        else if (myKeys->left)
            msg._msg.get()->data._action._action = RTypeProtocol::LEFT;
        else if (myKeys->right)
            msg._msg.get()->data._action._action = RTypeProtocol::RIGHT;
        else if (myKeys->shoot)
            msg._msg.get()->data._action._action = RTypeProtocol::SHOOT;
        _roomSocket.get()->SendToServer(msg);
    }
    return 0;

}

void GameState::update()
{
    // check if message
    std::cout << "i am in update" << std::endl;
    while (!_messageQueue.isEmpty())
    {
        _rfcGameHandler.executeCommand(_messageQueue.peekMessage(), _messageQueue.peekOwnerID());
        _messageQueue.pop();
    }
}

void GameState::render(double lag)
{
    if (this->Entities.empty())
        std::cout << "render it's empty" << std::endl;
    else
        std::cout << "render it's not empty" << std::endl;
    for (auto e : Entities)
    {
        std::cout << "change speed" << std::endl;
        e.second->_posX += e.second->_speedX * lag;
        e.second->_posY += e.second->_speedY * lag;
    }
    lib->handleGame(this->Entities);
}
