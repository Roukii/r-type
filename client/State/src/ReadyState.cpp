//
// Created by Samy on 28/01/2018.
//

#include "ReadyState.hpp"
#include "SplashState.hpp"
#include "GameState.hpp"
#include "OptionsState.hpp"
#include "ConnexionState.hpp"
#include "LobbyState.hpp"

void ReadyState::changeScreen(std::shared_ptr<IState> &state, std::string s, CoreInfo &info, std::shared_ptr<UgandaEngine::AGameEngine> engine) {
    if (s == "MENU")
    {
        RTypeProtocol::Message msg;
        msg._msg->_header._code = RTypeProtocol::PLAYER_LEAVE_ROOM;
        _info.getSocketRoom()->SendToServer(msg);
        _info.getSocketRoom()->shutdown();
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

int    ReadyState::exec() {
    while (!_info.getMessageQueue().isEmpty())
    {
        if (_info.getMessageQueue().peekMessage()._msg->_header._code == (RTypeProtocol::code) RTypeProtocol::START_GAME)
        {
            _info.getSocketRoom()->shutdown();
            return 3;
        }
        _info.getMessageQueue().pop();
    }
    int returnValue = engine->_libGraph->handleReady();
    if (returnValue == 5)
    {
        RTypeProtocol::Message msg;
        msg._msg->_header._code = RTypeProtocol::PLAYER_LEAVE_ROOM;
        _info.getSocketRoom()->SendToServer(msg);
        _info.getSocketRoom()->shutdown();
        return 5;
    }
    if (returnValue == 3 && !ready)
    {
        std::cout << "change status" << std::endl;
        RTypeProtocol::Message msg;
        msg._msg->_header._code = RTypeProtocol::PLAYER_READY;
        _info.getSocketRoom()->SendToServer(msg);
        ready = true;
    }
    else if (returnValue == 3 && ready)
    {
        std::cout << "stop ready" << std::endl;
        RTypeProtocol::Message msg;
        msg._msg->_header._code = RTypeProtocol::PLAYER_NOT_READY;
        _info.getSocketRoom()->SendToServer(msg);
        ready = false;
    }
    return -1;
}

void   ReadyState::init() {
    CoreInfo::RoomInfo choosenRoom = _info.getRooms()[engine->_libGraph->getJoin()];
    _info.getSocketRoom() = std::make_shared<ClientUdp>(_info.getHost(), choosenRoom.port, ClientUdp::createAPort(), _info.getMessageQueue());
    _info.getSocketRoom().get()->runWithThread();
    RTypeProtocol::Message startMsg;
    startMsg._msg.get()->_header._code = RTypeProtocol::PLAYER_JOIN_ROOM;
    _info.getSocketRoom().get()->SendToServer(startMsg);
}