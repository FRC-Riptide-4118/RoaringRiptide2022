// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drive.h"

Drive::Drive() {

    left_talon1.ConfigFactoryDefault();
    right_talon1.ConfigFactoryDefault();

    left_talon2.Follow(left_talon1);
    left_victor.Follow(left_talon1);

    right_talon2.Follow(right_talon1);
    right_victor.Follow(right_talon1);

    drive.SetSafetyEnabled(false);

}

// This method will be called once per scheduler run
void Drive::Periodic() {}

void Drive::SetHighGear() {

    shifter.Set(frc::DoubleSolenoid::kForward);

}

void Drive::SetLowGear() {

    shifter.Set(frc::DoubleSolenoid::kReverse);
    
}

// TODO: implement functionality
void Drive::ResetEncoder() {}

// TODO: implement functionality
void Drive::DriveToDistance(double setpoint) {}

void Drive::CurvatureDrive(double forward, double rotate) {

    drive.CurvatureDrive(forward, rotate, false);
    this->SetLowGear();

}

void Drive::ArcadeDrive(double forward, double rotate) {

    drive.ArcadeDrive(forward, rotate);
    this->SetLowGear();
}