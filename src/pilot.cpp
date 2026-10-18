#include "pilot.h"

#include <iostream>


Pilot::Pilot(std::string name, int skill)
: name_(name), skill_(skill), fatigue_(0), missions_(0) {
}

std::string Pilot::name() const {
    return name_;
}

int Pilot::skill() const {
    return skill_;
}

int Pilot::fatigue() const {
    return fatigue_;
}

int Pilot::missions() const {
    return missions_;
}

void Pilot::rest() {
    fatigue_ -= 30;
    if (fatigue_ < 0) {
        fatigue_ = 0;
    }
}

bool Pilot::fly_mission() {
    if (fatigue_ > 80) {
        return false;
    }
    fatigue_ += 20;
    missions_ += 1;
    return true;
}

void Pilot::print() const {
    std::cout << name_ << " | skill " << skill_ << " | fatigue "
              << fatigue_ << " | missions " << missions_ << '\n';
}
