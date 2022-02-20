// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Limelight.h"

Limelight::Limelight() = default;

void Limelight::StandardView(void) {

    this->table->PutNumber("ledMode", 1);
    this->table->PutNumber("camMode", 1);

}
