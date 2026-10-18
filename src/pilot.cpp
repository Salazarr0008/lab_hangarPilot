#include "pilot.h"

#include <iostream>


Pilot::Pilot(std::string name, int skill)
: name_(name), skill_(skill), fatigue_(0), missions_(0) {
    if (name_.empty()) {
        name_ = "Unnamed";
    }
    if (skill_ < 1) {
        skill_ = 1;
    }
    if (skill_ > 100) {
        skill_ = 100;
    }
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

bool Pilot::set_name(const std::string& name) {
    if (name.empty()) {
        return false;
    }
    name_ = name;
    return true;
}

void Pilot::change_skill(int change) {
long long new_skill = static_cast<long long>(skill_) + change;
    if (new_skill < 1) {
        skill_ = 1;
    }
    else if (new_skill > 100) {
        skill_ = 100;
    }
    else {
        skill_ = static_cast<int>(new_skill);
    }
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
