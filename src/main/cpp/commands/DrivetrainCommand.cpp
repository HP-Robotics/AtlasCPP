/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DrivetrainCommand.h"
#include "Robot.h"
#include "ctre/Phoenix.h"

DrivetrainCommand::DrivetrainCommand() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&Robot::m_drivetrainSubsystem);
}

// Called just before this Command runs the first time
void DrivetrainCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DrivetrainCommand::Execute() {
    Robot::m_drivetrainSubsystem.SetOutputs(Robot::m_oi.driverStickLeft->GetRawAxis(1), Robot::m_oi.driverStickRight->GetRawAxis(1));
}

// Make this return true when this Command no longer needs to run execute()
bool DrivetrainCommand::IsFinished() { return false; }

// Called once after isFinished returns true
void DrivetrainCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DrivetrainCommand::Interrupted() {}
