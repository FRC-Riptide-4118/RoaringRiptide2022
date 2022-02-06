// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Climber.h"

Climber::Climber() {

    this->left_servo.Set(0);
    this->right_servo.Set(0);

}

// This method will be called once per scheduler run
void Climber::Periodic() {}

void Climber::LowerClimber(void) {

    this->left_servo.Set(0);
    this->right_servo.Set(0);

    if (this->bottom_left_limit_switch.Get()) {

        this->climber_left_motor.Set(ControlMode::PercentOutput, 0);

    }
    else {

        this->climber_left_motor.Set(ControlMode::PercentOutput, -ClimberConstants::climber_speed);

    }

    if (this->bottom_right_limit_switch.Get()) {

        this->climber_right_motor.Set(ControlMode::PercentOutput, 0);

    }
    else {

        this->climber_right_motor.Set(ControlMode::PercentOutput, -ClimberConstants::climber_speed);

    }

}

void Climber::RaiseClimber(void) {

    this->left_servo.Set(ClimberConstants::servo_hold_value);
    this->right_servo.Set(ClimberConstants::servo_hold_value);

    if (this->top_left_limit_switch.Get()) {

        this->climber_left_motor.Set(ControlMode::PercentOutput, 0);

    }
    else {

        this->climber_left_motor.Set(ControlMode::PercentOutput, ClimberConstants::climber_speed);

    }

    if (this->top_right_limit_switch.Get()) {

        this->climber_right_motor.Set(ControlMode::PercentOutput, 0);

    }
    else {

        this->climber_right_motor.Set(ControlMode::PercentOutput, ClimberConstants::climber_speed);

    }

}