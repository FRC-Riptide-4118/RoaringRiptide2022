// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

// include RobotContainer
#include "RobotContainer.h"

RobotContainer::RobotContainer() {

  // Set up the Drive subsystem to have a default command that allows it to be driven via Xbox controller
  // Required the use of lambda functions to set up
  m_drive.SetDefaultCommand( DefaultDrive{ &m_drive, [this] {return driver_controller.GetY(frc::GenericHID::JoystickHand::kLeftHand); }, [this] {return driver_controller.GetX(frc::GenericHID::JoystickHand::kRightHand); } } );

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {}

// TODO: Implement functionality when autonomous modes are added
frc2::Command* RobotContainer::GetAutonomousCommand() {

  return nullptr;

}
