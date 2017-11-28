/*
 * CommandDrive.cpp
 *
 *  Created on: Jan 31, 2017
 *      Author: FIRSTUser
 */

#include "CommandDrive.h"
#include <stdio.h>

CommandDrive::CommandDrive(double toTravel, double direction) {
	// TODO Auto-generated constructor stub
	_toTravel = toTravel;
	_direction = direction;
}

commandOutput CommandDrive::tick(commandInput input) {
	printf("DRIVING\n");

	if (checkDistance(input) >= _toTravel) {
		setComplete();
		printf("DRIVE COMPLETE\n");
		return doNothing();
	}

	return commandOutput(.5);
}

void CommandDrive::init(commandInput input) {

	LWhlEncInit = input.LWhlEnc;
	RWhlEncInit = input.RWhlEnc;
}

const char* CommandDrive::getCommandName()
{
	return "Drive";
}

double CommandDrive::checkDistance(commandInput input) {

	double LWhlDrvEnc = fabs(input.LWhlEnc - LWhlEncInit);
	double RWhlDrvEnc = fabs(input.RWhlEnc - RWhlEncInit);

	double EncAvg = (LWhlDrvEnc + RWhlDrvEnc) / 2;

	printf("ENcAvg: %f", EncAvg);

	return EncAvg;

}

CommandDrive::~CommandDrive() {
	// TODO Auto-generated destructor stub
}

