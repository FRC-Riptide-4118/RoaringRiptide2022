// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

// header include guard
#pragma once

// all frc/frc2 includes
#include <frc/XboxController.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/Command.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/button/Button.h>
#include <frc2/command/ConditionalCommand.h>
#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/WaitCommand.h>
#include <frc2/command/WaitUntilCommand.h>
#include <frc2/command/ParallelRaceGroup.h>
// all subsystem includes
#include <subsystems/Drive.h>
#include <subsystems/Intake.h>
#include <subsystems/Transfer.h>
#include <subsystems/Limelight.h>
#include <subsystems/Launcher.h>
#include <subsystems/Climber.h>
// all command includes
#include <commands/DefaultDrive.h>
#include <commands/DefaultTransfer.h>
#include <commands/DefaultIntake.h>
#include <commands/DefaultLimelight.h>
#include <commands/DefaultLauncher.h>
#include <commands/TurnToAngleGyro.h>
#include <commands/DefaultClimber.h>
#include <commands/LaunchAtSpeed.h>
#include <commands/DriveToDistance.h>
#include <commands/TurnToAngleLimelight.h>
// all other includes
#include <Constants.h>

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
  
  public:
    // Constructor definition
    // No arguments necessary
    RobotContainer();

    // GetAutonomousCommand should return a pointer to an frc2::Command object
    frc2::Command* GetAutonomousCommand();

 private:

  /* ----- SUBSYSTEM DECALARATIONS ----- */

  // Drive subsystem
  Drive m_drive;
  // Intake subsystem
  Intake m_intake;
  // Transfer subsystem
  Transfer m_transfer;
  // Limelight subsystem
  Limelight m_limelight;
  // Launcher subsystem
  Launcher m_launcher;
  // Climber subsystem
  Climber m_climber;

  // Create a sendable chooser to select which auto will be run
  frc::SendableChooser<frc2::Command*> m_auto_chooser;

  /* ----- SIMPLE COMMAND DECALARATIONS ---- */

  // various lambda functions to define commands
  
  // [DRIVE]
  frc2::InstantCommand reset_encoders{ [this] { m_drive.ResetEncoder(); }, {&m_drive} };
  frc2::InstantCommand reset_gyro{ [this] { m_drive.ResetAngle(); }, {&m_drive} };

  // [INTAKE]
  frc2::InstantCommand toggle_intake{ [this] { m_intake.ToggleIntake(); }, {&m_intake} };
  frc2::InstantCommand raise_intake{ [this] { m_intake.RaiseIntake(); }, {&m_intake} };
  frc2::InstantCommand lower_intake{ [this] { m_intake.LowerIntake(); }, {&m_intake} };
  frc2::RunCommand run_intake_forward{ [this] { m_intake.IntakeForward(); }, {&m_intake} };
  frc2::RunCommand run_intake_backward{ [this] { m_intake.IntakeBackward(); }, {&m_intake} };

  // [TRANSFER]
  frc2::RunCommand run_transfer_forward{ [this] { m_transfer.TransferFoward(); }, {&m_transfer} };
  frc2::RunCommand run_transfer_backwards{ [this] { m_transfer.TransferBackward(); }, {&m_transfer} };
  
  // [LAUNCHER]
  frc2::RunCommand run_launcher{ [this] { m_launcher.RunToSpeed(); }, {&m_launcher} };

  // [CLIMBER]
  frc2::RunCommand raise_climber{ [this] { m_climber.RaiseClimber(); }, {&m_climber} };
  frc2::RunCommand lower_climber{ [this] { m_climber.LowerClimber(); }, {&m_climber} };

  // [LIMELIGHT]
  frc2::InstantCommand set_camera_mode_normal{ [this] { m_limelight.StandardView(); }, {&m_limelight} };
  frc2::InstantCommand set_camera_mode_tracking{ [this] { m_limelight.TrackingView(); }, {&m_limelight} };

  /* ----- AUTO DECLARATIONS ---- */

  // Nothing auto
  frc2::InstantCommand nothing_auto{ [this] { } };

  // Drive to Distance
  frc2::SequentialCommandGroup drive_to_distance_auto{

    reset_encoders,
    DriveToDistance(&m_drive, DriveConstants::setpoint).WithTimeout(2_s)

  };

  // Turn to Angle
  frc2::SequentialCommandGroup turn_to_angle_gyro{

    reset_gyro,
    TurnToAngleGyro(&m_drive, 90).WithTimeout(2_s)

  };

  frc2::SequentialCommandGroup turn_to_angle_limelight{

    set_camera_mode_tracking,
    TurnToAngleLimelight(&m_drive, &m_limelight).WithTimeout(2_s)

  };

  // Complex 1
  frc2::SequentialCommandGroup complex_auto1{

    reset_encoders,
    frc2::ParallelCommandGroup{

      lower_intake,
      LaunchAtSpeed(&m_transfer, &m_launcher),
      DriveToDistance(&m_drive, DriveConstants::setpoint).WithTimeout(2_s)

    }

  };

  /* ------ CONTROLLER/BUTTON DECLARATIONS ---- */

  // frc::XboxController object for the driver
  frc::XboxController driver_controller{ControllerConstants::driver_controller_port};

  frc2::Button a_button{[&] { return driver_controller.GetAButton(); } };
  frc2::Button b_button{[&] { return driver_controller.GetBButton(); } };
  frc2::Button x_button{[&] { return driver_controller.GetXButton(); } };
  frc2::Button y_button{[&] { return driver_controller.GetYButton(); } };
  frc2::Button right_bumper{[&] { return driver_controller.GetRightBumper(); } };
  frc2::Button left_bumper{[&] { return driver_controller.GetLeftBumper(); } };
  frc2::Button up_button{[&] { return driver_controller.GetPOV() == 0; } };
  frc2::Button down_button{[&] { return driver_controller.GetPOV() == 180; } };

  // Configure button bindings will link specific buttons to various commands
  void ConfigureButtonBindings();

};