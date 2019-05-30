/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RedButton.h"

RedButton::RedButton(frc::Joystick *j, int id, std::string n) {
    stick = j;
    num = id;
    name = n;
}

std::string RedButton::GetName() {
    return name;
}

bool RedButton::On() {
    return state;
}

bool RedButton::Held() {
    return held;
}

bool RedButton::Changed() {
    return changed;
}

void RedButton::Update() {
    cbutton = stick->GetRawButton(num);
    // TODO Check with Jeremy if you need to check for cbutton too.
    if(cbutton != lastState) {
        state = !state;
        changed = true;
    } else {
        changed = false;
    }

    held = cbutton;
    lastState = cbutton;
}

void RedButton::Reset() {
    state = false;
    lastState = false;
    changed = false;
}

void RedButton::ToggleOff() {
    Reset();
    Update();
}

void RedButton::ToggleOn() {
    state = true;
}