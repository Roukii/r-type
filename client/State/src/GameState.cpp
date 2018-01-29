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

int    GameState::exec() {
    auto previous = std::chrono::system_clock::now();
    std::chrono::duration<double> lag = std::chrono::seconds(0);
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
            _info.getSocketRoom()->SendToServer(msg);
            _info.getSocketRoom()->shutdown();
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
}

int GameState::processInput()
{
    std::vector<char> actions = _engine->_libGraph->handleClientAction();
    RTypeProtocol::Message msg;
    msg._msg.get()->_header._code = RTypeProtocol::ACTION;


    for (auto e : actions) {
        std::cout << "get action" << std::endl;
        if (e == 27)
            return 1;
            //TODO : interpret the action and get UP, DOWN, RIGHT, LEFT, SHOOT, LEAVE
            // il faut faire une récupération des touches dans le state option
        if (e == _myKeys->down)
            msg._msg.get()->data._action._action = RTypeProtocol::DOWN;
        else if (e == _myKeys->up)
            msg._msg.get()->data._action._action = RTypeProtocol::UP;
        else if (e == _myKeys->left)
            msg._msg.get()->data._action._action = RTypeProtocol::LEFT;
        else if (e == _myKeys->right)
            msg._msg.get()->data._action._action = RTypeProtocol::RIGHT;
        else if (e == _myKeys->shoot)
            msg._msg.get()->data._action._action = RTypeProtocol::SHOOT;
        _info.getSocketRoom().get()->SendToServer(msg);
    }
    return 0;

}

void GameState::update()
{
    // check if message
    while (!_info.getMessageQueue().isEmpty())
    {
        std::cout << "[DBG] Message queue of size : "<< _info.getMessageQueue().size() << std::endl;
        _rfcGameHandler.executeCommand(_info.getMessageQueue().peekMessage(), _info.getMessageQueue().peekOwnerID());
        _info.getMessageQueue().pop();
        std::cout << "[DBG] Message queue new size after pop : "<< _info.getMessageQueue().size() << std::endl;
    }
}

void GameState::render(double lag)
{
    _engine->_libGraph->handleGame(this->_entities);
}

