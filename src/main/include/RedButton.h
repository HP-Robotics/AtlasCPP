/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <Joystick.h>
#include <string>

class RedButton {
  public:
    RedButton(frc::Joystick *j, int id, std::string n);
    std::string GetName();
    bool On();
    bool Held();
    bool Changed();
    void Update();
    void Reset();
    void ToggleOff();
    void ToggleOn();
  private:
    bool held = false;
    bool state = false;
    bool lastState = false;
    bool changed = false;
    bool cbutton;
    std::string name;
    frc::Joystick *stick;
    int num;
};
