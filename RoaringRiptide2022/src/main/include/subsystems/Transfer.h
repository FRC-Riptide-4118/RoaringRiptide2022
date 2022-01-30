// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <Constants.h>

class Transfer : public frc2::SubsystemBase {
 public:
  Transfer();
  void Periodic() override;
  void TransferFoward(double setpoint);
  void TransferBackward(double setpoint);

 private:
  WPI_VictorSPX transfer_motor = {TransferConstants::motor_controller_id};

};
