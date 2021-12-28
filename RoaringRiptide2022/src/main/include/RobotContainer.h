// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

// header include guard
#pragma once

// all frc/frc2 includes
#include <frc/XboxController.h>
#include <frc2/command/Command.h>
// all subsystem includes
#include <subsystems/Drive.h>
// all command includes
#include <commands/DefaultDrive.h>
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
  // Drive subsystem
  Drive m_drive;

  // frc::XboxController object for the driver
  frc::XboxController driver_controller{ControllerConstants::driver_controller_port};

  // Configure button bindings will link specific buttons to various commands
  void ConfigureButtonBindings();

};