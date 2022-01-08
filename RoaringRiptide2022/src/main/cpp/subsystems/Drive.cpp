// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

// include the Drive subsystem
#include "subsystems/Drive.h"

// Drive constructor
Drive::Drive() {

    // Reset left/right talon information
    left_talon1.ConfigFactoryDefault();
    right_talon1.ConfigFactoryDefault();

    // left motor controllers always follow left_talon1
    left_talon2.Follow(left_talon1);
    left_victor.Follow(left_talon1);

    // right motor controllers always follow right_talon1
    right_talon2.Follow(right_talon1);
    right_victor.Follow(right_talon1);

    // disable safety to avoid weird errors
    drive.SetSafetyEnabled(false);
    left_talon1.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative);
    right_talon1.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative);

    left_talon1.SetSelectedSensorPosition(0);
    right_talon1.SetSelectedSensorPosition(0);

    left_talon1.Config_kF(0, 0);
    left_talon1.Config_kP(0, 0.03);
    left_talon1.Config_kI(0, 0);
    left_talon1.Config_kD(0, 0);

    right_talon1.Config_kF(0, 0);
    right_talon1.Config_kP(0, 0.03);
    right_talon1.Config_kI(0, 0);
    right_talon1.Config_kD(0, 0);

    left_talon1.SetSensorPhase(false);
    right_talon1.SetSensorPhase(false);

}

// This method will be called once per scheduler run
// No implementation necessary
void Drive::Periodic() {}

void Drive::SetHighGear() {

    // extend piston to set high gear
    shifter.Set(frc::DoubleSolenoid::kForward);

}

void Drive::SetLowGear() {

    // retract piston to set low gear
    shifter.Set(frc::DoubleSolenoid::kReverse);
    
}

// TODO: implement functionality
void Drive::ResetEncoder() {}

// TODO: implement functionality
void Drive::DriveToDistance(double setpoint) {

    left_talon1.Set(ControlMode::Position, -setpoint);
    right_talon1.Set(ControlMode::Position, setpoint);
}

void Drive::CurvatureDrive(double forward, double rotate) {

    // call curvature drive on the DifferentialDrive object (with quick turn set to false)
    drive.CurvatureDrive(forward, rotate, false);
    // set low gear perpetually
    this->SetLowGear();

}

void Drive::ArcadeDrive(double forward, double rotate) {

    // call arcade drive on DifferentialDrive object
    drive.ArcadeDrive(forward, rotate);
    // set low gear perpetually
    this->SetLowGear();
}