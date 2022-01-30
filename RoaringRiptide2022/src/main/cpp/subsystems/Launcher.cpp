// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Launcher.h"

Launcher::Launcher() {

    this->launcher_motor.SetInverted(true);
    this->launcher_motor.ConfigSupplyCurrentLimit( SupplyCurrentLimitConfiguration(true, 40, 35, 1.0));
    this->launcher_motor.ConfigClosedloopRamp(5);
    this->launcher_motor.ConfigSelectedFeedbackSensor(TalonFXFeedbackDevice::IntegratedSensor);

    this->launcher_motor.Config_kF(LauncherConstants::motor_controller_id, LauncherConstants::launcher_PID_coefficients.kF);
    this->launcher_motor.Config_kP(LauncherConstants::motor_controller_id, LauncherConstants::launcher_PID_coefficients.kP);
    this->launcher_motor.Config_kI(LauncherConstants::motor_controller_id, LauncherConstants::launcher_PID_coefficients.kI);
    this->launcher_motor.Config_kD(LauncherConstants::motor_controller_id, LauncherConstants::launcher_PID_coefficients.kD);

}

// This method will be called once per scheduler run
void Launcher::Periodic() {}

void Launcher::RunToSpeed(double setpoint) {

    this->launcher_motor.Set(ControlMode::Velocity, setpoint);

}

void Launcher::Stop(void) {

    this->launcher_motor.Set(ControlMode::PercentOutput, 0);

}