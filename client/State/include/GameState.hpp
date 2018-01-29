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
	RTypeClient::MessageQueue<RTypeProtocol::Message> _messageQueue;

    std::map<int, UgandaEngine::Entity *> _entities;

    RTypeClient::RFCClientGameHandler _rfcGameHandler;
    std::shared_ptr<UgandaEngine::AGameEngine> _engine;
	std::shared_ptr<key::KeyHandler> _myKeys;

public:
    GameState(CoreInfo &info, std::shared_ptr<UgandaEngine::AGameEngine> eng) : _info(info), _rfcGameHandler(info.getSocketRoom(), _entities, _engine), _engine(eng), _myKeys(key::instance()) {};
    virtual ~GameState() = default;
	virtual void changeScreen(std::shared_ptr<IState> &state, std::string s, CoreInfo &info, std::shared_ptr<UgandaEngine::AGameEngine> engine);

    virtual int exec();
    virtual void init();

    int processInput();

    void update();

    void render(double lag);
};

#endif //R_TYPE_GAMESCREEN_HPP
