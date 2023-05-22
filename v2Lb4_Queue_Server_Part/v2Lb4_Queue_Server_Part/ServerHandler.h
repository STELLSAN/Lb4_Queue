#pragma once

#include "Queue.h"
#include "Patient.h"
#include <string>
#include <fstream>
#include<sstream>


/*
* 
* 
* 
* 
*/
class ServerHandler
{
private:
	Queue<Patient> _patients;
	std::ifstream pat_str;
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
				//std::cout << tmp << std::endl;
				std::stringstream  st_tmp(tmp); // ?? it's ok
				std::string fn, ln, patr, brn_day, brn_mount, brn_year, stt, gndr;
				getline(st_tmp, fn, ' ');
				getline(st_tmp, ln, ' ');
				getline(st_tmp, patr, ' ');
				getline(st_tmp, brn_day, '.');
				getline(st_tmp, brn_mount, '.');
				getline(st_tmp, brn_year, ' ');
				getline(st_tmp, stt, ' ');
				getline(st_tmp, gndr, ' ');
				// Normal partition, then add setters, etc.
				/*
				std::cout << "-------------------------------------------" << std::endl;
				std::cout << fn << std::endl;
				std::cout << ln << std::endl;
				std::cout << patr << std::endl;
				std::cout << brn_day << std::endl;
				std::cout << brn_mount << std::endl;
				std::cout << brn_year << std::endl;
				std::cout << stt << std::endl;
				std::cout << gndr << std::endl;
				*/
			}
		}
		
		pat_str.close();	
	}
public:


	
	ServerHandler() : _patients(5) {
		LoadPatients();
	}

	

	std::string GetPatient() {
		Patient tmp_pat = _patients.Get();
		std::string a;
		return a;
	}
};

