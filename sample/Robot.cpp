#include "WPILib.h"

using namespace std;

class Robot : public SimpleRobot {
private:
	Joystick joy;
	Talon motor;
	DriverStationLCD *dslcd;

public:
	Robot(): joy(1),
			 motor(1),
			 dslcd(DriverStationLCD::GetInstance())
	{
		printf("Robot object created!\n");
	}

	/**
	 * Print a message stating that the robot has been initialized.
	 */
	void RobotInit() {
		printf("Robot initialized!\n");
		dslcd->PrintfLine(DriverStationLCD::kUser_Line1, "RobotInit");
		dslcd->UpdateLCD();
	}

	/**
	 * Print a message stating that the robot is disabled.
	 */
	void Disabled() {
		printf("Robot disabled!\n");
	}

	/**
	 * Print a message stating that the robot is in autonomous mode.
	 */
	void Autonomous() {
		printf("Autonomous mode enabled!\n");
	}

	/**
	 * Print a message stating that the robot is in operator-controlled mode.
	 */
	void OperatorControl() {
		printf("Operator control enabled!\n");
		while(IsEnabled() && IsOperatorControl()) {
			dslcd->PrintfLine(DriverStationLCD::kUser_Line2, "RobotMain/Teleop");
			dslcd->UpdateLCD();

			motor.Set(joy.GetRawAxis(2));

			Wait(0.005);
		}
	}

	/**
	 * Print a message stating that the robot is in test mode.
	 */
	void Test() {
		printf("Test mode enabled!\n");
	}
};

START_ROBOT_CLASS(Robot);
