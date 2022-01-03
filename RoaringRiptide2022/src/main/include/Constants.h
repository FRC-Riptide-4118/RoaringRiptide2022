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


#define CURVATURE_DRIVE_MODE 0
#define ARCADE_DRIVE_MODE 1

// DriveConstants namespace is a location for all constants realted to the Drive subsystem
namespace DriveConstants {

    // left motor controller IDs
    const int left_talon1_id = 0;
    const int left_talon2_id = 1;
    const int left_victor_id = 2;

    // right motor controller IDs
    const int right_talon1_id = 3;
    const int right_talon2_id = 4;
    const int right_victor_id = 5;

    // PCM shifter ports
    const int PCM_shifter_forward = 0;
    const int PCM_shifter_reverse = 1;

    const int drive_mode = CURVATURE_DRIVE_MODE;
}

// ControllerConstants is a location for all constants related to the XboxController
namespace ControllerConstants {

    // the primary Xbox controller is connected on port 0
    const int driver_controller_port = 0;

}

namespace DriveToDistanceConstants {

    const double kP = 0.0;
    const double kI = 0.0;
    const double kD = 0.0;
}