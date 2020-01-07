#include <frc/smartdashboard/SmartDashboard.h>
#include "commands/ElevatorManualControl.h"
#include "Modules/Mode.h"
#include "Robot.h"

ElevatorManualControl::ElevatorManualControl() {
  // Use Requires() here to declare subsystem dependencies
  Requires(Robot::elevator);
}


void ElevatorManualControl::Initialize() {

  SmartDashboard::PutString("Elevator Mode","Manual");
}

void ElevatorManualControl::Execute() {
  if(!Mode::IsEndGame()){
    if(Robot::oi->GetRightTrigger() > 0){
      Robot::elevator->ElevatorUp(Robot::oi->GetRightTrigger());
    }else if (Robot::oi->GetLeftTrigger() > 0){
      Robot::elevator->ElevatorDown(Robot::oi->GetLeftTrigger());
    }else if (Robot::elevatorMotor->GetEncoderPosition() < -15){
      Robot::elevator->ElevatorHold();
    }else{
      Robot::elevator->ElevatorStop();
    }
  }else{
    Robot::elevator->ElevatorStop();
  }
}

bool ElevatorManualControl::IsFinished() { return false; }

void ElevatorManualControl::End() {
  Robot::elevator->ElevatorStop();
  SmartDashboard::PutString("Elevator Mode","Unknown");
}

void ElevatorManualControl::Interrupted() {
  End();
}