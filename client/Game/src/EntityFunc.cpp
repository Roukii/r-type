//
// Created by youssef on 23/01/18.
//

#include "EntityFunc.hpp"

void EntityFunc::move_up(RTypeProtocol::Message &msg, CoreInfo& info) {
	msg._msg.get()->_header._code = RTypeProtocol::ACTION;
	msg._msg.get()->data._action._action = RTypeProtocol::actions::UP;
	info.getSocket().get()->SendToServer(msg);
}

void EntityFunc::move_down(RTypeProtocol::Message &msg, CoreInfo& info) {
	msg._msg.get()->_header._code = RTypeProtocol::ACTION;
	msg._msg.get()->data._action._action = RTypeProtocol::actions::DOWN;
	info.getSocket().get()->SendToServer(msg);
}

void EntityFunc::move_right(RTypeProtocol::Message &msg, CoreInfo& info) {
	msg._msg.get()->_header._code = RTypeProtocol::ACTION;
	msg._msg.get()->data._action._action = RTypeProtocol::actions::RIGHT;
	info.getSocket().get()->SendToServer(msg);
}

void EntityFunc::move_left(RTypeProtocol::Message &msg, CoreInfo& info) {
	msg._msg.get()->_header._code = RTypeProtocol::ACTION;
	msg._msg.get()->data._action._action = RTypeProtocol::actions::LEFT;
	info.getSocket().get()->SendToServer(msg);
}

void EntityFunc::shoot() {
}

void EntityFunc::leave(RTypeProtocol::Message& msg, CoreInfo& info) {
	msg._msg.get()->_header._code = RTypeProtocol::ACTION;
	msg._msg.get()->data._action._action = RTypeProtocol::actions::LEAVE;
	info.getSocket().get()->SendToServer(msg);
}

void EntityFunc::updatePosition(sf::Vector2f pos, const UgandaEngine::Entity& entity) {
	//
	entity._myGraph->_anims;
}
