//
// Created by Alexandre on 18/01/2018.
//

#ifndef R_TYPE_NETWORK_H
#define R_TYPE_NETWORK_H

#define PORT_TCP 4242

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include "IServerSocket.h"
#include "IClientSocket.h"
#include "ClientManager.hpp"
#include "OnSocketEvent.h"
#include "ServerTcp.h"

namespace RTypeServer
{
	class Network
	{
	public:
		Network();
		~Network() = default;
		Network(const Network &) = delete;
		Network                 &operator=(const Network &) = delete;

		void					initServer();
		const bool              isRunning() const;

    private:
		void addNewClient(IClientSocket *newClient);

	private:
		std::shared_ptr<IServerSocket>		_Server;
		std::shared_ptr<OnSocketEvent>	_SocketManager;
		bool                    _running;
	};
}

#endif //R_TYPE_NETWORK_H
