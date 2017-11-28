/*
 * CommandIO.h
 *
 *  Created on: Jan 30, 2017
 *      Author: FIRSTUser
 */

#ifndef SRC_AUTOCOMMANDS_COMMANDIO_H_
#define SRC_AUTOCOMMANDS_COMMANDIO_H_

	struct commandOutput {
		double autoSpeed;
		double autoShooterSpd;
		double autoLoadSpd;
		double autoAimAng;
		double autoIntakePwr;

		commandOutput() {
			autoSpeed = 0;
			autoShooterSpd = 0;
			autoLoadSpd = 0;
			autoIntakePwr = 0;
			autoAimAng = .4;
		}

		commandOutput(double mag) {
			autoSpeed = mag;
			autoShooterSpd = 0;
			autoLoadSpd = 0;
			autoIntakePwr = 0;
			autoAimAng = .4;
		}

		commandOutput(double shootSpd, double rotSpd) {
			autoSpeed = 0;
			autoIntakePwr = 0;
			autoShooterSpd = shootSpd;
			autoLoadSpd = rotSpd;
			autoAimAng = .4;
		}

		commandOutput(double mag, double shootSpd, double rotSpd, double aimAng, double intakePwr){
			autoSpeed = mag;
			autoShooterSpd = shootSpd;
			autoLoadSpd = rotSpd;
			autoAimAng = aimAng;
			autoIntakePwr = intakePwr;
		}
	};

	struct  commandInput {
		double currentGyroReading;
		double LWhlEnc;
		double RWhlEnc;
		double shooterEnc;
	};

	enum robotTeam {
		NONE,
		BLUE,
		RED
	};

	enum robotStation {
		UNKNOWN,
		ONE,
		TWO,
		THREE
	};

	enum robotAction {
		NO_AUTO,
		CROSS_MIDLINE,
		SHOOT_ONLY,
		SHOOT_ONLY_BIN
	};


#endif /* SRC_AUTOCOMMANDS_COMMANDIO_H_ */
