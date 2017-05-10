void setSolenoids(int value) {
	SensorValue[solenoid1] = value;
	SensorValue[solenoid2] = value;
}

void fire() {
	setSolenoids(RETRACT);
}

void load() {
	setSolenoids(EXTEND);
}
