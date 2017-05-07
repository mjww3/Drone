#include "controller.h"
#include <mavros/RadioStatus.h>
#include <mavros/RCIn.h>
#include <mavros/RCOut.h>
#include <vector>
#include "std_msgs/Int32MultiArray.h"


// values from radio calibration in MissionPlanner
// 1: aileron, neutral = 1527, low = 1128, high = 1925
// 2: elevator, neutral = 1528, low = 1921, high = 1124
// 3: throttle, neutral ?, low = 1124, high = 1927
// 4: yaw, neutral = 1530, low = 1131, high = 1928
// 5: mode, low = 1128, med = 1528, high = 1928

enum Aileron {
	AILERON_LOW = 1128,
	AILERON_HIGH = 1925,
	AILERON_RANGE = 797
};

enum Elevator {
	ELEVATOR_LOW = 1124,
	ELEVATOR_HIGH = 1921,
	ELEVATOR_RANGE = 797 
};

enum Throttle {
	THROTTLE_LOW = 1124,
	THROTTLE_HIGH = 1927
};

enum Yaw {
	YAW_LOW = 1128,
	YAW_HIGH = 1928,
	YAW_RANGE = 800
};

const int NEUTRAL = 1528;
int AILERON_NEUTRAL = NEUTRAL;
int ELEVATOR_NEUTRAL = NEUTRAL;
int THROTTLE_NEUTRAL = 0;
int YAW_NEUTRAL = NEUTRAL;

const float PI_F=3.14159265358979f;
const float YAW_CORRECTION = 0.08; // ~= 5 degrees 
const float	THROTTLE_GAIN = 0.05;

// Global, set by cmdline param
// Max error for x,y dimensions in mm
int MAX_DISPLACEMENT_ERROR;

int getMaxDisplacementError()
{
    return MAX_DISPLACEMENT_ERROR;
}

void setMaxDisplacementError(int err)
{
    MAX_DISPLACEMENT_ERROR = err;
}

mavros::RCIn buildRCMsg(int aileron, int elevator, int throttle, int yaw) {
	mavros::RCIn msg;
	msg.channels[0] = aileron;
	msg.channels[1] = elevator;
	msg.channels[2] = throttle;
	msg.channels[3] = yaw;
	//We never override channel 4, this will let us recover to manual control.
	msg.channels[4] = 0;
	//Channels 5-7 are not in use, so we set them = 0.
	msg.channels[5] = 0;
	msg.channels[6] = 0;
	msg.channels[7] = 0;
	return msg;
}

mavros::RCIn getNeutralControlMsg () {
	return buildRCMsg(AILERON_NEUTRAL, ELEVATOR_NEUTRAL, THROTTLE_NEUTRAL, \
		YAW_NEUTRAL);
}

/**mavros::RCIn getRotationControlMsg () {
	double yaw_error =  getQuadcopterPose().yaw; //radians
	double yaw_gain = -1 * (yaw_error / PI_F);
	int yaw = (int) ((yaw_gain * YAW_RANGE) / 2) + YAW_NEUTRAL;
	return buildRCMsg(AILERON_NEUTRAL, ELEVATOR_NEUTRAL, THROTTLE_NEUTRAL, yaw);
}**/

mavros::RCIn getDescendOnlyControlMsg () {
	int throttle = (1 - THROTTLE_GAIN) * THROTTLE_NEUTRAL;
	return buildRCMsg(AILERON_NEUTRAL, ELEVATOR_NEUTRAL, throttle, YAW_NEUTRAL);
}

mavros::RCIn getManualControlMsg () {
	return buildRCMsg(0,0,0,0);
}

mavros::RCIn getPowerOffControlMsg () {
	return buildRCMsg(AILERON_NEUTRAL, ELEVATOR_NEUTRAL, THROTTLE_LOW, \
		YAW_NEUTRAL);
}


/**mavros::RCIn getTranslateAndDescendControlMsg () {
	if (getQuadcopterPose().yaw > YAW_CORRECTION || getQuadcopterPose().yaw < (-1*YAW_CORRECTION)) {
		return getRotationControlMsg();
	}

	// Assume we are always pointing forwards and therefore
	// can map x and y onto aileron and elevator inputs
	double x_error = getQuadcopterPose().x; //mm
				double y_error = getQuadcopterPose().y; //mm

	float aileron_gain = -1 * (x_error / MAX_DISPLACEMENT_ERROR);
	float elevator_gain = -1 * (y_error / MAX_DISPLACEMENT_ERROR);

	int aileron = (int) ((aileron_gain * AILERON_RANGE) / 2) + AILERON_NEUTRAL;
	int elevator = (int) ((elevator_gain * ELEVATOR_RANGE) / 2) + ELEVATOR_NEUTRAL;

	// Calculate z error
	// FIX THROTTLE FOR NOW (always descending)
	double z_error =  getQuadcopterPose().z; //mm
	int throttle = (1 - THROTTLE_GAIN) * THROTTLE_NEUTRAL;

	return buildRCMsg(aileron, elevator, throttle, YAW_NEUTRAL);
}


void updateRC(const mavros::RCIn::ConstPtr& rcMsg) {
	if (!isLanderActive()) {
		AILERON_NEUTRAL = rcMsg->channels[0];
		ELEVATOR_NEUTRAL = rcMsg->channels[1];
		THROTTLE_NEUTRAL = rcMsg->channels[2];
		YAW_NEUTRAL = rcMsg->channels[3];
	}
}**/
