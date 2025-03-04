#include "autons.hpp"
#include "EZ-Template/util.hpp"
#include "main.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "subsystems.hpp"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

// These are out of 127
const int DRIVE_SPEED = 110;
const int TURN_SPEED = 90;
const int SWING_SPEED = 110;

///
// Constants
///
void default_constants() {
  // P, I, D, and Start I
  chassis.pid_drive_constants_set(6, 0 , 0);   //310      // Fwd/rev constants, used for odom and non odom motions
  chassis.pid_heading_constants_set(16.0, 0.0, 25.0);        // Holds the robot straight while going forward without odom
  chassis.pid_turn_constants_set(5.2, 0.14, 38, 12.0);     // Turn in place constants
  chassis.pid_swing_constants_set(6.0, 0.0, 65.0);           // Swing constants
  chassis.pid_odom_angular_constants_set(10, 0.07, 60 );    // Angular control for odom motions
  chassis.pid_odom_boomerang_constants_set(6, 0.0, 28);  // Angular control for boomerang motions

  // Exit conditions
  chassis.pid_turn_exit_condition_set(90, 3, 250, 7, 500, 500);
  chassis.pid_swing_exit_condition_set(90, 3, 250, 7, 500, 500);
  chassis.pid_drive_exit_condition_set(90, 1, 250, 3, 500, 500);
  chassis.pid_odom_turn_exit_condition_set(90, 3, 250, 7, 500, 750);
  chassis.pid_odom_drive_exit_condition_set(90, 1, 250, 3, 500, 750);
  chassis.pid_turn_chain_constant_set(3_deg);
  chassis.pid_swing_chain_constant_set(5_deg);
  chassis.pid_drive_chain_constant_set(3_in);

  // Slew constants
  chassis.slew_turn_constants_set(3_deg, 70);
  chassis.slew_drive_constants_set(3_in, 70);
  chassis.slew_swing_constants_set(3_in, 80);

  // The amount that turns are prioritized over driving in odom motions
  // - if you have tracking wheels, you can run this higher.  1.0 is the max
  chassis.odom_turn_bias_set(0.9);

  chassis.odom_look_ahead_set(7_in);           // This is how far ahead in the path the robot looks at
  chassis.odom_boomerang_distance_set(16_in);  // This sets the maximum distance away from target that the carrot point can be
  chassis.odom_boomerang_dlead_set(0.625);     // This handles how aggressive the end of boomerang motions are

  chassis.pid_angle_behavior_set(ez::shortest);  // Changes the default behavior for turning, this defaults it to the shortest path there
}

///
// Drive Example
///
void test(){
setIntake(127);
  chassis.pid_odom_set(48,110);
  chassis.pid_wait();
}
void redpm(){
// alliance, 3 ring, ladder
}
void bluepm(){
//alliance, 3 ring, ladder
}
void bluenm(){
// alliance plus 5 ring, ladder
}
void rednm(){
// alliance plus 5 ring, ladder
}



