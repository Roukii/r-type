//
// Created by Alexandre on 18/01/2018.
//

#include "ServerTcp.h"

namespace RTypeServer
{
	ServerTcp::ServerTcp()
	{}

	ServerTcp::~ServerTcp()
	{
		_Service.stop();
		_Acceptor->close();
		delete _Acceptor;
	}

	void ServerTcp::runServer()
	{
		_Service.run();
	}

	void ServerTcp::startServer(unsigned short port,
		std::function<void(IClientSocket *newClient)> callback)
	{
		_Acceptor = new boost::asio::ip::tcp::acceptor(_Service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port));
		start_accept(callback);
		_Service.run();
	}

	void ServerTcp::start_accept(std::function<void(IClientSocket *newClient)> callback)
	{
        auto *tmpSocket = new ClientSocket(_Acceptor->get_io_service());

		_Acceptor->async_accept(tmpSocket->getSocket(),
			[this, callback, tmpSocket](boost::system::error_code const &e)
		{
			std::cout << "new client " << std::endl;
			if (!e)
			{
                //_newClient.swap(std::shared_ptr<IClientSocket>(tmpSocket));
				callback(tmpSocket);
				start_accept(callback);
			}
			else
            {
                std::cout << "Error : " << e.message() << std::endl;
                delete tmpSocket;
            }
		});
	}

	void ServerTcp::closeServer()
	{
		_Acceptor->close();
		delete _Acceptor;
		_Service.stop();
	}
}