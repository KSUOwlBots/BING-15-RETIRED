#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
//controller
controller master = controller(primary);

//drivetrain
//right motors
motor rightMotorA = motor(PORT1, ratio6_1, false);
motor rightMotorB = motor(PORT2, ratio6_1, false);
motor rightMotorC = motor(PORT3, ratio6_1, false);
motor_group rightDrive = motor_group(rightMotorA, rightMotorB, rightMotorC);
//left motors
motor leftMotorA = motor(PORT10, ratio6_1, true);
motor leftMotorB = motor(PORT9, ratio6_1, true);
motor leftMotorC = motor(PORT8, ratio6_1, true);
motor_group leftDrive = motor_group(leftMotorA, leftMotorB, leftMotorC);

//other motors
//catapult
motor leftCataMotor = motor(PORT6, ratio18_1, false);
motor rightCataMotor = motor(PORT7, ratio18_1, true);
motor_group catapult = motor_group(leftCataMotor, rightCataMotor);
//intake
motor intakeMotor = motor(PORT4, ratio18_1, false);

//sensors
//inertial
inertial imu = inertial(PORT5);
// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}