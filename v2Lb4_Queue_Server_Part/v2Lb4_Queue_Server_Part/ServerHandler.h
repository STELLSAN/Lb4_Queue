#pragma once

#include "Queue.h"
#include "Patient.h"
#include <string>
#include <fstream>
#include <sstream>
#include "Converter.h"



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
				std::stringstream  st_tmp(tmp); // ?? it's ok
				std::string fn, ln, patr, brn_day, brn_mount, brn_year, stt, gndr;
				getline(st_tmp, fn, ' ');
				getline(st_tmp, ln, ' ');
				getline(st_tmp, patr, ' ');
				getline(st_tmp, brn_day, '.');
				getline(st_tmp, brn_mount, '.');
				getline(st_tmp, brn_year, ' ');
				getline(st_tmp, stt, ' ');
				getline(st_tmp, gndr, ' '); // "\0"?
				Date tmp_date;
				tmp_date.day = (unsigned char)brn_day.c_str();
				tmp_date.mount = (unsigned char)brn_mount.c_str();
				tmp_date.year = (unsigned char)brn_year.c_str();
				Converter conv;
				Patient tmp_patient = Patient(fn, ln, patr, tmp_date, conv.StateBook[stt], conv.GenderBook[gndr]);
				_patients.Add(tmp_patient);
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
		if (&tmp_pat != nullptr) { // tmp_pat.IsValid?
			std::string a = "";
			a += tmp_pat.get_firstName() + " ";
			a += tmp_pat.get_lastName() + " ";
			a += tmp_pat.get_patronymic() + " ";
			Converter conv;
			a += conv.DateIntoString(tmp_pat.get_bornDate()) + " ";
			a += conv.GenderIntoStr(tmp_pat.get_gender()) + " ";
			a += conv.StateIntoStr(tmp_pat.get_state());
			return a;
		}
		else {
			// обработка ошибки
		}
	}
};

