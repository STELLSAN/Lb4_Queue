#pragma once

//
// Created by Nedelin-Dmitry on 13.03.2023.
//

#ifndef UNTITLED4_PATIENT_H
#define UNTITLED4_PATIENT_H
#include <iostream>

enum State {
    DISPANCER, NORMAL, CRITIC
};

enum Gender {
    MALE, FEMALE
};

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

	std::string get_firstName() const  { return _firstName; }
	std::string get_lastName() const  { return _lastName; }
	std::string get_patronymic() const  { return _patronymic; }
	Date get_bornDate() const  { return _bornDate; }
	State get_state() const  { return _state; }
	Gender get_gender() const  { return _gender; }
	bool IsValidPatient() const  { return _patientType == ObjectType::VALID; }

	friend std::ostream& operator<<(std::ostream& out, const Patient& patient) {
		out << patient._firstName << " " << patient._lastName << " " << patient._patronymic << std::endl;
		return out;
	}

};

#endif UNTITLED4_PATIENT_H