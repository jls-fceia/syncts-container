/*
 * Service.h
 *
 *  Created on: 5 may. 2020
 *      Author: joseluis
 */

#ifndef SERVICE_H_
#define SERVICE_H_

#include <boost/asio.hpp>
#include <thread>
#include <atomic>
#include <memory>
#include <iostream>
#include <chrono>
#include <ctime>

using namespace boost;

class Service {
public:
	Service(){}
	void HandleClient(asio::ip::tcp::socket& sock) {
		try {
			std::time_t tt;
			asio::streambuf request;

			tt = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now());
			asio::read_until(sock, request, '\n');
			std::string respuesta = ctime( &tt );
			asio::write(sock, asio::buffer(respuesta));
		}
		catch (system::system_error&e) {
			std::cout << "Error occured! Error code = "
					<<e.code() << ". Message: "
					<<e.what();
		}
	}
};

#endif /* SERVICE_H_ */
