// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

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
namespace DriveConstants {

    const int left_talon1 = 0;
    const int left_talon2 = 1;
    const int left_victor = 2;

    const int right_talon1 = 3;
    const int right_talon2 = 4;
    const int right_victor = 5;

    const int PCM_port0_forward = 0;
    const int PCM_port0_reverse = 1;
}
namespace ControllerConstants {

    const int driver_controller_port = 0;
}