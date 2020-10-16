//============================================================================
// Name        : SyncTimeserver.cpp
// Author      : JLS
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <boost/asio.hpp>

#include "Server.h"
using namespace std;

int main() {
	unsigned short port_num = 3333;
	try {
		Server srv;
		srv.Start(port_num);
		std::this_thread::sleep_for(std::chrono::seconds(60));
		srv.Stop();
	}
	catch (system::system_error&e) {
		std::cout << "Error occured! Error code = "
				<<e.code() << ". Message: "
				<<e.what();
	}
	return 0;
}
