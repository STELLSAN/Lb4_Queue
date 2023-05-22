#pragma once

#include "Queue.h"
#include "Patient.h"
#include <string>
#include <fstream>


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
		* 1. �������� �����
		* 2. ������ �������� � �����
		* 3. �������� �������� � ������������ �������
		* 4. ��������� � �������
		*/
		pat_str.open("patient.txt"); // ? correct
		std::string tmp;
		if (pat_str.is_open())
		{
			while (std::getline(pat_str, tmp))
			{
				//std::cout << tmp << std::endl;

			}
		}
		
		pat_str.close();	
	}
public:
	
	ServerHandler() : _patients(5) {
		LoadPatients();
	}
	

	std::string GetPatient() {
		Patient tmp_pat = _patients.Pop();
		std::string a;
		return a;
	}
};

