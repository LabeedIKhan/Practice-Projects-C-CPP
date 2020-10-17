#pragma once

#include <chrono>
#include <iostream>
#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif
#define ASIO_STANDALONE
#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>
#include <string>
#include <memory>
#include <memory.h>
#include <fstream>

using namespace std;



class Port
{
private:
	string host;
	int port;
	string tcpstatus;
	string udpstatus;

public:
	Port(string &host, int &port) : host(host), port(port) {};

	~Port();

	bool TestIfOpenTCP();

	bool TestIfOpenUDP();

	string GetDetails();
};

class Results
{
private:
	vector<string> vec;

public:
	Results();

	~Results();

	void AddToResults(shared_ptr<Port> result);

	void DsiplayResultstoConsole();

	void StoreResultAsFile();
};



