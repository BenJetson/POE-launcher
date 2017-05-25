
bool killSwitch = false;

//void driveControl() { // OLD; BROKEN -- use new method below.
//	motor[drvLeft]  = (vexRT[Ch1] + vexRT[Ch2])/2;
//	motor[drvRight] = (vexRT[Ch1] - vexRT[Ch2])/2;
//}

void cannonControl() {
	if (vexRT[Btn5U] == 1) {
		fire(); //When button "5U" is pressed, it retracts the cylinder.
	} else if (vexRT[Btn5D] == 1) {
		load(); //When button "5D" is pressed, it extends the cylinder.
	}
}

void driveControl() {
	if (abs(vexRT[Ch2]) > THRESHOLD && abs(vexRT[Ch1]) < THRESHOLD) {
		motor[drvLeft] = vexRT[Ch2];
		motor[drvRight] = vexRT[Ch2];
	} else if (abs(vexRT[Ch2]) > THRESHOLD && vexRT[Ch1] > THRESHOLD) {
		motor[drvLeft] = vexRT[Ch2];
		motor[drvLeft] = vexRT[Ch2] / 2;
	} else if (abs(vexRT[Ch2]) > THRESHOLD && vexRT[Ch1] < -THRESHOLD) {
		motor[drvLeft] = vexRT[Ch2] / 2;
		motor[drvRight] = vexRT[Ch2];
	} else {
		motor[drvLeft] = 0;
		motor[drvRight] = 0;
	}
}

void releaseControl() {
	if (vexRT[Btn6D] == 1) {
		motor[releaseMotor] = MOTOR_MAX;
	} else if (vexRT[Btn6U] == 1) {
	  motor[releaseMotor] = -MOTOR_MAX;
	} else {
		motor[releaseMotor] = MOTOR_STOP;
	}
}

bool killSwitchControl() {
	if (vexRT[Btn7U] == 1 && vexRT[Btn8U] == 1) {
		killSwitch = false;
	} else if (vexRT[Btn7D] && vexRT[Btn8D] == 1) {
		killSwitch = true;
	}
	return killSwitch;
}
