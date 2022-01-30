// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <Constants.h>

class Launcher : public frc2::SubsystemBase {
 public:
  Launcher();
  void Periodic() override;
  void RunToSpeed(double setpoint);
  void Stop(void);

 private:
  TalonFX launcher_motor{LauncherConstants::motor_controller_id};

};