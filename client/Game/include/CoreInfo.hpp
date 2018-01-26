//
// Created by alex on 1/26/18.
//

#ifndef R_TYPE_COREINFO_HPP
#define R_TYPE_COREINFO_HPP

#include <memory>

#include "MessageQueue.hpp"
#include "IClientUdpSocket.hpp"
#include "ClientUdp.hpp"
#include "Message.hpp"
#include "Random.h"

class CoreInfo {
public:
	CoreInfo();

	~CoreInfo() = default;

	std::shared_ptr<IClientUdpSocket<RTypeProtocol::Message>> &getSocket();
	void startSocket(const std::string &host, unsigned short port);
	RTypeClient::MessageQueue<RTypeProtocol::Message> &getMessageQueue();

private:
	std::shared_ptr<IClientUdpSocket<RTypeProtocol::Message>> _socket;
	RTypeClient::MessageQueue<RTypeProtocol::Message> _messageQueue;
	unsigned short _port;
};


#endif /* R_TYPE_COREINFO_HPP */
