// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DefaultLauncher.h"

DefaultLauncher::DefaultLauncher(Launcher* m_launcher) {
  
  this->m_launcher = m_launcher;
  AddRequirements({m_launcher});

}

// Called repeatedly when this Command is scheduled to run
void DefaultLauncher::Execute() {

  this->m_launcher->Stop();

}