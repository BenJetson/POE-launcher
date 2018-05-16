
// Default kill switch state
bool killSwitch = false;

void cannonControl() {
	if (vexRT[Btn5U] == 1) {
		fire(); //When button "5U" is pressed, it retracts the cylinder.
	} else if (vexRT[Btn5D] == 1) {
		load(); //When button "5D" is pressed, it extends the cylinder.
	}
}

void driveControl() {
	if (abs(vexRT[Ch2]) > THRESHOLD && abs(vexRT[Ch1]) < THRESHOLD) { // Forward/Back
		motor[drvLeft] = vexRT[Ch2];
		motor[drvRight] = vexRT[Ch2];
	} else if (abs(vexRT[Ch2]) > THRESHOLD && vexRT[Ch1] > THRESHOLD) { // Turn right 
		motor[drvLeft] = vexRT[Ch2];      // Left at full speed
		motor[drvRight] = vexRT[Ch2] / 2; // Right at half speed
	} else if (abs(vexRT[Ch2]) > THRESHOLD && vexRT[Ch1] < -THRESHOLD) { // Turn left
		motor[drvLeft] = vexRT[Ch2] / 2; // Left at half speed
		motor[drvRight] = vexRT[Ch2];    // Right at full speed
	} else {
		motor[drvLeft] = MOTOR_STOP;
		motor[drvRight] = MOTOR_STOP;
	}
}

void releaseControl() {
	if (vexRT[Btn6D] == 1) {              // If release down button pressed,
		motor[releaseMotor] = MOTOR_MAX;  // turn release motor CCW.
	} else if (vexRT[Btn6U] == 1) {       // If release up button pressed,
	  motor[releaseMotor] = -MOTOR_MAX;   // turn release motor CW.
	} else {                              // Otherwise:
		motor[releaseMotor] = MOTOR_STOP; // disable release motor
	}
}

bool killSwitchControl() {
	if (vexRT[Btn7U] == 1 && vexRT[Btn8U] == 1) { // If disable combo pressed
		killSwitch = false; // disable kill switch
	} else if (vexRT[Btn7D] && vexRT[Btn8D] == 1) { // If enable combo pressed
		killSwitch = true;  // enable kill switch
	}
	return killSwitch; // return state of kill switch
}
