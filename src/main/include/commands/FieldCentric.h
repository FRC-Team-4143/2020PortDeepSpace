#pragma once

#include <frc/commands/Command.h>

class FieldCentric : public frc::Command {
 public:


  FieldCentric();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
