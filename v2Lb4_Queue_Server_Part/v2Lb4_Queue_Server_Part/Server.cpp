#include "Server.h"
#include "ServerHandler.h"

Server::Server() {
    SocketInitializationInterface();
    SocketInitializaon();
    SocketBind();
    SocketListenerInitialization();
    ConnectionConfirmation();
    MessageProcessing();
}
    
Server::Server(int _connNum) {
    SocketInitializationInterface();
    SocketInitializaon();
    SocketBind();
    SocketListenerInitialization(_connNum);
    ConnectionConfirmation();	
    MessageProcessing();
}

int Server::SocketInitializationInterface(void) {
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
}

int Server::SocketInitializaon(void) {
    ServSock = socket(AF_INET, SOCK_STREAM, 0);

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
}

int Server::SocketBind(void) {
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
    else {
        std::cout << "Binding socket to Server info is OK" << std::endl;
        return 0;
    }

}

int Server::SocketListenerInitialization(void) {
    erStat = listen(ServSock, SOMAXCONN_HINT(2)); // SONACONN - no connection restrictions

    if (erStat != 0) {
        std::cout << "Can't start to listen to. Error # " << WSAGetLastError() << std::endl;
        closesocket(ServSock);
        WSACleanup();
        return 1;
    }
    else {
        std::cout << "Listening..." << std::endl;
        return 0;
    }
}

int Server::SocketListenerInitialization(int _ConnectionNumbers) {
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
    else {
        std::cout << "Connection to a client established successfully" << std::endl;
        return 0;
    }
}

int Server::ConnectionConfirmation(void){
    ZeroMemory(&clientInfo, sizeof(clientInfo));
    int clientInfo_size = sizeof(clientInfo);

    ClientConn = accept(ServSock, (sockaddr*)&clientInfo, &clientInfo_size);

    if (ClientConn == INVALID_SOCKET) {
        std::cout << "Client detected, but can't connect to a client. Error # " << WSAGetLastError() << std::endl;
        closesocket(ServSock);
        closesocket(ClientConn);
        WSACleanup();
        return 1;
    }
    else {
        std::cout << "Connecton to a client wstablished successfully" << std::endl;
        return 0;
    }
}

int Server::MessageProcessing(void) {
    const char IP_SERV[] = "";          // Enter local Server IP address
    const int PORT_NUM = 0;             // Enter Open working server port
    const short BUFF_SIZE = 1024;
    std::vector<char> servBuff(BUFF_SIZE), clientBuff(BUFF_SIZE);                           // Creation of buffers for sending and receiving data

    //std::vector<char> cstr(str.c_str(), str.c_str() + str.size() + 1);
    short packet_size = 0;                                                              // The size of sending / receiving packet in bytes

    ServerHandler servh = ServerHandler();

    while (true) {
        ServerHandler servH;
        packet_size = recv(ClientConn, servBuff.data(), servBuff.size(), 0);           // Receiving packet from client. Program is waiting (system pause) until receive
        std::cout << "Client's message: " << servBuff.data() << std::endl;
        //a degenerate solution
        // ask how to implement normally using sockets
        // Check whether server would like to stop chatting 
        /*
        * //
        if (strcmp(in_buffer, "get") == 0) {
            ....
        }
        */
        if (servBuff[0] == 'g' && servBuff[1] == 'e' && servBuff[2] == 't') {
            Patient pat = Patient("TEST TEST TEST", State::NORMAL);
            servH.sendObject(ClientConn, pat);
        }
        else if (clientBuff[0] == 'x' && clientBuff[1] == 'x' && clientBuff[2] == 'x') {
            shutdown(ClientConn, SD_BOTH);
            closesocket(ServSock);
            closesocket(ClientConn);
            WSACleanup();
            return 0;
        }
        else {
            std::cout << "Your (host) message: ";
            fgets(clientBuff.data(), clientBuff.size(), stdin);
            packet_size = send(ClientConn, clientBuff.data(), clientBuff.size(), 0);
        }



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
}