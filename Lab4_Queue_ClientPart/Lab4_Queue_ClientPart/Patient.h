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
    Date _bornDate;
    std::string _firstName;
    std::string _lastName;
    std::string _patronymic;

    State _state;
    Gender _gender;
    ObjectType _patientType;

public:

    //Constructor
    Patient(std::string firstName, std::string lastName, std::string patronymic, Date bornDate, State state, Gender gender);
    //default constructor
    Patient();

    // Getters
    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const std::string& getPatronymic() const;
    const Date& getBornDate() const;
    State getState() const;
    Gender getGender() const;
    bool ISValidPatient() const;

    // pin
    friend std::ostream& operator<<(std::ostream& out, const  Patient& patient) {
        out << patient._firstName << " " << patient._lastName << " " << patient._patronymic << std::endl;
    }

};

#endif UNTITLED4_PATIENT_H