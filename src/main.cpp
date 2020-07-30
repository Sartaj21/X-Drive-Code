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
	// A variable for each motor  
	int leftFront=3;
	int leftBack=1;
	int rightFront=2;
	int rightBack=4;
	// Sets up the name and the motors in PROS
	pros::Motor LFDrive(leftFront);
	pros::Motor LBDrive(leftBack);
	// true reverses the motor
	pros::Motor RFDrive(rightFront, true);
	pros::Motor RBDrive(rightBack, true);
	// Sets Up the controller
	pros::Controller master (CONTROLLER_MASTER);
	// We set the brake to hold for all motors
	LFDrive.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  	LBDrive.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
 	RFDrive.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	RBDrive.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);


   while (true){
	   // Power is set to the y axis of the left joystick
	   int power = master.get_analog(ANALOG_LEFT_Y);
	   // Turning is set to the x axis of the right joystick
	   int turn   = master.get_analog(ANALOG_RIGHT_X);
	   // Strafe is set to the x axis of the left joystick
   	   int strafe = master.get_analog(ANALOG_LEFT_X);
	   // We set the power of the Left Front Motor to the postion of the varaible power postion + the turn postion + the strafe postion
       int LF = power + turn + strafe;
	   // We set the power of the Left Back Motor to the postion of the varaible power postion + the turn postion - the strafe postion
	   int LB = power + turn - strafe;
	   // We set the power of the Right Front Motor to the postion of the varaible power postion - the turn postion - the strafe postion
	   int RF = power - turn - strafe;
	   // We set the power of the Right Back Motor to the postion of the varaible power postion + the turn postion - the strafe postion
	   int RB = power - turn + strafe;

	   // We tell the motor to spin at the velocity of the caluclated number in the step above.
	   LFDrive.move(LF);
	   LBDrive.move(LB);
	   RFDrive.move(RF);
	   RBDrive.move(RB);
   }
}
