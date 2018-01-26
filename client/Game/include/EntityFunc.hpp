//
// Created by youssef on 23/01/18.
//

#ifndef R_TYPE_ENTITYFUNC_HPP
#define R_TYPE_ENTITYFUNC_HPP

#include <iostream>
#include <SFML/Audio.hpp>

#include "Entity.hpp"
#include "../../../utils/Protocol/Message.hpp"


struct EntityFunc {
	static void		move_up(RTypeProtocol::Message &msg);
	static void		move_down(RTypeProtocol::Message &msg);
	static void		move_right(RTypeProtocol::Message &msg);
	static void		move_left(RTypeProtocol::Message &msg);
	static void		shoot(RTypeProtocol::Message &msg);
	static void		leave(RTypeProtocol::Message &msg);
	static void		updatePosition(sf::Vector2f, const UgandaEngine::entity::Entity&);
};


#endif //R_TYPE_ENTITYFUNC_HPP
