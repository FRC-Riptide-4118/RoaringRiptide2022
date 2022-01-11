// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

// header include guard
#pragma once

// all frc/frc2 includes
#include <frc2/command/SubsystemBase.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/DoubleSolenoid.h>
#include <frc/LinearFilter.h>
// CTRE/Phoenix include
#include "ctre/Phoenix.h"
// all other includes
#include "Constants.h"

// The Drive subsystem will represent an abstraction of the drivebase to allow for general robot mobility
class Drive : public frc2::SubsystemBase {
 
 public:
  // Drive constructor takes no arguments
  Drive();
  // Periodic method will not run anything
  void Periodic() override;
  // Curvature drive implementation
  void CurvatureDrive(double forward, double rotate);
  // Arcade drive implementation
  void ArcadeDrive(double forward, double rotate);
  // SetHighGear will shift drivetrain into high gear
  void SetHighGear();
  // SetLowGear will shift drivetrain into low gear
  void SetLowGear();
  // ResetEncoder will set both left and right encoders to 0
  void ResetEncoder();
  // Get the current (filtered) velocity
  double GetVelocity();
  // DriveToDistance will use PID control and encoders to drive a specific distance in a straight line
  void DriveToDistance(double setpoint);

 private:
  // All of the left motor controllers are defined here
  WPI_TalonSRX left_talon1 = {DriveConstants::left_talon1_id};
  WPI_TalonSRX left_talon2 = {DriveConstants::left_talon2_id};
  WPI_VictorSPX left_victor = {DriveConstants::left_victor_id};
  // All of the right motor controllers are declared here
  WPI_TalonSRX right_talon1 = {DriveConstants::right_talon1_id};
  WPI_TalonSRX right_talon2 = {DriveConstants::right_talon2_id};
  WPI_VictorSPX right_victor = {DriveConstants::right_victor_id};
  // The left and right motor controllers are turned into SpeedControllerGroups
  frc::SpeedControllerGroup left{left_talon1, left_talon2, left_victor};
  frc::SpeedControllerGroup right{right_talon1, right_talon2, right_victor};
  // The SpeedControllerGroups form a DifferentialDrive
  frc::DifferentialDrive drive{left, right};
  // The gear shift can be viewed as an abstraction of a double solenoid
  frc::DoubleSolenoid shifter{DriveConstants::PCM_shifter_forward, DriveConstants::PCM_shifter_reverse};
  // filter for retrieving encoder information
  frc::LinearFilter<double> encoder_filter = frc::LinearFilter<double>::SinglePoleIIR(DriveConstants::encoder_filter_cutoff_frequency, ROBORIO_LOOP_PERIOD);

};