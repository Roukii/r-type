//
// Created by Alexandre on 18/01/2018.
//

#ifndef R_TYPE_ON_SOCKET_EVENT_H
#define R_TYPE_ON_SOCKET_EVENT_H

#include "IClientSocket.h"

namespace RTypeServer
{
	class OnSocketEvent
	{
	public:
		virtual ~OnSocketEvent() {};

		virtual void onNewClient(IClientSocket *socket) = 0;
		virtual void onReadFromSocket(IClientSocket &socket) = 0;
		virtual void onWriteFromSocket(IClientSocket &socket) = 0;
		virtual void onDisconnect(IClientSocket &socket) = 0;
		virtual void onCloseServer() = 0;
	};
}

#endif //R_TYPE_ON_SOCKET_EVENT_H
