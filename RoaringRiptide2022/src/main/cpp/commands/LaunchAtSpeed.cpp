// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/LaunchAtSpeed.h"

LaunchAtSpeed::LaunchAtSpeed(Transfer* m_transfer, Launcher* m_launcher) {
  
  this->m_transfer = m_transfer;
  this->m_launcher = m_launcher;

  AddRequirements({m_transfer, m_launcher});

}

// Called repeatedly when this Command is scheduled to run
void LaunchAtSpeed::Execute() {

  this->m_launcher->RunToSpeed();
  switch(this->m_launcher->AtSpeed()) {

    case true:
      this->m_transfer->TransferFoward();
      break;
    default:
      this->m_transfer->TransferStop();
      break;

  }

}