void ringrb(){
// rush stack, 6 ring and corner, no alliance
}
void ringrr(){
// rush stack, 6 ring and corner, no alliance

}
void goalrb(){
// 2 on 2, one near corner, one in clamp

}
void goalrr(){
// 2 on 2, one near corner, one in clamp

}
void sawpb(){

}
void sawpr(){

}
void skills(){
//alliance stake 
  chassis.odom_xyt_set(0,-64,0);
  liftPID.target_set(0);
  clamps.set(true);
  pros::delay(300);
  setIntake(-127);
  pros::delay(700);
//clamp 1
  chassis.pid_odom_set({{0, -52},fwd, 70});
  chassis.pid_wait();
  chassis.pid_turn_set(-89, 100);
  chassis.pid_wait();
  chassis.pid_odom_set({{24,-52},rev, 50});
  chassis.pid_wait();
  pros::delay(400);
  clamps.set(false);
  pros::delay(300);
  chassis.pid_odom_set({{19,-27}, fwd, 70});
  chassis.pid_wait();
  chassis.pid_odom_set({{50, -2}, fwd, 66});
  chassis.pid_wait();
  pros::delay(600);
  chassis.pid_odom_set({{48, 28}, fwd, 58});
  chassis.pid_wait();
  chassis.pid_odom_set({{48,-2}, rev, 60});
  chassis.pid_wait();
  chassis.pid_turn_set(175, 85);
  chassis.pid_wait();
  pros::delay(400);
  chassis.pid_odom_set({{48, -50}, fwd, 43});
  chassis.pid_wait();
  pros::delay(500);
  chassis.pid_odom_set({{48, -60}, fwd, 35});
  chassis.pid_wait();
  pros::delay(400);
  chassis.pid_odom_set({{42, -52}, rev, 60});
  chassis.pid_wait();
  chassis.pid_turn_set(-30, 110);
  chassis.pid_wait();
  chassis.pid_odom_set({{59,-61}, rev, 60});
  chassis.pid_wait();
  clamps.set(true);
  setIntake(100);
  pros::delay(300);

// END OF FIRST CORNER 
// clamp 2 
  setIntake(0); 
  chassis.pid_odom_set({{3, -51.6},fwd, 70});
  chassis.pid_wait();
  chassis.pid_turn_set(89, 110);
  chassis.pid_wait();
  chassis.pid_odom_set({{-21,-51.6},rev, 50});
  chassis.pid_wait();
  pros::delay(400);
  clamps.set(false);
  pros::delay(300);
  setIntake(-127); 
  chassis.pid_odom_set({{-20,-27}, fwd, 70});
  chassis.pid_wait();
  chassis.pid_odom_set({{-46, -2}, fwd, 70});
  chassis.pid_wait();
  chassis.pid_odom_set({{-44, 28}, fwd, 70});
  chassis.pid_wait();
  chassis.pid_odom_set({{-44,-2}, rev, 60});
  chassis.pid_wait();
  chassis.pid_turn_set(177, 85);
  chassis.pid_wait();
  pros::delay(400);
  chassis.pid_odom_set({{-44, -50}, fwd, 45});
  chassis.pid_wait();
  pros::delay(400);
  chassis.pid_odom_set({{-44, -60}, fwd, 40});
  chassis.pid_wait();
  pros::delay(400);
  chassis.pid_odom_set({{-38, -48}, rev, 60});
  chassis.pid_wait();
  chassis.pid_turn_set(30, 110);
  chassis.pid_wait();
  chassis.pid_odom_set({{-50, -61}, rev, 60});
  chassis.pid_wait();
  clamps.set(true);
  setIntake(100);
  pros::delay(300);
  setIntake(0);
// END OF CORNER 2 
  chassis.pid_odom_set({{-48, 2}, fwd, 90});
  chassis.pid_wait();
  chassis.pid_odom_set({{-11, 58}, fwd, 110});
  chassis.pid_wait();
  chassis.pid_odom_set({{-58, 58}, fwd, 90});
  chassis.pid_wait();
// END OF CORNER 3 
  chassis.pid_odom_set({{-17, 47}, rev, 70});
  chassis.pid_wait();
  chassis.pid_odom_set({{0, 49}, rev, 70});
  chassis.pid_wait();
  pros::delay(425);
  clamps.set(false);
  pros::delay(300);
  chassis.pid_wait();
  chassis.pid_drive_set(-29, 110, false);
  chassis.pid_wait();
  chassis.pid_odom_set({{60,60}, rev, 110});
// END 

}


///
// Motion Chaining
///
void motion_chaining() {
  // Motion chaining is where motions all try to blend together instead of individual movements.
  // This works by exiting while the robot is still moving a little bit.
  // To use this, replace pid_wait with pid_wait_quick_chain.
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(-45_deg, TURN_SPEED);
  chassis.pid_wait_quick_chain();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  // Your final motion should still be a normal pid_wait
  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}

