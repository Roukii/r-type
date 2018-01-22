//
// Created by alex on 1/18/18.
//

#ifndef DISPLAYTESTS_UGL_HPP
#define DISPLAYTESTS_UGL_HPP

// UGL means Uganda Graphic Library

#include <memory>
#include <map>
#include <functional>

#include "Animation.hpp"
#include "ILib.hpp"
#include "EntityGraphique.hpp"


enum eEntityType {
	NONE = 0,
	SHIP,
	BACKGROUND
};

class UGL : public ILib {
public:
	UGL();
	~UGL() override;
	// TODO : Sami, peux tu stp faire en sorte que cette fonction ne retourne pas un élément de la lib sfml :)
	std::shared_ptr<sf::RenderWindow> getWindow() override
	{return _window;}
protected:
	void 		init() override;
	void		loadLib() override;
	void		loadSprite(const std::string &path, const std::string &name) override;
	std::shared_ptr<sf::Texture>	textureFactory(const std::string&);

	sf::Sprite	*getSprite(const std::string& name) { return _sprites[name].first.get(); }
	sf::Sound	*getSound(const std::string& name) {return _sounds[name].first.get();};
	sf::Text	*getText(const std::string& name) {return _texts[name].get();};
	std::shared_ptr<sf::Texture>	getTexture(const std::string& name) { return _sprites[name].second; }
	eEntityType	getEntity(const std::string&);

	void		deleteSprite(const std::string& name) override;
	void		loadFont(const std::string &path) override;
	void		loadText(float x, float y, unsigned int size, const std::string &str, const std::string &name) override;
	void		loadSound(const std::string &path, const std::string &name) override;
	void		loadMusic(const std::string &path, const std::string &name) override;
	void 		loadAnimation(const std::shared_ptr<sf::Texture>&, const std::string&);

	std::shared_ptr<Animation>	getAnimation(const std::string& name) { return _animations[name]; }
	std::vector<std::shared_ptr<Animation>>	animationFactory(const std::string&);
	std::shared_ptr<EntityFactoryData>	    factoryData(const std::string&) override;


	std::shared_ptr<sf::RenderWindow>	_window;
	sf::Font			_font;
	std::map<std::string, std::pair<std::shared_ptr<sf::Sprite>, std::shared_ptr<sf::Texture>>>	_sprites;
	std::map<std::string, std::pair<std::shared_ptr<sf::Sound>, std::shared_ptr<sf::SoundBuffer>>> 	_sounds;
	std::map<std::string, std::shared_ptr<sf::Music>>	_musics;
	std::map<std::string, std::shared_ptr<sf::Text>>	_texts;
	std::map<std::string, std::shared_ptr<Animation>>	_animations;
};

#endif /* DISPLAYTESTS_UGL_HPP */
