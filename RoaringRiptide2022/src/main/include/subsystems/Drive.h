// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include "Constants.h"
#include <frc/DoubleSolenoid.h>

class Drive : public frc2::SubsystemBase {
 public:
  Drive();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void CurvatureDrive(double forward, double rotate);
  void ArcadeDrive(double forward, double rotate);

  void SetHighGear();
  void SetLowGear();

  void ResetEncoder();

  void DriveToDistance(double setpoint);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  WPI_TalonSRX left_talon1 = {DriveConstants::left_talon1};
  WPI_TalonSRX left_talon2 = {DriveConstants::left_talon2};
  WPI_VictorSPX left_victor = {DriveConstants::left_victor};

  WPI_TalonSRX right_talon1 = {DriveConstants::right_talon1};
  WPI_TalonSRX right_talon2 = {DriveConstants::right_talon2};
  WPI_VictorSPX right_victor = {DriveConstants::right_victor};

  frc::SpeedControllerGroup left{left_talon1, left_talon2, left_victor};
  frc::SpeedControllerGroup right{right_talon1, right_talon2, right_victor};

  frc::DifferentialDrive drive{left, right};

  frc::DoubleSolenoid shifter{DriveConstants::PCM_port0_forward, DriveConstants::PCM_port0_reverse};


};
