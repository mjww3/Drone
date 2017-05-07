#include <iostream>
#include <stdio.h>
#include <ros/ros.h>
#include <mavros/VFR_HUD.h>
#include <opencv/opencv2.hpp>
#include <std_msgs/Int8.h>
#include <mavros/Status.h>
#include <mavros/SetMode.h>
#include "/home/mukul/Landing/src/land/src/controller/controller.h"
#include <mavros/RadioStatus.h>
#include <mavros/RCIn.h>
#include <mavros/RCout.h>
using namespace std;
using namespace cv;

void update_telemetry_callback(mavros::VFR_HUD::ConstPtr& hudmessage)
{


}

void update_mode_callback(mavros::State::ConstPtr& statemsg)
{

}

void update_attitude_callback(mavros::State::ConstPtr& attitudemsg)
{

}

void pose_callback()
{

}

void rc_callback(mavros::RCout::ConstPtr& rcmessage)
{

}

int main(int argc,char **argv)
{
	ros::NodeHandle n;

	ros::Rate r(10);
	return 0;
}