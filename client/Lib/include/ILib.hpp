//
// Created by Samy on 18/01/2018.
//

#ifndef R_TYPE_ILIB_HPP
#define R_TYPE_ILIB_HPP

#include <iostream>

class ILib {
public:
	virtual ~ILib() = default;
	virtual void		loadLib() = 0;
	virtual void		loadSprite(const std::string &path, const std::string &name) = 0;
	virtual void		deleteSprite(const std::string&) = 0;
	virtual void		loadFont(const std::string &path) = 0;
	virtual void		loadText(float x, float y, unsigned int size, const std::string &str, const std::string &name) = 0;
	virtual void		loadSound(const std::string &path, const std::string &name) = 0;
	virtual void		loadMusic(const std::string &path, const std::string &name) = 0;
};

#endif //R_TYPE_ILIB_HPP
