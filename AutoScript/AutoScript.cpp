/*
 * AutoScript.cpp
 *
 *  Created on: Feb 23, 2017
 *      Author: FIRSTUser
 */

#include "AutoScript.h"

int main() {
	manager = new CommandManager((robotTeam)0, (robotStation)0, (robotAction)0);
	input.LWhlEnc = 0.5;
	input.RWhlEnc = 4;
	input.currentGyroReading = 270;
	input.shooterEnc = 0;
	manager->tick(input);
}

