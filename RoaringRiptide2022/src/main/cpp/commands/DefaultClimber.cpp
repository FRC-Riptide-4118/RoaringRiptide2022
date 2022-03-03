// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DefaultClimber.h"

DefaultClimber::DefaultClimber(Climber* m_climber) {
  
  this->m_climber = m_climber;
  AddRequirements({m_climber});

}

// Called repeatedly when this Command is scheduled to run
void DefaultClimber::Execute() {

  this->m_climber->Stop();

}
