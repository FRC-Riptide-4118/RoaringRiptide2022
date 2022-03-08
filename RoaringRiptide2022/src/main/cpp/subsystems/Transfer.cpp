// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Transfer.h"

Transfer::Transfer() {

    this->transfer_motor.SetInverted(true);

}

// This method will be called once per scheduler run
void Transfer::Periodic() {}

void Transfer::TransferFoward(void) {

    this->transfer_motor.Set(ControlMode::PercentOutput, TransferConstants::transfer_speed);

}

void Transfer::TransferBackward(void) {

    this->transfer_motor.Set(ControlMode::PercentOutput, -TransferConstants::transfer_speed);

}

void Transfer::TransferStop(void) {

    this->transfer_motor.Set(ControlMode::PercentOutput, 0);

}