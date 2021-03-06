#pragma once

#include <frc/commands/Command.h>

class ArmCommand : public frc::Command {
 public:


  ArmCommand();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
