// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"


RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  m_drive.SetDefaultCommand( DefaultDrive{ &m_drive, [this] {return driver_controller.GetY(frc::GenericHID::JoystickHand::kLeftHand); }, [this] {return driver_controller.GetX(frc::GenericHID::JoystickHand::kRightHand); } } );

}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
}
