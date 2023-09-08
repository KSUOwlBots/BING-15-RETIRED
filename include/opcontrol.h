#pragma once

#include <functional>
#include <iostream>
#include <tuple>

void reset_drive_sensors();
  
double left_curve_function(double x);
double right_curve_function(double x);
void joy_thresh_opcontrol(double l_stick, double r_stick);

void drive_arcade_standard();