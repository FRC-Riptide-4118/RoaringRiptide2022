// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

// include RobotContainer
#include "RobotContainer.h"

RobotContainer::RobotContainer() {

  // Configure the button bindings
  ConfigureButtonBindings();

  frc::Shuffleboard::GetTab("Game").Add(this->m_auto_chooser);
  this->m_auto_chooser.SetDefaultOption("Nothing", &nothing_auto);
  this->m_auto_chooser.AddOption("Drive To Distance", &drive_to_distance_auto);
  this->m_auto_chooser.AddOption("Turn To Angle", &turn_to_angle_gyro);
  this->m_auto_chooser.AddOption("Complex 1", &complex_auto1);

  // frc::Shuffleboard::GetTab("Game").AddNumber("Filtered Velocity", [this] { return m_drive.GetVelocity(); } );
  // frc::Shuffleboard::GetTab("Game").AddNumber("Unfiltered Velocity", [this] { return m_drive.GetUnfilteredVelocity(); } );
  frc::Shuffleboard::GetTab("Game").AddNumber("Angle", [this] { return m_drive.GetAngle(); } );
  frc::Shuffleboard::GetTab("Game").AddNumber("Limit Switch", [this] { return m_climber.GetLimitSwitches(); } );

  // Set up the Drive subsystem to have a default command that allows it to be driven via Xbox controller
  // Required the use of lambda functions to set up
  m_drive.SetDefaultCommand( DefaultDrive{ &m_drive, [this] {return driver_controller.GetLeftY(); }, [this] {return -driver_controller.GetRightX(); } } );
  m_transfer.SetDefaultCommand( DefaultTransfer(&m_transfer) );
  m_intake.SetDefaultCommand( DefaultIntake(&m_intake) );
  m_limelight.SetDefaultCommand( DefaultLimelight(&m_limelight) );
  m_launcher.SetDefaultCommand( DefaultLauncher(&m_launcher) );
  m_climber.SetDefaultCommand( DefaultClimber(&m_climber) );  
  
}

void RobotContainer::ConfigureButtonBindings() {

  a_button.WhileHeld( &run_transfer_forward );
  b_button.WhileHeld( &run_intake_forward );
  x_button.WhileHeld( &raise_intake );
  right_bumper.ToggleWhenPressed( &run_launcher );
  left_bumper.WhenPressed( &toggle_intake );
  up_button.WhileHeld( &raise_climber );
  down_button.WhileHeld( &lower_climber );

}

// TODO: Implement functionality when autonomous modes are added
frc2::Command* RobotContainer::GetAutonomousCommand() {

  return this->m_auto_chooser.GetSelected();

}