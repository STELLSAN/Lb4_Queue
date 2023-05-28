#pragma once

#include "Patient.h"
#include <map>
#include <iostream>

class Converter
{
public:
    Converter() {};
    std::map<std::string, State> StateBook = { {"DISPANCER", State::DISPANCER}, {"NORMAL", State::NORMAL} , {"CRITIC", State::CRITIC} }; // Расположение?

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
            throw std::exception("StateIntoStr error");
            break; // обработка ошибки
        }
        return ret;
    }

};

