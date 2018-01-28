//
// Created by Samy on 10/01/2018.
//

#ifndef R_TYPE_GAMESCREEN_HPP
#define R_TYPE_GAMESCREEN_HPP

#include <chrono>
#include "IState.hpp"
#include "Core.hpp"
#include "RFCClientGameHandler.hpp"
#include "KeyHandler.hpp"

#define MS_PER_UPDATE 16

class GameState : public IState {
	CoreInfo &_info;
	std::shared_ptr<IClientUdpSocket> _roomSocket;
	RTypeClient::MessageQueue<RTypeProtocol::Message> _messageQueue;

    std::map<int, std::shared_ptr<UgandaEngine::Entity>> Entities;

    RTypeClient::RFCClientGameHandler _rfcGameHandler;
    std::shared_ptr<UgandaEngine::AGameEngine> engine;
	std::shared_ptr<key::KeyHandler> myKeys;

public:
    GameState(CoreInfo &info, std::shared_ptr<UgandaEngine::AGameEngine> eng) : _info(info), _rfcGameHandler(_roomSocket, Entities, engine), engine(eng), myKeys(key::instance()) {};
    virtual ~GameState() = default;
	virtual void changeScreen(std::shared_ptr<IState> &state, std::string s, CoreInfo &info, std::shared_ptr<UgandaEngine::AGameEngine> engine);

    virtual int exec();
    virtual void init();

    int processInput();

    void update();

    void render(double lag);
};

#endif //R_TYPE_GAMESCREEN_HPP
