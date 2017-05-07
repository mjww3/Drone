#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <ros/ros.h>
#include <mavros/CommandBool.h>
#include <mavros/SetMode.h>
#include <mavros/Waypoint.h>
#include <mavros/CommandTOL.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros/OverrideRCIn.h>																																																																																																																																																																																																																																																					
#include "/home/mukul/Landing/src/land/src/controller/controller.h"
#include <geometry_msgs/Quaternion.h>
#include "geometry_msgs/TwistStamped.h"
#include "geometry_msgs/Vector3Stamped.h"
#include <mavros/WaypointPush.h>
#include <mavros/WaypointGOTO.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <mavros/State.h>
using namespace std;
using namespace cv;
////State
bool landing_can_be_done= false;
////detect circles
bool detect_circle()
{
	VideoCapture cap(0);
	if(!(cap.isOpened()))
	{
		return "Error in opening the port";
	}
	Mat frame;
	Mat grayFrame;
	Mat cannyFrame;
	while(true)
	{
			/**
			1)If quadcopter has reached the location gps
			2)change mode to guided
			3)detect the circles
			4)center detections 
			5)command generation
			6)landing
			**/
		cap>>frame;
		cvtColor(frame,grayFrame,CV_BGR2GRAY);
		///median blur apply
		medianBlur(frame,frame,3);
		///CANNY
		Canny(grayFrame, cannyFrame, 100, 200, 3);
		///define the vectors
		vector<vector<Point> > contours;
		//vector<vec4i> hierarchy;
		///find the contours
		//findContours(cannyFrame,contours,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE,Point(0,0));
		///now get the geometry of these contours
	}
}
///the main function of everyhting  1-----6
int main(int argc,char** argv)
{
	int rate = 10;
	ros::init(argc,argv,"circle_lander");
	ros::NodeHandle n;
	ros::Rate r(rate);
	bool flag = false;
	bool armed = false;
	bool set_guided=false;
	bool set_altitude=false;
	///Now here will be the publishers and subscribers
	////now check has the Quadcopter reached the position of the gps plate
	///wwaypoint go to the coordinated of the plate 
	///let the plate be at 10,10,10
	///change the mode to guided mode
	 /////////////////GUIDED////////////////////
	 ros::ServiceClient cl = n.serviceClient<mavros::SetMode>("/mavros/set_mode");
	 mavros::SetMode srv_setMode;
	 srv_setMode.request.base_mode = 0;
	 srv_setMode.request.custom_mode = "GUIDED";
	 if(cl.call(srv_setMode)){
	     ROS_ERROR("setmode send ok %d value:", srv_setMode.response.success);
	     set_guided=true;
	 }else{
	     ROS_ERROR("Failed SetMode");
	     return -1;
	 }
	 ///wait for 20 seconds
	 sleep(20);
	 ////change its altitude to just see the plate
	 ///ARMING////
	 if(set_guided==true)
	 {
	 ros::ServiceClient arming_cl = n.serviceClient<mavros::CommandBool>("/mavros/cmd/arming");
	     mavros::CommandBool srv;
	     srv.request.value = true;
	     if(arming_cl.call(srv)){
	         ROS_ERROR("ARM send ok %d", srv.response.success);
	         armed = true;
	     }else{
	         ROS_ERROR("Failed arming or disarming");
	     }
	 }
	 ///TAKEOFF///
	 if(armed==true)
	 {
	 ros::ServiceClient takeoff_cl = n.serviceClient<mavros::CommandTOL>("/mavros/cmd/takeoff");
	 mavros::CommandTOL srv_takeoff;
	 srv_takeoff.request.altitude = 14;
	 srv_takeoff.request.latitude = 0;
	 srv_takeoff.request.longitude = 0;
	 srv_takeoff.request.min_pitch = 0;
	 srv_takeoff.request.yaw = 0;
	 if(takeoff_cl.call(srv_takeoff)){
	     ROS_ERROR("srv_takeoff send ok %d", srv_takeoff.response.success);
	     set_altitude=true;
	 }else{
	     ROS_ERROR("Failed Takeoff");
	   }
	}
	///wait for 20 seconds
	cout<<"sleeping for 20 seconds"<<endl;
	sleep(20);

	ros::Publisher local_go_to = n.advertise<geometry_msgs::PoseStamped>("mavros/setpoint_position/local",10);
	geometry_msgs::PoseStamped pose;
	pose.pose.position.x = 10;
	pose.pose.position.y = 10;
	pose.pose.position.z = 10;

	local_go_to.publish(pose);
	cout<<"fine"<<endl;
	sleep(30);
	///go to the plate point
	ros::ServiceClient send_to_plate = n.serviceClient<mavros::WaypointGOTO>("/mavros/goto");
	mavros::WaypointGOTO srv_goto;
	mavros::Waypoint wp;
	wp.frame = mavros::Waypoint::FRAME_GLOBAL;
	wp.command = mavros::Waypoint::NAV_WAYPOINT;
	wp.is_current = false;
	wp.autocontinue = false;
	wp.x_lat = 10;
	wp.y_long = 10;
	wp.z_alt = 10;
	srv_goto.request.waypoint=wp;
	if(send_to_plate.call(srv_goto))
	{
		ROS_ERROR("ok");
	}
	else
	{
		ROS_ERROR("eror in going to the location");
	}													
	cout<<"Sleeping for 20 seconds"<<endl;
	sleep(20);
	///rc yaw
	ros::Publisher rc_yaw = n.advertise<mavros::OverrideRCIn>("mavros/rc/override",10);
	mavros::OverrideRCIn rcmsg;
	rcmsg.channels[0] = 0;
	rcmsg.channels[1] = 0;
	rcmsg.channels[2] = 0;
	rcmsg.channels[3] = 1400;
	rcmsg.channels[4] = 0;
	rcmsg.channels[5] = 0;
	rcmsg.channels[6] = 0;
	rcmsg.channels[7] = 0;
	rc_yaw.publish(rcmsg);
	ROS_ERROR("ok");
	///change the yaw into the required orientation
	ros::Publisher yaw_pub = n.advertise<geometry_msgs::TwistStamped>("mavros/setpoint_velocity/cmd_vel",10);
	geometry_msgs::TwistStamped msg;
	msg.header.stamp = ros::Time::now();
    msg.header.seq=1;
	msg.twist.linear.x = 10.0;
	msg.twist.angular.z = 3.0;
	yaw_pub.publish(msg);
	cout<<"Sleeping for 20 seconds"<<endl;
	sleep(20);
	bool not_found_anything=false;
	////Land the Quadcopter
	 /////////////////Land////////////////////
	if(not_found_anything==true)
	{
		not_found_anything=true;
	};
	ros::ServiceClient land_cl = n.serviceClient<mavros::SetMode>("/mavros/set_mode/land");
	 mavros::SetMode srv_setMode_rtl;
	 srv_setMode_rtl.request.base_mode = 0;
	 srv_setMode_rtl.request.custom_mode = "RTL";
	 if(cl.call(srv_setMode_rtl)){
	     ROS_ERROR("setmode send ok %d value:", srv_setMode_rtl.response.success);
	 }else{
	     ROS_ERROR("Failed SetMode");
	     return -1;
	 }
	// getManualControlMsg();
	 ///ros Spin
	 while (n.ok())
    {
      ros::spinOnce();
      r.sleep();
    }
return 0;
}
