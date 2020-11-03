/*
 * Acceptor.h
 *
 *  Created on: 5 may. 2020
 *      Author: joseluis
 */

#ifndef ACCEPTOR_H_
#define ACCEPTOR_H_

#include <boost/asio.hpp>
#include <thread>
#include <atomic>
#include <memory>
#include <iostream>

#include "Service.h"

using namespace boost;

class Acceptor {
public:
	Acceptor(asio::io_service&ios, unsigned short port_num) :
		m_ios(ios),
		m_acceptor(m_ios,
				asio::ip::tcp::endpoint(
						asio::ip::address_v4::any(),
						port_num))
{
		m_acceptor.listen();
}
	void Accept() {
		asio::ip::tcp::socket sock(m_ios);
		m_acceptor.accept(sock);
		Service svc;
		std::cout << "conexion desde ";
		std::cout << sock.local_endpoint().address().to_string() << ":" << 
			sock.remote_endpoint().port() << std::endl;
		svc.HandleClient(sock);
	}
private:
	asio::io_service & m_ios;
	asio::ip::tcp::acceptor m_acceptor;
};

#endif /* ACCEPTOR_H_ */
