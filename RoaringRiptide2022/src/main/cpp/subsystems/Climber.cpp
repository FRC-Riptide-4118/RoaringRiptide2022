// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Climber.h"

Climber::Climber() {

    this->climber_right_motor.SetInverted(true);

    this->left_servo.Set(0);
    this->right_servo.Set(0);

    this->topLeft_latch = 0;
    this->topRight_latch = 0;
    this->bottomLeft_latch = 0;
    this->bottomRight_latch = 0;

}

// This method will be called once per scheduler run
void Climber::Periodic() {}

void Climber::Stop(void) {

    this->climber_left_motor.Set(ControlMode::PercentOutput, 0);
    this->climber_right_motor.Set(ControlMode::PercentOutput, 0);

}

void Climber::LowerClimber(void) {

    int limit_switches = this->GetLimitSwitches();

    this->left_servo.Set(ClimberConstants::servo_down_value);
    this->right_servo.Set(ClimberConstants::servo_down_value);

    this->topLeft_latch = 0;
    this->topRight_latch = 0;

    if (limit_switches & 0b0010) {

        this->bottomLeft_latch = 1;

    }

    if (limit_switches & 0b1000) {

        this->bottomRight_latch = 1;

    }

    if (!this->bottomLeft_latch) {

        this->climber_left_motor.Set(ControlMode::PercentOutput, -ClimberConstants::climber_down_speed);
        

    }
    else {

       this->climber_left_motor.Set(ControlMode::PercentOutput, 0);

    }

    if (!this->bottomRight_latch) {

        this->climber_right_motor.Set(ControlMode::PercentOutput, -ClimberConstants::climber_down_speed);

    }
    else {

        this->climber_right_motor.Set(ControlMode::PercentOutput, 0);

    }

}

void Climber::RaiseClimber(void) {

    int limit_switches = this->GetLimitSwitches();

    this->left_servo.Set(ClimberConstants::servo_up_value);
    this->right_servo.Set(ClimberConstants::servo_up_value);
    
    this->bottomRight_latch = 0;
    this->bottomLeft_latch = 0;

    if (limit_switches & 0b0001) {

        this->topLeft_latch = 1;

    }

    if (limit_switches & 0b0100) {

        this->topRight_latch = 1;

    }

    if (!this->topLeft_latch) {

        this->climber_left_motor.Set(ControlMode::PercentOutput, ClimberConstants::climber_up_speed);

    }
    else {

        this->climber_left_motor.Set(ControlMode::PercentOutput, 0);

    }

    if (!this->topRight_latch) {

        this->climber_right_motor.Set(ControlMode::PercentOutput, ClimberConstants::climber_up_speed);

    }
    else {

        this->climber_right_motor.Set(ControlMode::PercentOutput, 0);

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