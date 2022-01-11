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

    // As of 2022, DifferentialDrive no longer automatically inverts direction
    right.SetInverted(true);

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

    // set the current encoder value to 0
    left_talon1.SetSelectedSensorPosition(0);
    right_talon1.SetSelectedSensorPosition(0);

    // set left PID coefficients for motor controllers
    left_talon1.Config_kF(DriveConstants::left_talon1_id, DriveConstants::kF);
    left_talon1.Config_kP(DriveConstants::left_talon1_id, DriveConstants::kP);
    left_talon1.Config_kI(DriveConstants::left_talon1_id, DriveConstants::kI);
    left_talon1.Config_kD(DriveConstants::left_talon1_id, DriveConstants::kD);

    // set right PID coefficients for motor controllers
    right_talon1.Config_kF(DriveConstants::right_talon1_id, DriveConstants::kF);
    right_talon1.Config_kP(DriveConstants::right_talon1_id, DriveConstants::kP);
    right_talon1.Config_kI(DriveConstants::right_talon1_id, DriveConstants::kI);
    right_talon1.Config_kD(DriveConstants::right_talon1_id, DriveConstants::kD);

    // disable sensor phase sensing
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

void Drive::ResetEncoder() {

    // reset encoders to position 0
    left_talon1.SetSelectedSensorPosition(0);
    right_talon1.SetSelectedSensorPosition(0);

}

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
