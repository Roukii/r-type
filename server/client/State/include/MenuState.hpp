//
// Created by Samy on 10/01/2018.
//

#ifndef R_TYPE_MENUSCREEN_HPP
#define R_TYPE_MENUSCREEN_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Window/Event.hpp>

#include "IState.hpp"
#include "Core.hpp"

class MenuState : public IState {
    int selected = 0;
	CoreInfo &_info;
	std::shared_ptr<UgandaEngine::AGameEngine> engine;
public:
    MenuState(CoreInfo &info, std::shared_ptr<UgandaEngine::AGameEngine> eng) : _info(info), engine(eng) {};
    virtual ~MenuState() = default;
	virtual void changeScreen(std::shared_ptr<IState> &state, std::string s, CoreInfo &info, std::shared_ptr<UgandaEngine::AGameEngine> engine);

    virtual int exec();
    virtual void init();

    void    moveUp();
    int handleKeys(const sf::Event&e);
    void    moveDown();

};

#endif //R_TYPE_MENUSCREEN_HPP
