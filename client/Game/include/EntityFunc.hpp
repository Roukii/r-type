//
// Created by youssef on 23/01/18.
//

#ifndef R_TYPE_ENTITYFUNC_HPP
#define R_TYPE_ENTITYFUNC_HPP

//#include <memory>
#include <iostream>
#include <SFML/Audio.hpp>
#include "CoreInfo.hpp"

#include "Entity.hpp"
#include "../../../utils/Protocol/Message.hpp"


struct EntityFunc {
	static void		move_up(RTypeProtocol::Message &msg, CoreInfo& info);
	static void		move_down(RTypeProtocol::Message &msg, CoreInfo& info);
	static void		move_right(RTypeProtocol::Message &msg, CoreInfo& info);
	static void		move_left(RTypeProtocol::Message &msg, CoreInfo& info);
	static void		shoot();
	static void		leave(RTypeProtocol::Message &msg, CoreInfo& info);
	static void		updatePosition(sf::Vector2f, const UgandaEngine::Entity&);
};


#endif //R_TYPE_ENTITYFUNC_HPP
