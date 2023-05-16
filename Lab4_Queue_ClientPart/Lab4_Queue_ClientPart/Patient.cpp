#include "Patient.h"


Patient::Patient(std::string firstName, std::string lastName, std::string patronymic, Date bornDate, State state, Gender gender) : _firstName(firstName),
_lastName(lastName), _patronymic(patronymic), _state(state), _gender(gender) {
    _bornDate = bornDate;
    _patientType = ObjectType::VALID;
}

Patient::Patient() {
    _patientType = ObjectType::NOT_VALID;
}


const std::string& Patient::getFirstName() const { return _firstName; }
const std::string& Patient::getLastName() const { return _lastName; }
const std::string& Patient::getPatronymic() const { return _patronymic; }
const Date& Patient::getBornDate() const { return _bornDate; }
State Patient::getState() const { return _state; }
Gender Patient::getGender() const { return _gender; }
bool Patient::ISValidPatient() const { return _patientType == ObjectType::VALID; }
