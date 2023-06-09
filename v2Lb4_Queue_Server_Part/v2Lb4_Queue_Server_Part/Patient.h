#pragma once

//
// Created by Nedelin-Dmitry on 13.03.2023.
//

#ifndef UNTITLED4_PATIENT_H
#define UNTITLED4_PATIENT_H
#include <iostream>
#include <map>
#include <string>

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

    Patient(const Patient &pat) {
        _fullName = pat._fullName;
        _state = pat._state;
    }

    Patient() {
        _patientType = ObjectType::NOT_VALID;
    }

    // Getters
    std::string get_fullName() const  { return _fullName; }
    State get_state() const  { return _state; }
    bool IsValidPatient() const  { return _patientType == ObjectType::VALID; }
    
    std::string GetStringPatientInfo()
    {
        std::string patientInfo = ""; 
        patientInfo += get_fullName();
        patientInfo += " ";
        patientInfo += (_state == 0 ? "DISPANCER" : _state == 1 ? "NORMAL" : _state == 2 ? "CRITIC" : "not selected");
        return patientInfo;
    }

    friend std::ostream& operator<<(std::ostream& out, const Patient& patient) {
        out << patient.get_fullName() << " " << patient.get_state() << std::endl;
        return out;
    }

};

#endif UNTITLED4_PATIENT_H