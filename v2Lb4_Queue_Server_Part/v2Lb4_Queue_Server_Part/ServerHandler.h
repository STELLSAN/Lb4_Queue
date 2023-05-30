#pragma once

#include "Queue.h"
#include "Patient.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "Converter.h"
#include<WinSock2.h> // Has implementations for working with sockets
#include<WS2tcpip.h> // Contains various programming interfaces related to the operation of TCP/IP



class ServerHandler
{
private:
    Queue<Patient> _patients;
    std::ifstream pat_str;
    Queue<Patient>::Iterator it = _patients.begin();
    void LoadPatients() {
        /*
        * 1. Открытие файла
        * 2. Чтение пациента с файла
        * 3. Создание пациента с прочитанными данными
        * 4. Запустить в очередь
        */
        pat_str.open("../patient.txt");
        std::string tmp;
        if (pat_str.is_open())
        {
            while (std::getline(pat_str, tmp))
            {
                std::stringstream  st_tmp(tmp); // ?? it's ok
                std::string fullName, stt;
                getline(st_tmp, fullName, '|');
                getline(st_tmp, stt, ' ');
                Converter conv;
                Patient tmp_patient = Patient(fullName, conv.StateBook[stt]);
                _patients.Add(tmp_patient);
            }
        }
        pat_str.close();
    }
public:

    
    void sendObject(SOCKET sock) {
        short packet_size = 0;
        const short BUFF_SIZE = 1024;
        //std::vector<char> clientBuff(BUFF_SIZE);
        Converter conv;
        Patient tmp_pat = Patient(_patients.Get());
        std::string inBuff = tmp_pat.GetStringPatientInfo();
        packet_size = send(sock, inBuff.c_str(), inBuff.size(), 0);
    }

    ServerHandler() : _patients(5) {
        LoadPatients();
    }
    
};

