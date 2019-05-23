/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include "RobotMap.h"

#include <frc/WPILib.h>
#include <frc/Joystick.h>

OI::OI() {
  // Process operator interface input here.
  driverStickLeft = new frc::Joystick(DRIVER_STICK_LEFT_ID);
  driverStickRight = new frc::Joystick(DRIVER_STICK_RIGHT_ID);
  operatorStick = new frc::Joystick(OPERATOR_STICK_ID);
}
