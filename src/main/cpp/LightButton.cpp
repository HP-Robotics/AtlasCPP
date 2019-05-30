/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "LightButton.h"
#include "SmartDashboard/SmartDashboard.h"

void LightButton(RedButton *b) {
    frc::SmartDashboard::PutBoolean(b->GetName(), true);
}

void UnlightButton(RedButton *b) {
    frc::SmartDashboard::PutBoolean(b->GetName(), false);
}


