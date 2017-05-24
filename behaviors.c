void setSolenoids(int value) {
	SensorValue[solenoid1] = value;
	SensorValue[solenoid2] = value;
}

void fire() {
	setSolenoids(RETRACT);
}

void load() {
	//Pulls the
	setSolenoids(EXTEND);
}

void halt() {
	motor[drvLeft] = 0;
	motor[drvRight] = 0;
}
