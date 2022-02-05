// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Climber.h"

Transfer::Transfer() = default;

// This method will be called once per scheduler run
void Climber::Periodic() {}

void Climber::RaiseLeftClimber(double setpoint) {

    this->climber_left_motor.Set(ControlMode::PercentOutput, setpoint);

}

void Climber::RaiseRightClimber(double setpoint) {

    this->climber_right_motor.Set(ControlMode::PercentOutput, setpoint);

}

void Climber::LowerRightClimber(double setpoint) {

    this->climber_right_motor.Set(ControlMode::PercentOutput, -setpoint);

}

void Climber::LowerLeftClimber(double setpoint) {

    this->climber_left_motor.Set(ControlMode::PercentOutput, -setpoint);

}