// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/DoubleSolenoid.h>
#include <ctre/Phoenix.h>
#include <Constants.h>

class Intake : public frc2::SubsystemBase {
 public:
  Intake();
  void Periodic() override;
  void IntakeForward(void);
  void IntakeBackward(void);
  void Stop(void);
  void LowerIntake(void);
  void RaiseIntake(void);
  void ToggleIntake(void);

 private:
  bool intake_position;
  WPI_VictorSPX intake_motor = {IntakeConstants::motor_controller_id};
  frc::DoubleSolenoid intake_arm{ frc::PneumaticsModuleType::CTREPCM, IntakeConstants::PCM_intake_arm_forward, IntakeConstants::PCM_intake_arm_reverse };

};
