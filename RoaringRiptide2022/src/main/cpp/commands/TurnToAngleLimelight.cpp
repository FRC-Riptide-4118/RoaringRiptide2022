// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/TurnToAngleLimelight.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
TurnToAngleLimelight::TurnToAngleLimelight(Drive* m_drive, Limelight* m_limelight)
    : CommandHelper(
          frc2::PIDController(DriveConstants::limelight_PID_coefficients.kP, DriveConstants::limelight_PID_coefficients.kI, DriveConstants::limelight_PID_coefficients.kD),
          // This should return the measurement
          [m_limelight] { return m_limelight->GetHorizontalOffset(); },
          // This should return the setpoint (can also be a constant)
          [] { return 0; },
          // This uses the output
          [m_drive] (double output) {
            
            m_drive->ArcadeDrive(0, output);

          }) {

            AddRequirements({m_drive, m_limelight});

          }

// Returns true when the command should end.
bool TurnToAngleLimelight::IsFinished() {
  return m_controller.AtSetpoint();
}
