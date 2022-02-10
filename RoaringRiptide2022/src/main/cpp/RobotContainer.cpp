// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

// include RobotContainer
#include "RobotContainer.h"

RobotContainer::RobotContainer() {

  // Set up the Drive subsystem to have a default command that allows it to be driven via Xbox controller
  // Required the use of lambda functions to set up
  m_drive.SetDefaultCommand( DefaultDrive{ &m_drive, [this] {return driver_controller.GetLeftY(); }, [this] {return driver_controller.GetRightX(); } } );

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {

  a_button.WhileHeld( &run_transfer_forward );
  b_button.WhileHeld( &run_transfer_backwards );

}

// TODO: Implement functionality when autonomous modes are added
frc2::Command* RobotContainer::GetAutonomousCommand() {

  return nullptr;

}
