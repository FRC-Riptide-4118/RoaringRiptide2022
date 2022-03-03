// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DefaultIntake.h"

DefaultIntake::DefaultIntake(Intake* m_intake) {
  
  this->m_intake = m_intake;
  AddRequirements({m_intake});

}

// Called repeatedly when this Command is scheduled to run
void DefaultIntake::Execute() {

  this->m_intake->Stop();

}
