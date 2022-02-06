// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <Constants.h>
#include <frc/DigitalInput.h>
#include <frc/Servo.h>

class Climber : public frc2::SubsystemBase {
 public:  
  Climber();
  void Periodic() override;
  void RaiseClimber(void);
  void LowerClimber(void);

 private:
  WPI_VictorSPX climber_right_motor = {ClimberConstants::right_climber_motor_id};
  WPI_VictorSPX climber_left_motor = {ClimberConstants::left_climber_motor_id};

  frc::DigitalInput top_left_limit_switch{ClimberConstants::top_left_limit_switch_port};
  frc::DigitalInput bottom_left_limit_switch{ClimberConstants::bottom_left_limit_switch_port};
  frc::DigitalInput top_right_limit_switch{ClimberConstants::top_right_limit_switch_port};
  frc::DigitalInput bottom_right_limit_switch{ClimberConstants::bottom_right_limit_switch_port};

  frc::Servo left_servo{ClimberConstants::left_servo_port};
  frc::Servo right_servo{ClimberConstants::right_servo_port};

};