/*
 * CommandManager.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: FIRSTUser
 */

#include "CommandManager.h"
#include "CommandDrive.h"
#include "CommandPause.h"
#include "CommandTurn.h"
#include "CommandVision.h"
#include "CommandShoot.h"
#include <stdio.h>

CommandManager::CommandManager(robotTeam team, robotStation station, robotAction action) {

	commands = queue<CommandBase*>();
	buildCommands(&commands, team, station, action);

	commands.push(_doNothing = new CommandPause(-1));
	currCommand = NULL;
}

commandOutput CommandManager::tick(commandInput input) {

	if (currCommand == NULL || currCommand->isDone())
		currCommand = getNextCommand(input);

	return currCommand == NULL
		? commandOutput()
		: currCommand->tick(input);
}

CommandBase *CommandManager::getNextCommand(commandInput input) {

	// In the event that all prior commands have been popped off the queue, do nothing.
	if (commands.size() < 1)
		return _doNothing;

	CommandBase *nextCommand =  commands.front();
	commands.pop();

	//Need to add NULL protection here in case no command was added to the queue prior to the pop
	if (currCommand != NULL) delete currCommand;

	if(nextCommand == NULL)
	{
		printf("Received a null command from the queue.\n");
		return _doNothing;
	}

	printf("Retrieved a %s Command from the queue.\n", nextCommand->getCommandName());
	nextCommand->init(input);
	printf("Command Init Successful\n");
	return nextCommand;
}

void CommandManager::buildCommands(queue<CommandBase*> *queue, robotTeam team, robotStation station, robotAction action) {
	switch(action) {
	case CROSS_MIDLINE:
		crossMidline(queue, team, station);
		break;
	case SHOOT_ONLY:
		shootOnly(queue, team, station);
		break;
	case SHOOT_ONLY_BIN:
		shootOnlyBin(queue, team, station);
		break;
	default:
		break;
	}
	queue->push(new CommandPause(-1));
}

//ALL VALUES IN COMMANDS ARE PLACEHOLDERS FOR ACTUAL VALUES
void CommandManager::crossMidline(queue<CommandBase*> *queue,robotTeam team, robotStation station) {
	//Drive forward until to a speficied point
}

void CommandManager::shootOnly(queue<CommandBase*> *queue,robotTeam team, robotStation station) {
	//Do one specific task
}

void CommandManager::shootOnlyBin(queue<CommandBase*> *queue,robotTeam team, robotStation station) {
	//Do above command and a bit more
}

double CommandManager::configShooterSpd(robotTeam team, robotStation RS)
{
	//Modify numerical values to match the physical shooter
	double shooterSpd = 0;
	if(team == robotTeam::RED)
	{
		if(RS == ONE) shooterSpd = 3000;
		else if (RS == TWO) shooterSpd = 3900;
		else if (RS == THREE) shooterSpd = 4600;
	} else {
		if(RS == THREE) shooterSpd = 3000;
		else if (RS == TWO) shooterSpd = 3900;
		else if (RS == ONE) shooterSpd = 4600;
	}

	return shooterSpd;
 }

double CommandManager::configShooterAng(robotTeam team, robotStation RS)
{
	//Modify numerical values to match the physical shooter
	double shooterAng = 0;
	if(team == robotTeam::RED)
	{
		if(RS == ONE) shooterAng = .4;
		else if (RS == TWO) shooterAng = .6;
		else if (RS == THREE) shooterAng = 1;
	} else {
		if(RS == THREE) shooterAng = .4;
		else if (RS == TWO) shooterAng = .6;
		else if (RS == ONE) shooterAng = 1;
	}

	return shooterAng;
}

CommandManager::~CommandManager() {
	// TODO Auto-generated destructor stub
}

