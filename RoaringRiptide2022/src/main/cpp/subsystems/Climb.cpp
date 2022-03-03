// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Climber.h"

Climber::Climber() {

    this->climber_right_motor.SetInverted(true);

    this->left_servo.Set(0);
    this->right_servo.Set(0);

}

// This method will be called once per scheduler run
void Climber::Periodic() {}

void Climber::Stop(void) {

    this->climber_left_motor.Set(ControlMode::PercentOutput, 0);
    this->climber_right_motor.Set(ControlMode::PercentOutput, 0);

}

void Climber::LowerClimber(void) {

    int limit_switches = this->GetLimitSwitches();

    this->left_servo.Set(0.5);
    this->right_servo.Set(0.5);

    if (limit_switches & 0b0010) {

        this->climber_left_motor.Set(ControlMode::PercentOutput, 0);

    }
    else {

        this->climber_left_motor.Set(ControlMode::PercentOutput, -ClimberConstants::climber_speed);

    }

    if (limit_switches & 0b1000) {

        this->climber_right_motor.Set(ControlMode::PercentOutput, 0);

    }
    else {

        this->climber_right_motor.Set(ControlMode::PercentOutput, -ClimberConstants::climber_speed);

    }

}

void Climber::RaiseClimber(void) {

    int limit_switches = this->GetLimitSwitches();

    this->left_servo.Set(0);
    this->right_servo.Set(0);

    if (limit_switches & 0b0001) {

        this->climber_left_motor.Set(ControlMode::PercentOutput, 0);

    }
    else {

        this->climber_left_motor.Set(ControlMode::PercentOutput, ClimberConstants::climber_speed);

    }

    if (limit_switches & 0b0100) {

        this->climber_right_motor.Set(ControlMode::PercentOutput, 0);

    }
    else {

        this->climber_right_motor.Set(ControlMode::PercentOutput, ClimberConstants::climber_speed);

    }

}

int Climber::GetLimitSwitches(void) {

    int values = 0;

    values |= ((int)this->top_left_limit_switch.Get() << 0 );
    values |= ((int)this->bottom_left_limit_switch.Get() << 1 );
    values |= ((int)this->top_right_limit_switch.Get() << 2 );
    values |= ((int)this->bottom_right_limit_switch.Get() << 3 );

    return values ^ 0xF;

}