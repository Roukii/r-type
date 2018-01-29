//
// Created by Samy on 28/01/2018.
//

#ifndef R_TYPE_READYSTATE_HPP
#define R_TYPE_READYSTATE_HPP

#include "IState.hpp"
#include "Core.hpp"
#include "RFCRoomHandler.hpp"

class ReadyState : public IState {
    bool ready = false;
    CoreInfo &_info;
    std::shared_ptr<UgandaEngine::AGameEngine> engine;
    std::shared_ptr<IClientUdpSocket> _roomSocket;

public:
    ReadyState(CoreInfo &info, std::shared_ptr<UgandaEngine::AGameEngine> eng) : _info(info), engine(eng) {};
    virtual ~ReadyState() = default;
    virtual void changeScreen(std::shared_ptr<IState> &state, std::string s, CoreInfo &info, std::shared_ptr<UgandaEngine::AGameEngine> engine);

    virtual int exec();
    virtual void init();
};

#endif //R_TYPE_READYSTATE_HPP
