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
	struct RoomInfo
	{
		int playerNbr;
		bool inGame;
		unsigned short port;
	};

public:
	CoreInfo();

	~CoreInfo() = default;

	std::shared_ptr<IClientUdpSocket> &getSocket();
	void startSocket(const std::string &host, unsigned short port);
	void shutdownSocket();
	bool isRunning() const;
	RTypeClient::MessageQueue<RTypeProtocol::Message> &getMessageQueue();
	const std::vector<RoomInfo> &getRooms() { return _rooms; }
	void addElemToRoom(RoomInfo &room);
	void resetRoom() { _rooms.clear(); }
	const std::string &getHost() const { return _host; };
	unsigned short getPortRoom() const { return _portRoom; };

private:
	std::shared_ptr<IClientUdpSocket> _socket;
	RTypeClient::MessageQueue<RTypeProtocol::Message> _messageQueue;
	unsigned short _port;
	unsigned short _portRoom;
	std::vector<RoomInfo> _rooms;
	std::string _host;
    // TODO put a message if connection failed
    //bool connectionFailed;
};


#endif /* R_TYPE_COREINFO_HPP */
