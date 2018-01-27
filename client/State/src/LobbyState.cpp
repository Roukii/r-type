//
// Created by Samy on 22/01/2018.
//

#include "LobbyState.hpp"
#include "GameState.hpp"
#include "SplashState.hpp"
#include "OptionsState.hpp"
#include "ConnexionState.hpp"


void	LobbyState::splash(std::shared_ptr<IState> &state) {
    state = std::make_shared<SplashState>(_info);
}

void	LobbyState::menu(std::shared_ptr<IState> &state) {
    state = std::make_shared<MenuState>(_info);
}

void	LobbyState::options(std::shared_ptr<IState> &state) {
    state = std::make_shared<OptionsState>(_info);
}

void	LobbyState::game(std::shared_ptr<IState> &state) {
    state = std::make_shared<GameState>(_info);
}

void	LobbyState::connexion(std::shared_ptr<IState> &state) {
    state = std::make_shared<ConnexionState>(_info);
}

void	LobbyState::lobby(std::shared_ptr<IState> &state) {
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
        lib->setPlayer("ROOM " + std::to_string(i + 1) , std::to_string(rooms[i].playerNbr));
    }
    return lib->handleLobby();
}

void   LobbyState::init(std::shared_ptr<ILib> &lib) {
    RTypeProtocol::Message msg;
    msg._msg.get()->_header._code = RTypeProtocol::ROOMS;
    _info.getSocket().get()->SendToServer(msg);
    this->lib = lib;
}