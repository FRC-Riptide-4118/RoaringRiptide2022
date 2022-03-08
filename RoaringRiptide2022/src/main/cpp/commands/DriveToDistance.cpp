// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveToDistance.h"

DriveToDistance::DriveToDistance(Drive* m_drive, double setpoint) {
  
  this->m_drive = m_drive;
  this->setpoint = setpoint;
  this->m_drive->ResetEncoder();
  AddRequirements({m_drive});

}

// Called repeatedly when this Command is scheduled to run
void DriveToDistance::Execute() {

  this->m_drive->DriveToDistance(this->setpoint);

}

// Returns true when the command should end.
bool DriveToDistance::IsFinished() {

  if (this->setpoint > 0) {

     return this->m_drive->GetPosition() >= 0.95*this->setpoint;

  }
  else {

     return this->m_drive->GetPosition() <= 0.95*this->setpoint;

  }

 
}
