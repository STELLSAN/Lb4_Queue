#pragma once

//
// Created by Nedelin-Dmitry on 13.03.2023.
//
#define _CRT_SECURE_NO_WARNINGS

#ifndef UNTITLED4_PATIENT_H
#define UNTITLED4_PATIENT_H
#include <iostream>

enum State {
    DISPANCER, NORMAL, CRITIC
};

enum Gender {
    MALE, FEMALE
};

//	словарь соответствий 
enum ObjectType {
    VALID, NOT_VALID
};

// DOB 
struct Date { 
    unsigned char day;
    unsigned char mount;
    unsigned short year;
};


class Patient
{
private:
private:
	std::string _firstName;
	std::string _lastName;
	std::string _patronymic;
	Date _bornDate;
	State _state;
	Gender _gender;
	ObjectType _patientType;
public:
	Patient(std::string firstName, std::string lastName, std::string patronymic, Date bornDate, State state, Gender gender) : _firstName(firstName),
		_lastName(lastName), _patronymic(patronymic), _bornDate(bornDate), _state(state), _gender(gender), _patientType(ObjectType::VALID) {
	}
	Patient() {
		_patientType = ObjectType::NOT_VALID;
	}

	// Getters
	std::string get_firstName() const  { return _firstName; }
	std::string get_lastName() const  { return _lastName; }
	std::string get_patronymic() const  { return _patronymic; }
	Date get_bornDate() const  { return _bornDate; }
	State get_state() const  { return _state; }
	Gender get_gender() const  { return _gender; }
	bool IsValidPatient() const  { return _patientType == ObjectType::VALID; }

	
	// Setters
	void set_firstName(std::string tmp)  { _firstName = tmp;}
	void set_lastName(std::string tmp)  { _lastName = tmp; }
	void set_patronymic(std::string tmp)  { _patronymic = tmp; }
	// lack of checks on input
	void set_state(std::string tmp) { }
	void set_gender(std::string tmp) { }
	

	std::string DateIntoString(Date date) const {
		std::string tmp = (reinterpret_cast<char*>(date.day)) + '.';
		tmp += (reinterpret_cast<char*>(date.mount)) + '.';
		tmp += (reinterpret_cast<char*>(date.year));
		return tmp;
	}

	std::string GenderIntoString() const {
		std::string tmp;
		switch (_gender) {
		case MALE:
			tmp = "MALE";
			break;
		case FEMALE:
			tmp = "FEMALE";
			break;
		default:
			tmp = "Not init";
			break;
		};
		return tmp;
	}

	std::string StateIntoString() const {
		std::string tmp;
		switch (_state) {
		case DISPANCER:
			tmp = "DISPANCER";
			break;
		case NORMAL:
			tmp = "NORMAL";
			break;
		case CRITIC:
			tmp = "CRITIC";
			break;
		default:
			tmp = "Not init";
			break;
		};
		return tmp;
	}

	
	std::string PatientIntoStr() {
		std::string tmp = "";
		tmp += get_firstName() + " ";
		tmp += get_lastName() + " ";
		tmp += get_patronymic() + " ";
		tmp += DateIntoString(get_bornDate()) + " ";
		std::string _tmp = ""; 
		tmp += get_state() + " "; // ?? correct chech enum -> string
		tmp += get_gender() + " "; // ?? analogically TODO 
	}
	

	friend std::ostream& operator<<(std::ostream& out, const Patient& patient) {
		out << patient._firstName << " " << patient._lastName << " " << patient._patronymic << std::endl;
		return out;
	}

};

#endif UNTITLED4_PATIENT_H