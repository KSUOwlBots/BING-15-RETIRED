#include "vex.h"

void cataTune(){
    bool cataTuned = false;
    double cataPos = 0;
    double initialPower = 0;
    double currentPower = 0;
    double finalPower = 0;
  while(catapult.position(deg) < 720 && !cataTuned){
    catapult.spin(directionType::fwd, 8, voltageUnits::volt);
    currentPower = catapult.power(watt);
    // master.Screen.clearScreen();
    // master.Screen.setCursor(1,1);
    // master.Screen.print(catapult.power(watt));
    // master.Screen.setCursor(2,1);
    // master.Screen.print(catapult.position(deg));
    
    if(currentPower > initialPower){
      initialPower = currentPower;
    }
    if(currentPower < initialPower){
      finalPower = currentPower;
    }
    if(finalPower < initialPower-1 && !cataTuned && catapult.position(deg) > 360){
    cataPos = catapult.position(deg);
      cataTuned = true;
    }
    if(cataTuned){
      catapult.stop(brakeType::hold);
    }
    

  }
  master.Screen.clearScreen();
    master.Screen.setCursor(1,1);
    master.Screen.print(finalPower);
    master.Screen.setCursor(2,1);
    master.Screen.print(cataPos);
  catapult.resetPosition();
  catapult.stop(brakeType::hold);
  while(catapult.position(deg) < cataPos+360){
    catapult.spin(directionType::fwd, 8, voltageUnits::volt);
  }
      catapult.stop(brakeType::hold);
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
    master.Screen.clearScreen();
    master.Screen.setCursor(1,1);
    master.Screen.print(catapult.power(watt));
    master.Screen.setCursor(2,1);
    master.Screen.print(catapult.position(deg));
  }
  else{
    catapult.stop(brakeType::hold);
  }
  //     catapult.stop(brakeType::hold);


}


