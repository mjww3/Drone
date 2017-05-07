#include <ros/ros.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "battery_status.h"

using namespace std;

QuadCopterState lateststate = QuadCopterState();
QuadCopterPose latestpose = QuadCopterPose();
CurrentBatteryStatus latestbattery = CurrentBatteryStatus();

void update_telemetry(const mavros::VFR_HUD::ConstPtr& vfrhudmsg)
{
	lateststate.airspeed = vfrhudmsg->airspeed;
	lateststate.groundspeed = vfrhudmsg->groundspeed;
	lateststate.heading = vfrhudmsg->heading;
	lateststate.throttle = vfrhudmsg->throttle;
	lateststate.altitude = vfrhudmsg->altitude;
	lateststate.climb = vfrhudmsg->climb;
}

void update_current_mode(const mavros::State::ConstPtr& statemsg)
{
	lateststate.mode = statemsg->mode;
}

///update the atitude of the quadcopter
void update_attitude()
{
	lateststate.pitch
	lateststate.yaw
	lateststate.roll

}
///update the battery status

void update_battery_status(const mavros::BatteryStatus::ConstPtr& batterymsg)
{
	latestbattery.voltage = batterymsg->voltage;
	latestbattery.current = batterymsg->current;
	latestbattery.remaining = batterymsg->remaining;
}
///get the quadcopter state
QuadCopterState getQuadcopterState()
{
	return lateststate;
}
////get the quadcopter pose
QuadCopterPose getQuadcopterPose()
{
	return latestpose;
}

bool onGround()
{

}
