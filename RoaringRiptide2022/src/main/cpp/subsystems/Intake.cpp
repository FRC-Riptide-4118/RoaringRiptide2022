// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Intake.h"

Intake::Intake() {

    this->intake_position = false;
    this->RaiseIntake();

    this->intake_motor.SetInverted(true);

}

// This method will be called once per scheduler run
void Intake::Periodic() {}

void Intake::IntakeForward(void) {

    this->intake_motor.Set(ControlMode::PercentOutput, IntakeConstants::intake_speed);

}

void Intake::IntakeBackward(void) {

    this->intake_motor.Set(ControlMode::PercentOutput, -IntakeConstants::intake_speed);

}

void Intake::Stop(void) {

    this->intake_motor.Set(ControlMode::PercentOutput, 0);

}

void Intake::LowerIntake(void) {

    this->intake_arm.Set(frc::DoubleSolenoid::kReverse);

}

void Intake::RaiseIntake(void) {

    this->intake_arm.Set(frc::DoubleSolenoid::kForward);

}

void Intake::ToggleIntake(void) {

    switch (intake_position) {

        case false:
            this->LowerIntake();
            this->intake_position = true;
            break;
        default:
            this->RaiseIntake();
            this->intake_position = false;
            break;

    }

}