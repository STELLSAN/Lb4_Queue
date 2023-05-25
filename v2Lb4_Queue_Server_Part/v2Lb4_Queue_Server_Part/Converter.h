#pragma once

#include "Patient.h"
#include <map>
#include <iostream>

class Converter
{
public:
	std::map<std::string, State> StateBook = { {"DISPANCER", State::DISPANCER}, {"NORMAL", State::NORMAL} , {"CRITIC", State::CRITIC} }; // Расположение?
	std::map<std::string, Gender> GenderBook = { {"MALE", Gender::MALE}, {"FEMALE", Gender::FEMALE} };
};

