void setSolenoids(int value) { 
	//Used to set whether the solenoid retracts or extends. See below.
	SensorValue[solenoid1] = value; 
	SensorValue[solenoid2] = value; //planning to have 2 solenoids...
}

void fire() {
	//Pushes cylinder (its inverted)
	setSolenoids(RETRACT);
}

void load() {
	//Pulls cylinders (its inverted)
	setSolenoids(EXTEND);
}

void halt() {
	//Stops the bot, activated by kill switch.
	motor[drvLeft] = 0;
	motor[drvRight] = 0;
}
