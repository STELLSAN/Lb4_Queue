#pragma once

#include "Patient.h"
#include <map>
#include <iostream>

class Converter
{
public:
	std::map<std::string, State> StateBook = { {"DISPANCER", State::DISPANCER}, {"NORMAL", State::NORMAL} , {"CRITIC", State::CRITIC} }; // Расположение?
	std::map<std::string, Gender> GenderBook = { {"MALE", Gender::MALE}, {"FEMALE", Gender::FEMALE} };

	std::string DateIntoString(Date date) {
		std::string tmp = (reinterpret_cast<char*>(date.day));
		tmp += (reinterpret_cast<char*>(date.mount));
		tmp += (reinterpret_cast<char*>(date.year));
		return tmp;
	}

	std::string StateIntoStr(State st) {
		std::string ret = "";
		switch (st) {
		case State::NORMAL:
			ret = "NORMAL";
			break;
		case State::DISPANCER:
			ret = "DISPANCER";
			break;
		case State::CRITIC:
			ret = "CRITIC";
			break;
		default:
			break; // обработка ошибки
		}
		return ret;
	}

	std::string GenderIntoStr(Gender gndr) {
		std::string ret = "";
		switch (gndr) {
		case Gender::MALE:
			ret = "MALE";
			break;
		case Gender::FEMALE:
			ret = "FEMALE";
			break;
		default:
			break; // Обработка
		}
		return ret;
	}

};

