//
// Created by Samy on 10/01/2018.
//

#ifndef R_TYPE_GAMESCREEN_HPP
#define R_TYPE_GAMESCREEN_HPP

#include <chrono>
#include "IState.hpp"
#include "Core.hpp"
#include "RFCClientGameHandler.hpp"

#define MS_PER_UPDATE 16

class GameState : public IState {
    std::shared_ptr<ILib> lib;
	CoreInfo &_info;
	std::shared_ptr<IClientUdpSocket> _roomSocket;
	RTypeClient::MessageQueue<RTypeProtocol::Message> _messageQueue;

    std::map<int, std::shared_ptr<UgandaEngine::Entity>> Entities;

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

    int processInput();

    void update();

    void render(double lag);
};

#endif //R_TYPE_GAMESCREEN_HPP
