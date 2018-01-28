//
// Created by Samy on 10/01/2018.
//

#include "GameState.hpp"
#include "SplashState.hpp"
#include "OptionsState.hpp"
#include "ConnexionState.hpp"
#include "LobbyState.hpp"
#include "ReadyState.hpp"

void GameState::changeScreen(std::shared_ptr<IState> &state, std::string s, CoreInfo &info, std::shared_ptr<UgandaEngine::AGameEngine> engine) {
    if (s == "MENU")
    {
        RTypeProtocol::Message msg;
        msg._msg->_header._code = RTypeProtocol::PLAYER_LEAVE_ROOM;
        _roomSocket->SendToServer(msg);
        _roomSocket->shutdown();
        state = std::make_shared<MenuState>(info, engine);
    }
    else if (s == "SPLASH")
        state = std::make_shared<SplashState>(info, engine);
    else if (s == "CONNEXION")
        state = std::make_shared<ConnexionState>(info, engine);
    else if (s == "OPTIONS")
        state = std::make_shared<OptionsState>(info, engine);
    else if (s == "LOBBY")
        state = std::make_shared<LobbyState>(info, engine);
    else if (s == "GAME")
        state = std::make_shared<GameState>(info, engine);
    else if (s == "READY")
        state = std::make_shared<ReadyState>(info, engine);
}

int    GameState::exec() {
    auto previous = std::chrono::system_clock::now();
    std::chrono::duration<double> lag = std::chrono::seconds(0);
	//TODO: Delete ligne suivante:
	Entities[1] = engine->_factory->create(RTypeProtocol::types::SHIP, engine->_libGraph);
    engine->_libGraph->getMusic("Music")->play();
    while (true)
    {
        auto current = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = current - previous;
        previous = current;
        lag += elapsed;

        if (processInput()) {
            engine->_libGraph->getMusic("Music")->stop();
            return 1;
        }

        update();
        while (lag.count() >= MS_PER_UPDATE)
        {
            update();
            lag -= std::chrono::seconds(MS_PER_UPDATE);
        }

        render(lag.count() / MS_PER_UPDATE);
    }
}

void   GameState::init() {
    std::cout << "Start Game" << std::endl;
    CoreInfo::RoomInfo choosenRoom = _info.getRooms()[engine->_libGraph->getJoin()];
    _roomSocket = std::make_shared<ClientUdp>(_info.getHost(), choosenRoom.port, _info.getRandomPort(), _messageQueue);
    _roomSocket.get()->runWithThread();
    RTypeProtocol::Message startMsg;
}

int GameState::processInput()
{
    std::vector<char> actions = engine->_libGraph->handleClientAction();
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
    while (!_messageQueue.isEmpty())
    {
        _rfcGameHandler.executeCommand(_messageQueue.peekMessage(), _messageQueue.peekOwnerID());
        _messageQueue.pop();
    }
}

void GameState::render(double lag)
{
    for (auto e : Entities)
    {
        e.second->_posX += e.second->_speedX * lag;
        e.second->_posY += e.second->_speedY * lag;
    }
    engine->_libGraph->handleGame(this->Entities);
}

