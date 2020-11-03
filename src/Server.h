/*
 * Server.h
 *
 *  Created on: 5 may. 2020
 *      Author: joseluis
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <boost/asio.hpp>
#include <thread>
#include <atomic>
#include <memory>
#include <iostream>

#include "Acceptor.h"
#include "Service.h"

using namespace boost;

class Server {
public:
	Server() : m_stop(false) {}
	void Start(unsigned short port_num) {
		m_thread.reset(new std::thread([this, port_num]() {
			Run(port_num);
		}));
	}
	void Stop() {
		m_stop.store(true);
		m_thread->join();
	}
private:
	void Run(unsigned short port_num) {
		Acceptor acc(m_ios, port_num);
		std::cout << "Servidor asincrono corriendo en el puerto " << port_num << std::endl;
		while (!m_stop.load()) {
			acc.Accept();
		}
	}
	std::unique_ptr<std::thread> m_thread;
	std::atomic<bool> m_stop;
	asio::io_service m_ios;
};

#endif /* SERVER_H_ */
