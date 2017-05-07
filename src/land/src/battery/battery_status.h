#include <ros/ros.h>
#include <mavros/BatteryStatus.h>
#include <vector>
#include <vector>
#include <stdio.h>
#include <mavros/SetMode.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <mavros/State.h>
#include <mavros/VFR_HUD.h>
///also defines the whole Quadcopter
///Battery status is a message file of ros
#ifndef __BATTERY_STATUS__H__
#define __BATTERY_STATUS__H__
using namespace std;
///current battery status
struct CurrentBatteryStatus
{
	float voltage;
	float current;
	float remaining;///this is from a scale 0-------1
};

///Quadcopter Pose
struct QuadCopterPose
{
	float x;
	float y;
	float z;
	double heading;
};

///Sizes
enum Sizes
{
	large,
	medium,
	small
};

///Plate
struct Plate
{
	double latitude;
	double longitude;
	double altitude;
	Sizes size;
};

///get the Quadcopter State
struct QuadCopterState
{
	double pitch;
	double roll;
	double yaw;
	float throttle;
	float altitude;
	int heading;
	vector<double> location;
	float airspeed;
	float groundspeed;
	CurrentBatteryStatus batterystatus;
	bool isArmed;
	bool hasReachedLocation;
	bool isDirectlyAbove;
	bool guided;
	string mode;
	float climb;
	float name;
	long long int UUID;
	//this is the uuid generated
	////this will be the getters and setters
	///these are the functions
};

	void set_pitch();
	///set the roll
	void set_roll();
	///set the yaw
	void set_yaw();
	////get the current battery status
	void update_battery_status(const mavros::BatteryStatus::ConstPtr& batterystatusmsg);
	///get the current mode
	void update_current_mode(const mavros::State::ConstPtr& statemsg);
	///update the attitude
	void update_attitude(const mavros::VFR_HUD::ConstPtr& vfrhudmsg);
	///update the telemetry
	void update_telemetry(const mavros::VFR_HUD::ConstPtr& vfrhudmsg);
	///is on ground??
	bool onGround();
	///check whether the quadccotper is below field of view
	bool belowFieldOfView();
	///get the quadcopter state
	QuadCopterState getQuadcopterState();
	////get the quadcopter pose
	QuadCopterPose getQuadcopterPose();
};
#endif																											