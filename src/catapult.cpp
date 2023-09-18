#include "vex.h"

void cataTune(){
    bool cataTuned = false;
  while(catapult.position(deg) < 720 && cataTuned == false){
    catapult.spin(directionType::fwd, 8, voltageUnits::volt);
    if(catapult.power(watt) < .45 && catapult.position(deg) > 360){
      catapult.resetPosition();
      cataTuned = true;
    }

  }  
  catapult.stop(brakeType::hold);
  catapult.spin(directionType::fwd, 8, voltageUnits::volt);
  if(catapult.position(deg) > 360){
    catapult.stop(brakeType::hold);
  }
}
void cataReset(){
  if(catapult.position(deg) < 280){
    catapult.spin(directionType::fwd, 8, voltageUnits::volt);
  }
  else{
    catapult.stop(brakeType::hold);
  }
  // catapult.spin(directionType::fwd, 12, voltageUnits::volt);
  // if(catapult.position(deg) > 360){
  //   catapult.stop(brakeType::hold);
  // }
  }
void cataFire(){
  if(master.ButtonL1.pressing()){
    catapult.spin(directionType::fwd, 12, voltageUnits::volt);
  }
  else{
    catapult.stop(brakeType::hold);
  }

}


void intakeRun(){
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