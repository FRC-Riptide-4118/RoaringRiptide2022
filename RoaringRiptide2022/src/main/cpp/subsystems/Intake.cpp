// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Intake.h"

Intake::Intake() = default;

// This method will be called once per scheduler run
void Intake::Periodic() {}

void Intake::IntakeForward(double setpoint) {

    this->intake_motor.Set(ControlMode::PercentOutput, setpoint);

}

void Intake::IntakeBackward(double setpoint) {

    this->intake_motor.Set(ControlMode::PercentOutput, -setpoint);

}

void Intake::LowerIntake(void) {

    this->intake_arm.Set(frc::DoubleSolenoid::kForward);

}

void Intake::RaiseIntake(void) {

    this->intake_arm.Set(frc::DoubleSolenoid::kReverse);

}