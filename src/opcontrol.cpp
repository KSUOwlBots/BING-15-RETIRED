#include "vex.h"


// Reset drive sensors(do this before the while loop in usercontrol)
void reset_drive_sensors(){
  leftDrive.resetPosition();
  rightDrive.resetPosition();
}


// Curve function for left joystick
double left_curve_function(double x) {
  double left_curve_scale = 3;
  if (left_curve_scale != 0) {
    return (powf(2.718, -(left_curve_scale / 10)) + powf(2.718, (fabs(x) - 127) / 10) * (1 - powf(2.718, -(left_curve_scale / 10)))) * x;
  }
  return x;
}
// Curve function for right joystick
double right_curve_function(double x) {
  double right_curve_scale = 3;
  if (right_curve_scale != 0) {
    return (powf(2.718, -(right_curve_scale / 10)) + powf(2.718, (fabs(x) - 127) / 10) * (1 - powf(2.718, -(right_curve_scale / 10)))) * x;
  }
  return x;
}
// Set robot to l_stick and r_stick, check joystick threshold, set active brake
void joy_thresh_opcontrol(double l_stick, double r_stick) {
  double JOYSTICK_THRESHOLD = 5;
  double active_brake_kp = .05;
  // Threshold if joysticks don't come back to perfect 0
  if (abs(l_stick) > JOYSTICK_THRESHOLD || abs(r_stick) > JOYSTICK_THRESHOLD) {
    leftDrive.spin(directionType::fwd, l_stick*.12, voltageUnits::volt);
    rightDrive.spin(directionType::fwd, r_stick*.12, voltageUnits::volt);
    if (active_brake_kp != 0) reset_drive_sensors();
  }
  // When joys are released, run active brake (P) on drive
  else {
    leftDrive.spin(directionType::fwd, (0 - leftDrive.position(degrees)) * active_brake_kp*.12, voltageUnits::volt);
    rightDrive.spin(directionType::fwd, (0 - rightDrive.position(degrees)) * active_brake_kp*.12, voltageUnits::volt);
  }
}
//usercontrol task
void arcadeDrive() {
  double fwd_stick, turn_stick;
  // Put the joysticks through the curve function
  fwd_stick = left_curve_function(master.Axis2.position());
  turn_stick = right_curve_function(master.Axis1.position());
  

  // Set robot to l_stick and r_stick, check joystick threshold, set active brake
  joy_thresh_opcontrol(fwd_stick + turn_stick, fwd_stick - turn_stick);
}
