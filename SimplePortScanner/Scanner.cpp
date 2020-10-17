#include "Scanner.h"

Port::~Port()
{
}

bool Port::TestIfOpenTCP()
{
	asio::error_code err;

	asio::io_context context;

	asio::io_context::work dowork(context);

	asio::ip::tcp::endpoint epoint(asio::ip::make_address(this->host, err), this->port);

	asio::ip::tcp::socket socket(context);

	socket.connect(epoint, err);

	cout << "TCP connection" << endl;

	this_thread::sleep_for(500ms);

	if (!err)
	{
		cout << "Connected " << this->port << " is Open " <<endl;

		this->tcpstatus = "Open";

		context.stop();

		return true;
	}
	else
	{
		cout << "Failed to Connect" << err.message() << endl;

		this->tcpstatus = "Close";

		context.stop();

		return false;
	}
}

bool Port::TestIfOpenUDP()
{
	asio::error_code err;

	asio::io_context context;

	asio::io_context::work dowork(context);

	asio::ip::udp::endpoint epoint(asio::ip::make_address(this->host, err), this->port);

	asio::ip::udp::socket socket(context);

	socket.connect(epoint, err);

	cout << "UDP Connection" << endl;

	this_thread::sleep_for(500ms);

	if (!err)
	{
		cout << "Connected " << this->port << " is Open " << endl;

		this->udpstatus = "Open";

		context.stop();

		return true;
	}
	else
	{
		cout << "Failed to Connect" << err.message() << endl;

		this->udpstatus = "Closed";

		context.stop();

		return false;
	}

	
}

string Port::GetDetails()
{
	time_t currenttime = time(NULL);

	return "Host " + this->host + " Port " + to_string(this->port) + " Statuses Are : " +
	" TCP Status: " + this->tcpstatus + " UDP Status: " + this->udpstatus;

}

Results::Results()
{

}

Results::~Results()
{
}

void Results::AddToResults(shared_ptr<Port> result)
{
	
	vec.push_back(result->GetDetails());
}

void Results::DsiplayResultstoConsole()
{
	for (string& s : vec)
	{
		cout << s << endl;
	}
}

void Results::StoreResultAsFile()
{
	cout << "Please Enter File name to Store data" << endl;
	string filename;
	cin.ignore();
	getline(cin, filename);

	string data = "";

	for (string& s : vec)
	{
		data += s + "\n";
	}

	ofstream writeto;
	try
	{
		writeto.open(filename);

		writeto << data;

		cout << "Results stored in " << filename << endl;
	}
	catch (exception e)
	{
		writeto.close();
	}
}