///
// Auto that tests everything
///
void combining_movements() {
  chassis.pid_drive_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_turn_set(45_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_swing_set(ez::RIGHT_SWING, -45_deg, SWING_SPEED, 45);
  chassis.pid_wait();

  chassis.pid_turn_set(0_deg, TURN_SPEED);
  chassis.pid_wait();

  chassis.pid_drive_set(-24_in, DRIVE_SPEED, true);
  chassis.pid_wait();
}


///
// Odom Drive PID
///
void odom_drive_example() {
  // This works the same as pid_drive_set, but it uses odom instead!
  // You can replace pid_drive_set with pid_odom_set and your robot will
  // have better error correction.

  chassis.pid_odom_set(24_in, DRIVE_SPEED, true);
  chassis.pid_wait();

  chassis.pid_odom_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();

  chassis.pid_odom_set(-12_in, DRIVE_SPEED);
  chassis.pid_wait();
}

///
// Odom Pure Pursuit
///
void odom_pure_pursuit_example() {
  // Drive to 0, 30 and pass through 6, 10 and 0, 20 on the way, with slew
  chassis.pid_odom_set({{{6_in, 10_in}, fwd, DRIVE_SPEED},
                        {{0_in, 20_in}, fwd, DRIVE_SPEED},
                        {{0_in, 30_in}, fwd, DRIVE_SPEED}},
                      true);
  chassis.pid_wait();

  // Drive to 0, 0 backwards
  chassis.pid_odom_set({{0_in, 0_in}, rev, DRIVE_SPEED},
                      true);
  chassis.pid_wait();
}

///
// Odom Pure Pursuit Wait Until
///
void odom_pure_pursuit_wait_until_example() {
  chassis.pid_odom_set({{{0_in, 24_in}, fwd, DRIVE_SPEED},
                        {{12_in, 24_in}, fwd, DRIVE_SPEED},
                        {{24_in, 24_in}, fwd, DRIVE_SPEED}},
                      true);
  chassis.pid_wait_until_index(1);  // Waits until the robot passes 12, 24
  // Intake.move(127);  // Set your intake to start moving once it passes through the second point in the index
  chassis.pid_wait();
  // Intake.move(0);  // Turn the intake off
}

///
// Odom Boomerang
///
void odom_boomerang_example() {
  chassis.pid_odom_set({{0_in, 24_in, 45_deg}, fwd, DRIVE_SPEED},
                      true);
  chassis.pid_wait();

  chassis.pid_odom_set({{0_in, 0_in, 0_deg}, rev, DRIVE_SPEED},
                      true);
  chassis.pid_wait();
}

///
// Odom Boomerang Injected Pure Pursuit
///
void odom_boomerang_injected_pure_pursuit_example() {
  chassis.pid_odom_set({{{0_in, 24_in, 45_deg}, fwd, DRIVE_SPEED},
                        {{12_in, 24_in}, fwd, DRIVE_SPEED},
                        {{24_in, 24_in}, fwd, DRIVE_SPEED}},
                      true);
  chassis.pid_wait();

  chassis.pid_odom_set({{0_in, 0_in, 0_deg}, rev, DRIVE_SPEED},
                      true);
  chassis.pid_wait();
}

///
// Calculate the offsets of your tracking wheels
///
void measure_offsets() {
  // Number of times to test
  int iterations = 10;

  // Our final offsets
  double l_offset = 0.0, r_offset = 0.0, b_offset = 0.0, f_offset = 0.0;

  // Reset all trackers if they exist
  if (chassis.odom_tracker_left != nullptr) chassis.odom_tracker_left->reset();
  if (chassis.odom_tracker_right != nullptr) chassis.odom_tracker_right->reset();
  if (chassis.odom_tracker_back != nullptr) chassis.odom_tracker_back->reset();
  if (chassis.odom_tracker_front != nullptr) chassis.odom_tracker_front->reset();
  
  for (int i = 0; i < iterations; i++) {
    // Reset pid targets and get ready for running an auton
    chassis.pid_targets_reset();
    chassis.drive_imu_reset();
    chassis.drive_sensor_reset();
    chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD);
    chassis.odom_xyt_set(0_in, 0_in, 0_deg);
    double imu_start = chassis.odom_theta_get();
    double target = i % 2 == 0 ? 90 : 270;  // Switch the turn target every run from 270 to 90

    // Turn to target at half power
    chassis.pid_turn_set(target, 63, ez::raw);
    chassis.pid_wait();
    pros::delay(250);

    // Calculate delta in angle
    double t_delta = util::to_rad(fabs(util::wrap_angle(chassis.odom_theta_get() - imu_start)));

    // Calculate delta in sensor values that exist
    double l_delta = chassis.odom_tracker_left != nullptr ? chassis.odom_tracker_left->get() : 0.0;
    double r_delta = chassis.odom_tracker_right != nullptr ? chassis.odom_tracker_right->get() : 0.0;
    double b_delta = chassis.odom_tracker_back != nullptr ? chassis.odom_tracker_back->get() : 0.0;
    double f_delta = chassis.odom_tracker_front != nullptr ? chassis.odom_tracker_front->get() : 0.0;

    // Calculate the radius that the robot traveled
    l_offset += l_delta / t_delta;
    r_offset += r_delta / t_delta;
    b_offset += b_delta / t_delta;
    f_offset += f_delta / t_delta;
  }

  // Average all offsets
  l_offset /= iterations;
  r_offset /= iterations;
  b_offset /= iterations;
  f_offset /= iterations;

  // Set new offsets to trackers that exist
  if (chassis.odom_tracker_left != nullptr) chassis.odom_tracker_left->distance_to_center_set(l_offset);
  if (chassis.odom_tracker_right != nullptr) chassis.odom_tracker_right->distance_to_center_set(r_offset);
  if (chassis.odom_tracker_back != nullptr) chassis.odom_tracker_back->distance_to_center_set(b_offset);
  if (chassis.odom_tracker_front != nullptr) chassis.odom_tracker_front->distance_to_center_set(f_offset);
}

// . . .
// Make your own autonomous functions here!
// . . .