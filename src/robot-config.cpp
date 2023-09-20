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
motor rightMotorA = motor(PORT1, ratio6_1, false);//1
motor rightMotorB = motor(PORT2, ratio6_1, false);//changed cuz bong //2
motor rightMotorC = motor(PORT3, ratio6_1, false);//3
motor_group rightDrive = motor_group(rightMotorA, rightMotorB, rightMotorC);
//left motors
motor leftMotorA = motor(PORT10, ratio6_1, true);//10
motor leftMotorB = motor(PORT9, ratio6_1, true);//changed cuz bong//9
motor leftMotorC = motor(PORT8, ratio6_1, true);//8
motor_group leftDrive = motor_group(leftMotorA, leftMotorB, leftMotorC);


//other motors
//catapult
motor rightCataMotor = motor(PORT7, ratio36_1, false);
motor leftCataMotor = motor(PORT4, ratio36_1, true);
motor_group catapult = motor_group(leftCataMotor, rightCataMotor);


//intake
motor intakeMotor = motor(PORT19, ratio18_1, false);

digital_out intakePiston1 = digital_out(Brain.ThreeWirePort.A);
digital_out intakePiston2 = digital_out(Brain.ThreeWirePort.B);


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