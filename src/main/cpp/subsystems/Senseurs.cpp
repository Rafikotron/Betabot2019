/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Senseurs.h"

Senseurs::Senseurs() : Subsystem("Senseurs") {
  captDist = new frc::AnalogInput(kCaptDist);
}

void Senseurs::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

double Senseurs::GetDist()
{
  return captDist->GetVoltage();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
