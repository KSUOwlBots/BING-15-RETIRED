using namespace vex;

extern brain Brain;

// VEXcode devices

extern controller master;
extern motor rightMotorA;
extern motor rightMotorB;
extern motor rightMotorC;
extern motor_group rightDrive;
extern motor leftMotorA;
extern motor leftMotorB;
extern motor leftMotorC;
extern motor_group leftDrive;
extern motor leftCataMotor;
extern motor rightCataMotor;
extern motor_group catapult;
extern motor intakeMotor;
extern motor intakeActuate1;
extern motor intakeActuate2;
extern motor_group intakeActuator;
extern inertial imu;
extern digital_out intakePiston1;
extern digital_out intakePiston2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );