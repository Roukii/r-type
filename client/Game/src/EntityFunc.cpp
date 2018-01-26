//
// Created by youssef on 23/01/18.
//

#include "EntityFunc.hpp"

void EntityFunc::move_up(RTypeProtocol::Message &msg) {
	msg._msg.get()->_header._code = RTypeProtocol::ACTION;
	msg._msg.get()->data._action._action = RTypeProtocol::actions::UP;
}

void EntityFunc::move_down(RTypeProtocol::Message &msg) {
	msg._msg.get()->_header._code = RTypeProtocol::ACTION;
	msg._msg.get()->data._action._action = RTypeProtocol::actions::DOWN;
}

void EntityFunc::move_right(RTypeProtocol::Message &msg) {
	msg._msg.get()->_header._code = RTypeProtocol::ACTION;
	msg._msg.get()->data._action._action = RTypeProtocol::actions::RIGHT;
}

void EntityFunc::move_left(RTypeProtocol::Message &msg) {
	msg._msg.get()->_header._code = RTypeProtocol::ACTION;
	msg._msg.get()->data._action._action = RTypeProtocol::actions::LEFT;
}

void EntityFunc::shoot(RTypeProtocol::Message &msg) {
	msg._msg.get()->_header._code = RTypeProtocol::ACTION;
	msg._msg.get()->data._action._action = RTypeProtocol::actions::SHOOT;
}

void EntityFunc::leave(RTypeProtocol::Message& msg) {
	msg._msg.get()->_header._code = RTypeProtocol::ACTION;
	msg._msg.get()->data._action._action = RTypeProtocol::actions::LEAVE;
}

void EntityFunc::updatePosition(sf::Vector2f pos, const UgandaEngine::entity::Entity& entity) {
	//
	entity.myGraph->_anims;
}
