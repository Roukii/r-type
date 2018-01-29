//
// Created by alex on 1/26/18.
//

#include "CoreInfo.hpp"

CoreInfo::CoreInfo()
{
	_portRoom = ClientUdp::createAPort();
}

std::shared_ptr<IClientUdpSocket>& CoreInfo::getSocket() {
	return _socket;
}

void CoreInfo::startSocket(const std::string& host, unsigned short hostPort) {
    _host = host;
    _port = ClientUdp::createAPort();
    std::cout << "get random port : " << _port << std::endl;
    std::cout << "host : " << host  << std::endl;
    std::cout << "host port : " << hostPort << std::endl;
    _socket = std::make_shared<ClientUdp>(host, hostPort, _port, _messageQueue);
	_socket.get()->runWithThread();
}

RTypeClient::MessageQueue<RTypeProtocol::Message>& CoreInfo::getMessageQueue() {
	return _messageQueue;
}

void CoreInfo::shutdownSocket() {
	_socket.get()->shutdown();
}

bool CoreInfo::isRunning() const {
	if (_socket.get() == nullptr)
		return false;
	return _socket.get()->isRunning();
}

void CoreInfo::addElemToRoom(CoreInfo::RoomInfo& room) {
	if (_rooms.size() == 4)
	{
		resetRoom();
	}
		_rooms.push_back(room);
}
