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
#include <subsystems/Transfer.h>
#include <subsystems/Limelight.h>
#include <subsystems/Launcher.h>
// all command includes
#include <commands/DefaultDrive.h>
#include <commands/DefaultTransfer.h>
#include <commands/DefaultLimelight.h>
#include <commands/DefaultLauncher.h>
#include <commands/TurnToAngleGyro.h>
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
  // Transfer subsystem
  Transfer m_transfer;
  // Limelight subsystem
  Limelight m_limelight;
  // Launcher subsystem
  Launcher m_launcher;

  // Create a sendable chooser to select which auto will be run
  frc::SendableChooser<frc2::Command*> m_auto_chooser;

  /* ----- SIMPLE COMMAND DECALARATIONS ---- */

  // various lambda functions to define commands
  
  // [TRANSFER]
  frc2::RunCommand run_transfer_forward{ [this] { m_transfer.TransferFoward(); }, {&m_transfer} };
  frc2::RunCommand run_transfer_backwards{ [this] { m_transfer.TransferBackward(); }, {&m_transfer} };
  
  // [LAUNCHER]
  frc2::RunCommand run_launcher{ [this] { m_launcher.RunToSpeed(); }, {&m_launcher} };

  /* ----- AUTO DECLARATIONS ---- */

  // Nothing auto
  frc2::InstantCommand nothing_auto{ [this] { } };

  frc2::SequentialCommandGroup drive_to_distance_auto{

    frc2::InstantCommand{ [this] { m_drive.ResetEncoder(); }, {&m_drive} },
    frc2::RunCommand{ [this] { m_drive.DriveToDistance(DriveConstants::setpoint); }, {&m_drive} }.WithTimeout(1_s)

  };

  frc2::SequentialCommandGroup turn_to_angle{

    frc2::InstantCommand{ [this] { m_drive.ResetAngle(); }, {&m_drive} },
    TurnToAngleGyro(&m_drive, 90).WithTimeout(2_s)

  };

  /* ------ CONTROLLER/BUTTON DECLARATIONS ---- */

  // frc::XboxController object for the driver
  frc::XboxController driver_controller{ControllerConstants::driver_controller_port};

  frc2::Button a_button{[&] { return driver_controller.GetAButton(); } };
  frc2::Button b_button{[&] { return driver_controller.GetBButton(); } };
  frc2::Button right_bumper{[&] { return driver_controller.GetRightBumper(); } };

  // Configure button bindings will link specific buttons to various commands
  void ConfigureButtonBindings();

};