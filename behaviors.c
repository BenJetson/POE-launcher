void setSolenoids(int value) { 
	//Used to set whether the solenoid retracts or extends. See below.
	SensorValue[solenoid1] = value; 
	SensorValue[solenoid2] = value; //planning to have 2 solenoids...
}

void fire() {
	//Pushes cylinders
	setSolenoids(EXTEND);
}

void load() {
	//Pulls cylinders
	setSolenoids(RETRACT);
}

void halt() {
	//Stops the bot, activated by kill switch.
	motor[drvLeft] = 0;
	motor[drvRight] = 0;
}
