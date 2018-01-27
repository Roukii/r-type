//
// Created by alex on 1/26/18.
//

#include "CoreInfo.hpp"

CoreInfo::CoreInfo()
{
}

std::shared_ptr<IClientUdpSocket>& CoreInfo::getSocket() {
	return _socket;
}

void CoreInfo::startSocket(const std::string& host, unsigned short hostPort) {
    getRandomPort();
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

void CoreInfo::getRandomPort() {
    Random<unsigned short> random;
    _port = random.Generate(4000, 5000);
    while (ClientUdp::checkPort(_port))
    {
        _port = random.Generate(4000, 5000);
    }
}