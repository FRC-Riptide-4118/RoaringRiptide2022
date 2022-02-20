// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DefaultLimelight.h"

DefaultLimelight::DefaultLimelight(Limelight* m_limelight) {
  
  this->m_limelight = m_limelight;
  AddRequirements({m_limelight});

}

// Called repeatedly when this Command is scheduled to run
void DefaultLimelight::Execute() {

  this->m_limelight->StandardView();

}