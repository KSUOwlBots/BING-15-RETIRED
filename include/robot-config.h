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
extern inertial imu;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );