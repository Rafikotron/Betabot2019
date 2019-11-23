/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include <commands/Autonome.h>
#include <commands/Advance.h>
#include <Robot.h>
#include <algorithm>

#include <frc/WPILib.h>

OI::OI() {
   mJoystickPtr = new frc::Joystick(kJoystick);
   m1ButtonPtr = new frc::JoystickButton(mJoystickPtr, 1);
   m1ButtonPtr->WhenPressed(new Autonome());
   canTurn = true;
  // Process operator interface input here.
}

double OI::GetXJoystick() 
{if (Robot::m_senseurs.GetDist2()<2)
  {
    return  std::min(double(mJoystickPtr->GetRawAxis(kJoystickX) * GetSlider()),0.0);
  }
  else
  {
    return mJoystickPtr->GetRawAxis(kJoystickX) * GetSlider();
  }
}

double OI::GetYJoystick() 
{
  if (Robot::m_senseurs.GetDist()<2)
  {
    return  std::min(double(-mJoystickPtr->GetRawAxis(kJoystickY) * GetSlider()),0.0);
  }
  else
  {
    return -mJoystickPtr->GetRawAxis(kJoystickY) * GetSlider();
  }
}

double OI::GetZJoystick()
{
  if (!canTurn)
  {
    return 0;
  }
  else
  {
    return mJoystickPtr->GetRawAxis(kJoystickZ) * GetSlider();
  }
}

double OI::GetSlider()
{
  return (1-mJoystickPtr->GetRawAxis(kJoystickSlider))/2;
}