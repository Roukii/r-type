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
    std::chrono::duration<double> lag = std::chrono::milliseconds(0);
    _engine->_libGraph->getMusic("Music")->play();
    while (true)
    {
        auto current = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = current - previous;
        previous = current;
        lag += elapsed;
        if (processInput()) {
            _engine->_libGraph->getMusic("Music")->stop();
            RTypeProtocol::Message msg;
            msg._msg->_header._code = RTypeProtocol::ACTION;
            msg._msg->data._action._action = RTypeProtocol::LEAVE;
            _roomSocket->SendToServer(msg);
            _roomSocket->shutdown();
            return 1;
        }

        update();
        while (lag >= std::chrono::milliseconds(MS_PER_UPDATE))
        {
            update();
            lag -= std::chrono::milliseconds(MS_PER_UPDATE);
        }

        render(lag.count() / MS_PER_UPDATE);
    }
}

void   GameState::init() {
    CoreInfo::RoomInfo choosenRoom = _info.getRooms()[_engine->_libGraph->getJoin()];
    _roomSocket = std::make_shared<ClientUdp>(_info.getHost(), choosenRoom.port, _info.getPortRoom(), _info.getMessageQueue());
    _roomSocket.get()->runWithThread();
    RTypeProtocol::Message startMsg;
}

int GameState::processInput()
{
    std::vector<char> actions = _engine->_libGraph->handleClientAction();
    RTypeProtocol::Message msg;
    msg._msg.get()->_header._code = RTypeProtocol::ACTION;


    for (auto e : actions) {
        if (e == 27)
            return 1;
        if (e == _myKeys->down)
            msg._msg.get()->data._action._action = RTypeProtocol::DOWN;
        else if (e == _myKeys->up)
            msg._msg.get()->data._action._action = RTypeProtocol::UP;
        else if (e == _myKeys->left)
            msg._msg.get()->data._action._action = RTypeProtocol::LEFT;
        else if (e == _myKeys->right)
            msg._msg.get()->data._action._action = RTypeProtocol::RIGHT;
        else if (e == _myKeys->shoot) {
            _engine->_libGraph->getSound("Piou")->play();
            msg._msg.get()->data._action._action = RTypeProtocol::SHOOT;
        }
        _roomSocket.get()->SendToServer(msg);
    }
    return 0;

}

void GameState::update()
{
    // check if message
    while (!_info.getMessageQueue().isEmpty())
    {
        _rfcGameHandler.executeCommand(_info.getMessageQueue().peekMessage(), _info.getMessageQueue().peekOwnerID());
        _info.getMessageQueue().pop();
    }
}

void GameState::render(double lag)
{
    _engine->_libGraph->handleGame(this->_entities);
}

