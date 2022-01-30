// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Transfer.h"

Transfer::Transfer() = default;

// This method will be called once per scheduler run
void Transfer::Periodic() {}

void Transfer::TransferFoward(double setpoint) {

    this->transfer_motor.Set(ControlMode::PercentOutput, setpoint);

}

void Transfer::TransferBackward(double setpoint) {

    this->transfer_motor.Set(ControlMode::PercentOutput, -setpoint);

}