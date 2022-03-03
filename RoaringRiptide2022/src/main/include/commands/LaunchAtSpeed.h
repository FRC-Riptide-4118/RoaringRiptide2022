// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <subsystems/Transfer.h>
#include <subsystems/Launcher.h>

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class LaunchAtSpeed
    : public frc2::CommandHelper<frc2::CommandBase, LaunchAtSpeed> {
 public:
  LaunchAtSpeed(Transfer* m_transfer, Launcher* m_launcher);

  void Execute() override;

 private:
  Transfer* m_transfer;
  Launcher* m_launcher;

};
