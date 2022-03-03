// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Launcher.h"

Launcher::Launcher() {

    this->launcher_motor.SetInverted(true);
    this->launcher_motor.ConfigSupplyCurrentLimit(SupplyCurrentLimitConfiguration(true, 40, 35, 1.0));
    this->launcher_motor.ConfigSelectedFeedbackSensor(TalonFXFeedbackDevice::IntegratedSensor);

    this->launcher_motor.Config_kF(0, LauncherConstants::launcher_PID_coefficients.kF);
    this->launcher_motor.Config_kP(0, LauncherConstants::launcher_PID_coefficients.kP);
    this->launcher_motor.Config_kI(0, LauncherConstants::launcher_PID_coefficients.kI);
    this->launcher_motor.Config_kD(0, LauncherConstants::launcher_PID_coefficients.kD);

}

// This method will be called once per scheduler run
void Launcher::Periodic() {}

void Launcher::RunToSpeed(void) {

    this->launcher_motor.Set(ControlMode::Velocity, LauncherConstants::setpoint);

}

bool Launcher::AtSpeed(void) {

    return this->launcher_motor.GetSelectedSensorVelocity() >= 0.9*LauncherConstants::setpoint;

}

void Launcher::Stop(void) {

    this->launcher_motor.Set(ControlMode::PercentOutput, 0);

}