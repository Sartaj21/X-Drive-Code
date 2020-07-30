#include "main.h"



/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(0, "X Drive");


}


void disabled() {}


void competition_initialize() {}


void autonomous() {}


void opcontrol() {
	int leftFront=3;
	int leftBack=1;
	int rightFront=2;
	int rightBack=4;
	pros::Motor LFDrive(leftFront);
	pros::Motor LBDrive(leftBack);
	pros::Motor RFDrive(rightFront, true);
	pros::Motor RBDrive(rightBack, true);
	pros::Controller master (CONTROLLER_MASTER);
	LFDrive.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  	LBDrive.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
 	RFDrive.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	RBDrive.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);


   while (true){
	   int power = master.get_analog(ANALOG_LEFT_Y);
	   int turn   = master.get_analog(ANALOG_RIGHT_X);
   	   int strafe = master.get_analog(ANALOG_LEFT_X);
       int LF = power + turn + strafe;
	   int LB = power + turn - strafe;
	   int RF = power - turn - strafe;
	   int RB = power - turn + strafe;

	   LFDrive.move(LF);
	   LBDrive.move(LB);
	   RFDrive.move(RF);
	   RBDrive.move(RB);
   }
}
