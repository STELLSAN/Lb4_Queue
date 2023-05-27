#include "Client.h"
#include<iostream>



Client::Client() {
    SocketInitializationInterface();
    SocketInitializaon();
    SocketBind();
    Message_processing();
}

// OK
int Client::SocketInitializationInterface(void) {
    erStat = WSAStartup(MAKEWORD(2, 2), &wsData);
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

//OK
int Client::SocketInitializaon(void) {
    ClientSock = socket(AF_INET, SOCK_STREAM, 0);
    if (ClientSock == INVALID_SOCKET) {
        std::cout << "Error initialization socket # " << WSAGetLastError() << std::endl;
        closesocket(ClientSock);
        WSACleanup();
        return 1;
    }
    else {
        std::cout << "Client socket initialization is OK" << std::endl;
        return 0;
    }
};


int Client::SocketBind(void) {
    erStat = inet_pton(AF_INET, "127.0.0.1", &ip_to_num);
    if (erStat <= 0) {
        std::cout << "Error in IP translation to special numeric format" << std::endl;
        return 1;
    }

    ZeroMemory(&servInfo, sizeof(servInfo));


    servInfo.sin_family = AF_INET;
    servInfo.sin_addr = ip_to_num;
    servInfo.sin_port = htons(1234);

    erStat = connect(ClientSock, (sockaddr*)&servInfo, sizeof(servInfo));
    if (erStat != 0) {
        std::cout << "Connection to Server is FAILED. Error # " << WSAGetLastError() << std::endl;
        closesocket(ClientSock);
        WSACleanup();
        return 1;
    }
    else {
        std::cout << "Connection established SUCCESSFULLY. Ready to send a message to Server" << std::endl;
    }
};

/*
int Client::SocketConnectInitialization() {

    ZeroMemory(&servInfo, sizeof(servInfo));

    servInfo.sin_family = AF_INET;
    servInfo.sin_addr = ip_to_num;	  // Server's IPv4 after inet_pton() function
    servInfo.sin_port = htons(1234);

    erStat = connect(ServSock, (sockaddr*)&servInfo, sizeof(servInfo));

    if (erStat != 0) {
        std::cout << "Connection to Server is FAILED. Error # " << WSAGetLastError() << std::endl;
        closesocket(ServSock);
        WSACleanup();
        return 1;
    }
    else {
        std::cout << "Connection established SUCCESSFULLY. Ready to send a message to Server"
            << std::endl;
    }

}
*/
/*
int Client::SocketListenerInitialization() {
    erStat = listen(ClientSock, SOMAXCONN_HINT(2)); // SONACONN - no connection restrictions

    if (erStat != 0) {
        std::cout << "Can't start to listen to. Error # " << WSAGetLastError() << std::endl;
        closesocket(ClientSock);
        WSACleanup();
        return 1;
    }
    else {
        std::cout << "Listening..." << std::endl;
    }
};
*/

/*
int Client::SocketListenerInitialization(int _connectionsNumbers) {
    sockaddr_in clientInfo;
    ZeroMemory(&clientInfo, sizeof(clientInfo));

    int clientInfoSize = sizeof(clientInfo);

    SOCKET ClientConn = accept(ClientSock, (sockaddr*)&clientInfo, &clientInfoSize);

    if (ClientConn == INVALID_SOCKET) {
        std::cout << "Client detected, but can't connect to a client. Error # " << WSAGetLastError() << std::endl;
        closesocket(ClientSock);
        closesocket(ClientConn);
        WSACleanup();
        return 1;
    }
    else
        std::cout << "Connection to a client established successfully" << std::endl;
};
*/

/*
int Client::ConnectionСonfirmation() {

    ZeroMemory(&clientInfo, sizeof(clientInfo));	// Initializing clientInfo structure
    int clientInfo_size = sizeof(clientInfo);

    SOCKET ClientConn = accept(ClientSock, (sockaddr*)&clientInfo, &clientInfo_size);

    if (ClientConn == INVALID_SOCKET) {
        std::cout << "Client detected, but can't connect to a client. Error # " << WSAGetLastError() << std::endl;
        closesocket(ClientSock);
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
*/

int Client::Message_processing() {
    const char IP_SERV[] = "";          // Enter local Server IP address
    const int PORT_NUM = 0;             // Enter Open working server port
    const short BUFF_SIZE = 1024;

    std::vector<char> servBuff(BUFF_SIZE), clientBuff(BUFF_SIZE);                           // Creation of buffers for sending and receiving data
    short packet_size = 0;                                                              // The size of sending / receiving packet in bytes

    while (true) {
        std::cout << "Your (Client) message to Server: ";
        fgets(clientBuff.data(), clientBuff.size(), stdin);

        // Check whether client like to stop chatting 
        if (clientBuff[0] == 'x' && clientBuff[1] == 'x' && clientBuff[2] == 'x') {
            shutdown(ClientSock, SD_BOTH);
            closesocket(ClientSock);
            WSACleanup();
            return 0;
        }

        packet_size = send(ClientSock, clientBuff.data(), clientBuff.size(), 0);

        if (packet_size == SOCKET_ERROR) {
            std::cout << "Can't send message to Server. Error # " << WSAGetLastError() << std::endl;
            closesocket(ClientSock);
            WSACleanup();
            return 1;
        }

        packet_size = recv(ClientSock, servBuff.data(), servBuff.size(), 0);

        if (packet_size == SOCKET_ERROR) {
            std::cout << "Can't receive message from Server. Error # " << WSAGetLastError() << std::endl;
            closesocket(ClientSock);
            WSACleanup();
            return 1;
        }
        else
            std::cout << "Server message: " << servBuff.data() << std::endl;
        /*
        packet_size = recv(ClientConn, servBuff.data(), servBuff.size(), 0);           // Receiving packet from client. Program is waiting (system pause) until receive
        std::cout << "Client's message: " << servBuff.data() << std::endl;

        std::cout << "Your (host) message: ";
        fgets(clientBuff.data(), clientBuff.size(), stdin);

        // Check whether server would like to stop chatting 
        if (clientBuff[0] == 'x' && clientBuff[1] == 'x' && clientBuff[2] == 'x') {
            shutdown(ClientConn, SD_BOTH);
            closesocket(ServSock);
            closesocket(ServSock);
            WSACleanup();
            return 0;
        }

        packet_size = send(ServSock, clientBuff.data(), clientBuff.size(), 0);

        if (packet_size == SOCKET_ERROR) {
            std::cout << "Can't send message to Client. Error # " << WSAGetLastError() << std::endl;
            closesocket(ServSock);
            closesocket(ServSock);
            WSACleanup();
            return 1;
        }
        */

    }
    closesocket(ServSock);
    closesocket(ServSock);
    WSACleanup();
};