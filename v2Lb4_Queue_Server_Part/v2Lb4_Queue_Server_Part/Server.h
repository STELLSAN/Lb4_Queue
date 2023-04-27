#pragma once

#include <iostream>
#include<stdio.h>
#include<vector>
#include<WinSock2.h> // Has implementations for working with sockets
#include<WS2tcpip.h> // Contains various programming interfaces related to the operation of TCP/IP
#include<vector>



/*
* 1) ������������� �������� ����������� Win32API						|	Initialization of Win32API socket interfaces
* 2) �������� ������ � ��� �������������								|	Socket creation and initialization
* 3) �������� ������ � ���� IP-�����/����								|	Binding a socket to an IP address/Port pair
* 4) �������������� ������������ ����� ��� ������������� �����������	|	"Listening" on a bound port to identify connections
* 5) ������������� �����������											|	Connection confirmation
* 6) �������� ������ ����� �������� � ��������							|	Data transfer between Client and Server
*/


class Server
{
private:
    //const char IP_SERV[] = "";                                 // Enter local Server IP address
    //const int PORT_NUM = 0;                                         // Enter Open working server port
    //const short BUFF_SIZE = 1024;                                   // Maximum size of buffer for exchange info between server and client
    WSADATA wsData;                                                 // Need for Initializing socket interfaces
    int erStat;                                                     //
    SOCKET ServSock;                                                //
    in_addr ip_to_num;                                              //
    sockaddr_in servInfo;                                           //
    sockaddr_in clientInfo;                                         //  massive
    SOCKET ClientConn;                                              //
    int clientInfoSize;                                             //
    //vector <char> servBuff(BUFF_SIZE), clientBuff(BUFF_SIZE);                           // Creation of buffers for sending and receiving data
    //short packet_size = 0;                                                              // The size of sending / receiving packet in bytes


};