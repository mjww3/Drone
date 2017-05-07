#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <TooN/TooN.h>
#include <math.h>
#include <time.h>
#include <mavros/RadioStatus.h>
#include <mavros/RCIn.h>
#include <mavros/RCOut.h>

#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

///user defined in the mission planner
enum Mode {
	MODE_RTL = 1128,
	MODE_LOITER = 1528,
	MODE_STABILISE = 1928
};
/**
* Responsible for generating all control input messages
*/
mavros::RCIn getNeutralControlMsg();

mavros::RCIn getTranslateAndDescendControlMsg();

mavros::RCIn getDescendOnlyControlMsg();

/**
* Creates a message that will return the drone to manual control.
*/
mavros::RCIn getManualControlMsg();

mavros::RCIn getPowerOffControlMsg();

void updateRC(const mavros::RCIn::ConstPtr& rcMsg) ;

#endif
