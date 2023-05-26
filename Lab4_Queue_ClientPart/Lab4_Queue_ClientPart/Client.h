#pragma once

#include <iostream>
#include<stdio.h>
#include<vector>
#include<WinSock2.h> // Has implementations for working with sockets
#include<WS2tcpip.h> // Contains various programming interfaces related to the operation of TCP/IP
#include<vector>

#pragma comment(lib, "ws2_32.lib") // WHAT?? 


/*
* 1) Инициализация сокетных интерфейсов Win32API						|	Initialization of Win32API socket interfaces
* 2) Создание сокета и его инициализация								|	Socket creation and initialization
* 3) Привязка сокета к паре IP-адрес/Порт								|	Binding a socket to an IP address/Port pair
* 4) Инициализация сокета подключения	                                |	Connection socket initialization
* 6) Передача данных между Клиентом и Сервером							|	Data transfer between Client and Server
*/


class Client
{
private:

    WSADATA wsData;                                                 // Need for Initializing socket interfaces
    int erStat;                                                     //
    SOCKET ServSock;                                                //
    SOCKET ClientSock;
    in_addr ip_to_num;                                              //
    sockaddr_in servInfo;                                           //
    sockaddr_in clientInfo;                                         //
    SOCKET ClientConn;                                              //
    int clientInfoSize;                                             //

public:


    Client();

    int SocketInitializationInterface(void);    //  1   Initializing socket interfaces
    int SocketInitializaon(void);               //  2   Creating and initializing a socket
    int SocketBind(void);                       //  3   Binding a socket to an IP/port
    //int SocketListenerInitialization();                             //  4.1 Listener without connection limits
    //int SocketListenerInitialization(int _connectionsNumbers);      //  4.2 Connection-Restricted Listener = _connectionsNumbers
    //int SocketConnectInitialization();                              //  4   Connect to server 
    //int ConnectionСonfirmation();                                   //  5   Connection confirmation
    int Message_processing();                                       //  6   Data transfer between Client and Server

};

