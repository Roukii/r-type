//
// Created by Alexandre on 18/01/2018.
//

#ifndef R_TYPE_ICLIENT_SOCKET_H
#define R_TYPE_ICLIENT_SOCKET_H

#include <functional>
#include <string>
#include <memory>

namespace RTypeServer
{
	class IClientSocket
	{
	public:
		virtual ~IClientSocket() {};

		virtual const std::string &getIp() const = 0;
		//virtual Message &getRequest() = 0;
		//virtual ClientData &getData() = 0;
		virtual void readHandler(std::function<void(IClientSocket &client, std::size_t byte)> callback) = 0;
		virtual void writeHandler() = 0;
	};
}

#endif //R_TYPE_ICLIENT_SOCKET_H