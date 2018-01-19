//
// Created by Alexandre on 18/01/2018.
//

#ifndef R_TYPE_ISERVER_SOCKET_H
#define R_TYPE_ISERVER_SOCKET_H

#include <functional>
#include "IClientSocket.h"
#include "OnSocketEvent.h"

 namespace RTypeServer
{
	class IServerSocket
	{
	public:
		virtual ~IServerSocket() {};

		virtual void runServer() = 0;
		virtual void startServer(unsigned short port, std::function<void(IClientSocket *newClient)>) = 0;
		virtual void closeServer() = 0;
	};
}

#endif //R_TYPE_ISERVER_SOCKET_H
