//
// Created by Samy on 10/01/2018.
//

#ifndef R_TYPE_GAMESCREEN_HPP
#define R_TYPE_GAMESCREEN_HPP

#include "IState.hpp"
#include "Core.hpp"
#include "RFCClientGameHandler.hpp"

class GameState : public IState {
    std::shared_ptr<ILib> lib;
	CoreInfo &_info;
	std::shared_ptr<IClientUdpSocket> _roomSocket;
	RTypeClient::MessageQueue<RTypeProtocol::Message> _messageQueue;
    std::map<int, std::shared_ptr<UgandaEngine::entity::Entity>> Entities;
    RTypeClient::RFCClientGameHandler _rfcGameHandler;
    std::shared_ptr<UgandaEngine::AGameEngine> engine;

public:
    GameState(CoreInfo &info, std::shared_ptr<UgandaEngine::AGameEngine> eng) : _info(info), _rfcGameHandler(_roomSocket, Entities, engine), engine(eng) {};
    virtual ~GameState() = default;
    virtual void splash(std::shared_ptr<IState> &state);
    virtual void menu(std::shared_ptr<IState> &state);
    virtual void options(std::shared_ptr<IState> &state);
    virtual void game(std::shared_ptr<IState> &state);
    virtual void connexion(std::shared_ptr<IState> &state);
    virtual void lobby(std::shared_ptr<IState> &state);

    virtual int exec();
    virtual void init(std::shared_ptr<ILib> &lib);

    void processInput();

    void update();

    void render();
};

#endif //R_TYPE_GAMESCREEN_HPP
