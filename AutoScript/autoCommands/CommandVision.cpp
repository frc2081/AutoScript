/*
 * CommandVision.cpp
 *
 *  Created on: Jan 31, 2017
 *      Author: FIRSTUser
 */

#include "CommandVision.h"

CommandVision::CommandVision() {
	// TODO Auto-generated constructor stub
	autoMag = 0;

	//Init vision stuff
}

void CommandVision::init(commandInput input) {
}

const char* CommandVision::getCommandName()
{
	return "Vision";
}

commandOutput CommandVision::tick(commandInput input) {

	//Input vision stuff here

	return commandOutput(autoMag);
}

CommandVision::~CommandVision() {
	// TODO Auto-generated destructor stub
}

