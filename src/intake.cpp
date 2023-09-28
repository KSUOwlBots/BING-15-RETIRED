#include "vex.h"

void intakeOpControl(){
  if(master.ButtonR1.pressing()){
      intakeMotor.spin(forward, 12, voltageUnits::volt);
    }
    //outtake
    else if(master.ButtonR2.pressing()){
      intakeMotor.spin(forward, -12, voltageUnits::volt);
    }
    else{
      intakeMotor.stop(brakeType::coast);
    }   
}


void intakeActuate(){
  if(master.ButtonUp.pressing()){
    intakeActuator.spin(directionType::fwd, 12, voltageUnits::volt);
  }
  else if(master.ButtonDown.pressing()){
    intakeActuator.spin(directionType::fwd, -12, voltageUnits::volt);
  }
  else{
    intakeActuator.stop(brakeType::hold);
  }

  //incase the code doesnt work
  // if(master.ButtonUp.pressing()){
  //   intakePiston1.set(1);
  //   intakePiston2.set(1);
  // }
  // if(master.ButtonDown.pressing()){
  //   intakePiston1.set(0);
  //   intakePiston2.set(0);
  // }

}