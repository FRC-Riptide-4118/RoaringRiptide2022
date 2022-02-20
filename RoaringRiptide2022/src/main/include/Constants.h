// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

// header include guard
#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */
#include <units/length.h>
#include "user_defined/PID_Coefficients.h"

#define CURVATURE_DRIVE_MODE 0
#define ARCADE_DRIVE_MODE 1

#define ROBORIO_LOOP_PERIOD 0.02_s // corresponds to a frequency of 50Hz

// DriveConstants namespace is a location for all constants realted to the Drive subsystem
namespace DriveConstants {

    // left motor controller IDs
    const int left_talon_id = 1;
    const int left_victor1_id = 2;
    const int left_victor2_id = 3;

    // right motor controller IDs
    const int right_talon_id = 0;
    const int right_victor1_id = 4;
    const int right_victor2_id = 5;

    // drive PID coefficients
    const PID_Coefficients drive_PID_coefficients(0, 0.03, 0, 0);

    // control drive mode (either curvature or arcade)
    const int drive_mode = ARCADE_DRIVE_MODE;

    const double encoder_filter_cutoff_frequency = 0.1;

    const auto track_width = 30_in;
}

// IntakeConstants is a location for all constants related to the Intake
namespace IntakeConstants {

    const int motor_controller_id = 6;
    const int PCM_intake_arm_forward = 0;
    const int PCM_intake_arm_reverse = 0;

}

// TransferConstants is a location for all constants related to the Transfer
namespace TransferConstants {

    const int motor_controller_id = 7;

    const double transfer_speed = 0.25;

}

namespace LauncherConstants {

    const int motor_controller_id = 8;
    const PID_Coefficients launcher_PID_coefficients(0, 0.03, 0, 0);

    const double setpoint = 10000;

}

namespace ClimberConstants {

    const int left_climber_motor_id = 0;
    const int right_climber_motor_id = 1;

    const int top_left_limit_switch_port = 0;
    const int bottom_left_limit_switch_port = 1;
    const int top_right_limit_switch_port = 2;
    const int bottom_right_limit_switch_port = 3;

    const int left_servo_port = 0;
    const int right_servo_port = 1;

    const double servo_hold_value = 0.5;

    const double climber_speed = 0.5;

}

// ControllerConstants is a location for all constants related to the XboxController
namespace ControllerConstants {

    // the primary Xbox controller is connected on port 0
    const int driver_controller_port = 0;

}