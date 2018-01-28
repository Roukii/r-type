//
// Created by Samy on 22/01/2018.
//

#include "LobbyState.hpp"
#include "GameState.hpp"
#include "SplashState.hpp"
#include "OptionsState.hpp"
#include "ConnexionState.hpp"

void LobbyState::changeScreen(std::shared_ptr<IState> &state, std::string s, CoreInfo &info, std::shared_ptr<UgandaEngine::AGameEngine> engine) {
    if (s == "MENU")
        state = std::make_shared<MenuState>(info, engine);
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
}

int    LobbyState::exec() {
    RTypeClient::RFCClientHandler _rfcHandler(_info.getSocket(), _info);

    RTypeClient::MessageQueue<RTypeProtocol::Message> &queue = _info.getMessageQueue();

    while (!queue.isEmpty())
    {
        _rfcHandler.executeCommand(queue.peekMessage(), queue.peekOwnerID());
        queue.pop();
    }

    std::vector<CoreInfo::RoomInfo> rooms = _info.getRooms();

    for (unsigned int i = 0; i < rooms.size(); i++)
    {
        engine->_libGraph->setPlayer("ROOM " + std::to_string(i + 1) , std::to_string(rooms[i].playerNbr));
    }
    return engine->_libGraph->handleLobby();
}

void   LobbyState::init() {
    RTypeProtocol::Message msg;
    msg._msg.get()->_header._code = RTypeProtocol::ROOMS;
    _info.getSocket().get()->SendToServer(msg);
}