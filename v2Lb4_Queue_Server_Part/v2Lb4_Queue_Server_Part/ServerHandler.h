#pragma once

#include "Queue.h"
#include "Patient.h"
#include <string>
#include <fstream>


class ServerHandler
{
private:
	Queue<Patient> _patients;
	std::ifstream pat_str;
	void LoadPatients() {

		pat_str.open("patient.txt"); // ? correct

		/*
		* 1. �������� �����
		* 2. ������ �������� � �����
		* 3. �������� �������� � ������������ �������
		* 4. ��������� � �������
		*/
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

