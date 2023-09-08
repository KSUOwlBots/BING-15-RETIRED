#include "vex.h"



void reset_drive_sensors(){
  leftDrive.resetPosition();
  rightDrive.resetPosition();
}



double left_curve_function(double x) {
  double left_curve_scale = 3;
  if (left_curve_scale != 0) {
    return (powf(2.718, -(left_curve_scale / 10)) + powf(2.718, (fabs(x) - 127) / 10) * (1 - powf(2.718, -(left_curve_scale / 10)))) * x;
  }
  return x;
}

double right_curve_function(double x) {
  double right_curve_scale = 3;
  if (right_curve_scale != 0) {
    return (powf(2.718, -(right_curve_scale / 10)) + powf(2.718, (fabs(x) - 127) / 10) * (1 - powf(2.718, -(right_curve_scale / 10)))) * x;
  }
  return x;
}

void set_active_brake(double kp) {
  active_brake_kp = kp;
}

//need reset drive encoders code
void reset_drive_sensors(){
  leftDrive.resetPosition();
  rightDrive.resetPosition();
}


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
    leftDrive.spin(directionType::fwd, (0 - leftDrive.position()) * active_brake_kp*.12, voltageUnits::volt);
    rightDrive.spin(directionType::fwd, (0 - rightDrive.position()) * active_brake_kp*.12, voltageUnits::volt);
  }
}

void drive_arcade_standard() {
  double fwd_stick, turn_stick;
  // Put the joysticks through the curve function
  fwd_stick = left_curve_function(master.Axis2.position());
  turn_stick = right_curve_function(master.Axis1.position());
  

  // Set robot to l_stick and r_stick, check joystick threshold, set active brake
  joy_thresh_opcontrol(fwd_stick + turn_stick, fwd_stick - turn_stick);
}
/*

// Set active brake constant
void Drive::set_active_brake(double kp) { active_brake_kp = kp; }

// Set joystick threshold
void Drive::set_joystick_threshold(int threshold) { JOYSTICK_THRESHOLD = abs(threshold); }

void Drive::reset_drive_sensors_opcontrol() {
  if (util::AUTON_RAN) {
    reset_drive_sensor();
    util::AUTON_RAN = false;
  }
}

void Drive::joy_thresh_opcontrol(int l_stick, int r_stick) {
  // Threshold if joysticks don't come back to perfect 0
  if (abs(l_stick) > JOYSTICK_THRESHOLD || abs(r_stick) > JOYSTICK_THRESHOLD) {
    set_tank(l_stick, r_stick);
    if (active_brake_kp != 0) reset_drive_sensor();
  }
  // When joys are released, run active brake (P) on drive
  else {
    set_tank((0 - left_sensor()) * active_brake_kp, (0 - right_sensor()) * active_brake_kp);
  }
}

// Tank control
void Drive::tank() {
  is_tank = true;
  reset_drive_sensors_opcontrol();

  // Toggle for controller curve
  modify_curve_with_controller();

  // Put the joysticks through the curve function
  int l_stick = left_curve_function(master.get_analog(ANALOG_LEFT_Y));
  int r_stick = left_curve_function(master.get_analog(ANALOG_RIGHT_Y));

  // Set robot to l_stick and r_stick, check joystick threshold, set active brake
  joy_thresh_opcontrol(l_stick, r_stick);
}

// Arcade standard
void Drive::arcade_standard(e_type stick_type) {
  is_tank = false;
  reset_drive_sensors_opcontrol();

  // Toggle for controller curve
  modify_curve_with_controller();

  int fwd_stick, turn_stick;
  // Check arcade type (split vs single, normal vs flipped)
  if (stick_type == SPLIT) {
    // Put the joysticks through the curve function
    fwd_stick = left_curve_function(master.get_analog(ANALOG_LEFT_Y));
    turn_stick = right_curve_function(master.get_analog(ANALOG_RIGHT_X));
  } else if (stick_type == SINGLE) {
    // Put the joysticks through the curve function
    fwd_stick = left_curve_function(master.get_analog(ANALOG_LEFT_Y));
    turn_stick = right_curve_function(master.get_analog(ANALOG_LEFT_X));
  }

  // Set robot to l_stick and r_stick, check joystick threshold, set active brake
  joy_thresh_opcontrol(fwd_stick + turn_stick, fwd_stick - turn_stick);
}

// Arcade control flipped
  void Drive::arcade_flipped(e_type stick_type) {
    is_tank = false;
    reset_drive_sensors_opcontrol();

    // Toggle for controller curve
    modify_curve_with_controller();

    int turn_stick, fwd_stick;
    // Check arcade type (split vs single, normal vs flipped)
    if (stick_type == SPLIT) {
      // Put the joysticks through the curve function
      fwd_stick = right_curve_function(master.get_analog(ANALOG_RIGHT_Y));
      turn_stick = left_curve_function(master.get_analog(ANALOG_LEFT_X));
    } else if (stick_type == SINGLE) {
      // Put the joysticks through the curve function
      fwd_stick = right_curve_function(master.get_analog(ANALOG_RIGHT_Y));
      turn_stick = left_curve_function(master.get_analog(ANALOG_RIGHT_X));
    }

    // Set robot to l_stick and r_stick, check joystick threshold, set active brake
    joy_thresh_opcontrol(fwd_stick + turn_stick, fwd_stick - turn_stick);
  }
*/