///To check whether the sonar sensor is running on the 
///raspberry pi and the values are dumped into the 
///topic of /sonar_down
///here sonar sensor is used at the bottom of the quadcopter
#include <ros/ros.h>
#include <iostream>
#include <stdio.h>
#include <mavros/RCIn.h>
#include <mavors/RCOut.h>
#include <algorithm>

using namespace std;
