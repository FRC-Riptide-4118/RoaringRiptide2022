// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/PIDCommand.h>

#include <subsystems/Drive.h>
#include <subsystems/Limelight.h>

class TurnToAngleLimelight
    : public frc2::CommandHelper<frc2::PIDCommand, TurnToAngleLimelight> {
 public:
  TurnToAngleLimelight(Drive* m_drive, Limelight* m_limelight);

  bool IsFinished() override;

};
