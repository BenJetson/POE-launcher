
void driveControl() {
	motor[drvLeft]  = (vexRT[Ch2] + vexRT[Ch1])/2;
	motor[drvRight] = (vexRT[Ch2] - vexRT[Ch1])/2;
}

void cannonControl() {
	if (vexRT[Btn5U] == 1) {
		fire();
	} else if (vexRT[Btn5D] == 1) {
		load();
	}
}
