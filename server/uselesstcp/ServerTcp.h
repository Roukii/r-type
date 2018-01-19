//
// Created by Alexandre on 18/01/2018.
//

#ifndef R_TYPE_SERVER_TCP_H
#define R_TYPE_SERVER_TCP_H

#include <boost/asio.hpp>
#include <vector>
#include <memory>
#include "IClientSocket.h"
#include "OnSocketEvent.h"
#include "ClientSocket.hpp"
#include "IServerSocket.h"

namespace RTypeServer
{
	class ServerTcp : public IServerSocket
	{
	public:
		ServerTcp();
		~ServerTcp();

		void runServer();
		void startServer(unsigned short port,
			std::function<void(IClientSocket *newClient)> callback);
		void closeServer();

	private:
		void start_accept(std::function<void(IClientSocket *newClient)> callback);

	private:
		boost::asio::io_service			_Service;
		boost::asio::ip::tcp::acceptor *_Acceptor;
		std::shared_ptr<IClientSocket>   _newClient;
	};
}
#endif // R_TYPE_SERVER_TCP_H