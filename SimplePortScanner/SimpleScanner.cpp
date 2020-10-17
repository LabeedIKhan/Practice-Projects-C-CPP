

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
#include "Scanner.h"

using namespace std;
void ScanAllPorts();
void ScanThisPort();
void ShowScanning();
void TakeIPAndPort();

static bool isstopped = false;

static string host = "127.0.0.1";
static int lower = 1;
static int upper = 65534;



void StartPortScanning()
{
    cout << "Enter 1 if Your Want to scan all ports or 2 for specific port" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        TakeIPAndPort();

        unique_ptr<thread> th(new thread(ScanAllPorts));

        cin.ignore();

        cin.get();

        isstopped = true;

        cout << "Terminating Scanning Please Press Enter" << endl;

        th->join();
    }
    else if (choice == 2)
    {
       // TakeIPAndPort();

        ScanThisPort();
    }
    else
    {
        cout << "No Selection" << endl;
    }
    
}


void ScanAllPorts()
{
    Results * r = new Results();
    
    for (int i = lower; i < upper +1 ; i++)
    {  
        shared_ptr<Port> port(new Port(host, i));

        port->TestIfOpenTCP();

        port->TestIfOpenUDP();

        r->AddToResults(port);

        cout << "Press Enter to stop" << endl;

        if (isstopped)
        {
            break;
        }
    }
    
    cout << "Scanning Complete" << endl;
    cin.ignore();
    cout << "Please Enter 1 if you want to see result on console and 2 to store them as file";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        r->DsiplayResultstoConsole();
    }
    else if (choice == 2)
    {
        r->StoreResultAsFile();
    }
    else
    {
        cout << "No selection" << endl;
    }
    delete r;
}

void ScanThisPort()
{
    cin.ignore();

    cout << "Please Enter The host IP you want to scan" << endl;

    string host;

    getline(cin, host);

    cout << "Host IP to scan: " << host << endl;

    cout << "Please Enter the Post Number to scan" << endl;

    int num;

    cin >> num;

    cout << "Port Number to Scan: " << num << endl;

    thread th(ShowScanning);

    shared_ptr<Port> port(new Port(host, num));
    port->TestIfOpenTCP();
    port->TestIfOpenUDP();

    isstopped = true;

    th.join();

    cout << "Result is" << endl;
    cout << port->GetDetails() << endl;

}

void ShowScanning() 
{
    while (!isstopped)
    {
        cout << "Scanning" << endl;
        this_thread::sleep_for(1000ms);
    }
}

void OtherOperation()
{
    cout << "Not Implemented" << endl;
}


int main()
{
    cout << "Please Enter Choices 1 for Port Scanning" << endl;

    int choice;

    cin >> choice;

    if (choice == 1)
    {
        StartPortScanning();
    }
    else
    {
        OtherOperation();
    }

    cin.ignore();
}

void TakeIPAndPort()
{
  Again:
    cin.ignore();
    cout << "Please Enter IP Address of Machine To Be Scanned" << endl;
    getline(cin, host);
    cout << "Machine To Be Scanned Is " << host << endl;

    cout << "Please Enter Port Number to Start Scanning With" << endl;
    cin >> lower;

    cout << "Please Enter Port Number to end scanning At" << endl;
    cin >> upper;
    if (upper < lower)
    {
        cout << "Upper must be bigger than lower" << endl;
        goto Again;
    }
    cout << "Scanning will be done from " << lower << " to " << upper << endl;
    //cin.ignore();

}
