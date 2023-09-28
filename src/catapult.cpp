#include "vex.h"

void cataTune(){
   
}
void cataReset(){
  // if(catapult.position(deg) < 280){
  //   catapult.spin(directionType::fwd, 8, voltageUnits::volt);
  // }
  // else{
  //   catapult.stop(brakeType::hold);
  // }
  // catapult.spin(directionType::fwd, 12, voltageUnits::volt);
  // if(catapult.position(deg) > 360){
  //   catapult.stop(brakeType::hold);
  // }
  }
void cataFire(){
  if(master.ButtonL1.pressing()){
    catapult.spin(directionType::fwd, 8, voltageUnits::volt);
  }
  else if(master.ButtonL2.pressing()){
    catapult.spin(directionType::fwd, 12, voltageUnits::volt);
  }
  
  else{
    catapult.stop(brakeType::coast);
  }
  //     catapult.stop(brakeType::hold);


}


