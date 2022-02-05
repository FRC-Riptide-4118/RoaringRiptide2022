// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <Constants.h>


class Climber : public frc2::SubsystemBase {
 public:  
  Climber();
  void Periodic() override;
  void RaiseLeftClimber(double, setpoint);
  void LowerLeftClimber(double, setpoint);

  void RaiseRightClimber(double, setpoint);
  void LowerRightClimber(double, setpoint);

 private:
  WPI_VictorSPX climber_right_motor = {ClimberConstants::motor_controller_id};
  WPI_VictorSPX climber_left_motor = {ClimberConstants::motor_controller_id};
};