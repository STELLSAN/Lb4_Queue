#include "Client.h"
#include<iostream>



Client::Client() {
    int SocketInitializationInterface();
    int SocketInitialization();
    int SocketBind();
    int SocketListenerInitialization();
    int ConnectionСonfirmation();
    void Message_processing();
}

int Client::SocketInitializationInterface() {
    WSADATA wsData;
    int erStat = WSAStartup(MAKEWORD(2, 2), &wsData);
    if (erStat != 0) {
        std::cout << "Error WinSock version initialization#";
        std::cout << WSAGetLastError();
        return 1;
    }
    else {
        std::cout << "WinSock initialization is OK" << std::endl;
        return 0;
    }
};

//  std::

int Client::SocketInitialization() {
    if (ServSock == INVALID_SOCKET) {
        std::cout << "Error initialization socket # " << WSAGetLastError() << std::endl;
        closesocket(ServSock);
        WSACleanup();
        return 1;
    }
    else {
        std::cout << "Server socket initialization is OK" << std::endl;
        return 0;
    }
};

int Client::SocketBind() {
    erStat = inet_pton(AF_INET, "127.0.0.1", &ip_to_num);
    if (erStat <= 0) {
        std::cout << "Error in IP translation to special numeric format" << std::endl;
        return 1;
    }
    sockaddr_in servInfo;
    ZeroMemory(&servInfo, sizeof(servInfo));


    servInfo.sin_family = AF_INET;
    servInfo.sin_addr = ip_to_num;
    servInfo.sin_port = htons(1234);

    erStat = bind(ServSock, (sockaddr*)&servInfo, sizeof(servInfo));
    if (erStat != 0) {
        std::cout << "Error Socket binding to server info. Error # " << WSAGetLastError() << std::endl;
        closesocket(ServSock);
        WSACleanup();
        return 1;
    }
    else
        std::cout << "Binding socket to Server info is OK" << std::endl;
};

int Client::SocketListenerInitialization() {
    erStat = listen(ServSock, SOMAXCONN_HINT(2)); // SONACONN - no connection restrictions

    if (erStat != 0) {
        std::cout << "Can't start to listen to. Error # " << WSAGetLastError() << std::endl;
        closesocket(ServSock);
        WSACleanup();
        return 1;
    }
    else {
        std::cout << "Listening..." << std::endl;
    }
};

int Client::SocketListenerInitialization(int _connectionsNumbers) {
    sockaddr_in clientInfo;
    ZeroMemory(&clientInfo, sizeof(clientInfo));

    int clientInfoSize = sizeof(clientInfo);

    SOCKET ClientConn = accept(ServSock, (sockaddr*)&clientInfo, &clientInfoSize);

    if (ClientConn == INVALID_SOCKET) {
        std::cout << "Client detected, but can't connect to a client. Error # " << WSAGetLastError() << std::endl;
        closesocket(ServSock);
        closesocket(ClientConn);
        WSACleanup();
        return 1;
    }
    else
        std::cout << "Connection to a client established successfully" << std::endl;
};

int Client::ConnectionСonfirmation() {

    ZeroMemory(&clientInfo, sizeof(clientInfo));	// Initializing clientInfo structure
    int clientInfo_size = sizeof(clientInfo);

    SOCKET ClientConn = accept(ServSock, (sockaddr*)&clientInfo, &clientInfo_size);

    if (ClientConn == INVALID_SOCKET) {
        std::cout << "Client detected, but can't connect to a client. Error # " << WSAGetLastError() << std::endl;
        closesocket(ServSock);
        closesocket(ClientConn);
        WSACleanup();
        return 1;
    }
    else {
        std::cout << "Connection to a client established successfully" << std::endl;
        char clientIP[22];

        inet_ntop(AF_INET, &clientInfo.sin_addr, clientIP, INET_ADDRSTRLEN);	// Convert connected client's IP to standard string format

        std::cout << "Client connected with IP address " << clientIP << std::endl;

    }
};

int Client::Message_processing() {
    const char IP_SERV[] = "";          // Enter local Server IP address
    const int PORT_NUM = 0;             // Enter Open working server port
    const short BUFF_SIZE = 1024;
    std::vector<char> servBuff(BUFF_SIZE), clientBuff(BUFF_SIZE);                           // Creation of buffers for sending and receiving data
    short packet_size = 0;                                                              // The size of sending / receiving packet in bytes

    while (true) {
        packet_size = recv(ClientConn, servBuff.data(), servBuff.size(), 0);           // Receiving packet from client. Program is waiting (system pause) until receive
        std::cout << "Client's message: " << servBuff.data() << std::endl;

        std::cout << "Your (host) message: ";
        fgets(clientBuff.data(), clientBuff.size(), stdin);

        // Check whether server would like to stop chatting 
        if (clientBuff[0] == 'x' && clientBuff[1] == 'x' && clientBuff[2] == 'x') {
            shutdown(ClientConn, SD_BOTH);
            closesocket(ServSock);
            closesocket(ClientConn);
            WSACleanup();
            return 0;
        }

        packet_size = send(ClientConn, clientBuff.data(), clientBuff.size(), 0);

        if (packet_size == SOCKET_ERROR) {
            std::cout << "Can't send message to Client. Error # " << WSAGetLastError() << std::endl;
            closesocket(ServSock);
            closesocket(ClientConn);
            WSACleanup();
            return 1;
        }

    }
    closesocket(ServSock);
    closesocket(ClientConn);
    WSACleanup();
};