/*
 * CommandBase.h
 *
 *  Created on: Jan 30, 2017
 *      Author: FIRSTUser
 */

#ifndef SRC_AUTOCOMMANDS_COMMANDBASE_H_
#define SRC_AUTOCOMMANDS_COMMANDBASE_H_
#include "CommandInterface.h"
#include "CommandIO.h"
#include <math.h>
class CommandBase : public CommandInterface {
public:
	CommandBase();
	virtual ~CommandBase();
	bool isDone();
protected:
	void setComplete();
	commandOutput doNothing();
	bool compareDouble(double x, double y);
private:
	bool commandComplete;
};

#endif /* SRC_AUTOCOMMANDS_COMMANDBASE_H_ */
