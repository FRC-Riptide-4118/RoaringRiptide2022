// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DefaultTransfer.h"

DefaultTransfer::DefaultTransfer(Transfer* m_transfer) {
  
  this->m_transfer = m_transfer;
  AddRequirements({m_transfer});

}
// Called repeatedly when this Command is scheduled to run
void DefaultTransfer::Execute() {

  this->m_transfer->TransferStop();

}