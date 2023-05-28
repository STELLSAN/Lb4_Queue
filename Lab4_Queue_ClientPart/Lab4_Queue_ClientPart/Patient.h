#pragma once

//
// Created by Nedelin-Dmitry on 13.03.2023.
//

#ifndef UNTITLED4_PATIENT_H
#define UNTITLED4_PATIENT_H
#include <iostream>
#include <map>

enum State {
    DISPANCER, NORMAL, CRITIC
};

enum ObjectType {
    VALID, NOT_VALID
};




class Patient
{
private:
private:
    std::string _fullName;
    State _state;
    ObjectType _patientType;
public:
    Patient(std::string fullName, State state) : _fullName(fullName),
        _state(state), _patientType(ObjectType::VALID) {
    }
    Patient() {
        _patientType = ObjectType::NOT_VALID;
    }

    // Getters
    std::string get_fullName() const { return _fullName; }
    State get_state() const { return _state; }
    bool IsValidPatient() const { return _patientType == ObjectType::VALID; }

    /*
    std::string DateIntoString(Date date) {
        std::string tmp = (reinterpret_cast<char*>(date.day));
        tmp += (reinterpret_cast<char*>(date.mount));
        tmp += (reinterpret_cast<char*>(date.year));
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
    */


    friend std::ostream& operator<<(std::ostream& out, const Patient& patient) {
        out << patient.get_fullName() << " " << patient.get_state() << std::endl;
        return out;
    }

};

#endif UNTITLED4_PATIENT_H