// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TurnToAngleGyro.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
TurnToAngleGyro::TurnToAngleGyro(Drive* drive, double angle)
    : CommandHelper(
          frc2::PIDController(DriveConstants::rotate_PID_coefficients.kP, DriveConstants::rotate_PID_coefficients.kI, DriveConstants::rotate_PID_coefficients.kD),
          // This should return the measurement
          [drive] { return drive->GetAngle(); },
          // This should return the setpoint (can also be a constant)
          [&angle] { return angle; },
          // This uses the output
          [drive] (double output) {
            // Use the output here
            drive->ArcadeDrive(0, output);
          }) {

            AddRequirements({drive});

          }

// Returns true when the command should end.
bool TurnToAngleGyro::IsFinished() {
  return m_controller.AtSetpoint();
}
