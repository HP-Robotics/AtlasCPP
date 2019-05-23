/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DrivetrainSubsystem.h"
#include "commands/DrivetrainCommand.h"
#include "RobotMap.h"

DrivetrainSubsystem::DrivetrainSubsystem() : Subsystem("ExampleSubsystem") {
    topleft = new TalonSRX(TOP_LEFT_MOTOR);
    topright = new TalonSRX(TOP_RIGHT_MOTOR);
    bottomleft = new TalonSRX(BOTTOM_LEFT_MOTOR);
    bottomright = new TalonSRX(BOTTOM_RIGHT_MOTOR);
}

void DrivetrainSubsystem::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new DrivetrainCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DrivetrainSubsystem::SetOutputs(double left, double right) {
    topleft->Set(ControlMode::PercentOutput, left);
    bottomleft->Set(ControlMode::PercentOutput, left);
    topright->Set(ControlMode::PercentOutput, right);
    bottomright->Set(ControlMode::PercentOutput, right);
}
