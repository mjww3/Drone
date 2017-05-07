#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <ros/ros.h>
#include <std_msgs/Int8.h>
#include <mavros/CommandTOL.h>
#include <mavros/State.h>
#include "/home/mukul/Landing/src/land/src/pid/pid.h"
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <mavros/CommandTOL.h>
#include <vector>
using namespace std;
using namespace cv;
///This will be the background substraction test
///this is to check the eccentricity
///area of the plate according to the hiegth and camera
///this area needs to be in pixels
///get eccentricity
double getEccentricity(Moments &mu){
	double c = (mu.mu20-mu.mu02)*(mu.mu20-mu.mu02);
	double b = (mu.mu20+mu.mu02)*(mu.mu20+mu.mu02);
	return abs((double)((c-4*(mu.mu11)*(mu.mu11))/b));
}
////detect nested circles
vector<bool> nestedCircles; 

///find the common center
///as now there is sometimes  different center
///distance between 2 points in pixels
double distancebetween2points(Point center_frame,Point roi_center)
{
	double linka = (center_frame.x-roi_center.x)^2;
	double linkb = (center_frame.y-roi_center.y)^2;
	double distance = abs(sqrt(linka+linkb));
	return distance;
}
///cut the roi///
////the conversion from pixels to meters
////some variables
int threshold_value = 100;
int threshold_type = 3;
int thresh = 100;
////for the red color detection
 int iLowH = 100;
 int iHighH = 179;

 int iLowS = 0; 
 int iHighS = 255;

 int iLowV = 0;
 int iHighV = 255;
///eccentricity threshold
double eccentricitythresh = 0.6;
int const max_value = 255;
int const max_type = 4;
std_msgs::Int8 msg;
////rng 
RNG rng(12345);
////max binary value
int const max_BINARY_value = 255;
///main function
int main(int argc,char** argv)
{
	//initialize ros
	ros::init(argc,argv,"bgs_test");
	ros::NodeHandle n;
	///define a ros publisher
	ros::Publisher distance_publish = n.advertise<std_msgs::Int8>("/drone/distancetocenter/",1000);
	ros::Rate loopRate(10);																																																																																							
	VideoCapture cap(0);
	///if cap is not opened
	if(!cap.isOpened())
	{
		return -1;
	}
	///frame
	Mat frame;
	///grayscale frame
	Mat grayscale;
while(true)
 {
 	////frame
	cap>>frame;
	imshow("frame",frame);
	///convert color
	cvtColor(frame,grayscale,CV_BGR2GRAY);
	///thresh frame:
	Mat thresh_frame;
	Mat frame_copy;
	frame.copyTo(frame_copy);
	///apply the color detection
	//make the hsv image
	Mat imgHSV;
	///convert to the hsv colorplane
	cvtColor(frame_copy,imgHSV,CV_BGR2HSV);
	///this will be the result image of the color detection
	Mat imgThresholded;
	inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded);
	////now show this image
	imshow("color filter",imgThresholded);
	///threshold:
	threshold( grayscale, thresh_frame, threshold_value, max_BINARY_value,threshold_type );
	///canny output:
	Mat canny_output;
	vector<vector<Point> > contours;
	///hierarchy
	vector<Vec4i> hierarchy;
	Canny( grayscale, canny_output, thresh, thresh*2, 3 );
	///morphological opening (removes small objects from the foreground)
	//erode(canny_output, canny_output, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
	//dilate( canny_output, canny_output, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 
	///find contours
	findContours(canny_output,contours,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE,Point(0,0));
	/// Find the rotated rectangles and ellipses for each contour
	vector<RotatedRect> minRect( contours.size() );
	vector<RotatedRect> minEllipse( contours.size() );
	vector<float> major_axis(contours.size());
	vector<float> minor_axis(contours.size());
	///calculate moments
	vector<Moments> mu(contours.size() );
	for( int i = 0; i < contours.size(); i++ )
	    { 
	    	mu[i] = moments( contours[i], false ); 
	    	minRect[i] = minAreaRect(Mat(contours[i]));
	    	if(contours[i].size()>5)
	    	{
	    		minEllipse[i] = fitEllipse(Mat(contours[i]));
	    	}
	    }
	///  Get the mass centers:
	vector<Point2f> mc( contours.size() );
	for( int i = 0; i < contours.size(); i++ )
	     { 
	     	mc[i] = Point2f( mu[i].m10/mu[i].m00 , mu[i].m01/mu[i].m00 ); 
	     }
	////parent contours
	 int *parentContours = new int[contours.size()];
	 for(int i=0;i<contours.size();i++)
	 {
	 	parentContours[i] = 0;
	 }
	///drawing matrix
	Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
	////contours size 
	///draw a circle at the center of the image
	Point p;
	p.y = drawing.rows/2;
	p.x = drawing.cols/2;
	///color
	Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
	///draw a circle at the center
	circle(drawing,p,10,color,1,8,0);
	putText(drawing,"Center",p,FONT_HERSHEY_PLAIN,1,color,1,8,false);
	for(int i=0;i<contours.size();i++)
	 {
	 	Moments m = moments(contours[i],false);
	   	double e = getEccentricity(m);
	   	double area = contourArea(contours[i],false);
	   	double perimeter = arcLength(contours[i],true);
	   	double roundness  = (4*3.14159*area)/(perimeter*perimeter);
	   if(contourArea(contours[i],false)>600.0 && hierarchy[i][3]>0 && (e<1.0) && roundness>0.8 && roundness<=1.0)
	   {
	   	 //cout<<e<<endl;
	   	 //cout<<roundness<<endl;
	  	 Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
	     drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
	     circle( drawing, mc[i], 4, color, -1, 8, 0 );
	     //ellipse( drawing, minEllipse[i], color, 2, 8 );
	     //Point2f revct_points[4]; minRect[i].points( rect_points );
	     /**for( int j = 0; j < 4; j++ )
	     {
	        line( drawing, rect_points[j], rect_points[(j+1)%4], color, 1, 8 );
	     }**/
	     line(drawing,mc[i],p,color,1,8,0);
	     cout<<distancebetween2points(mc[i],p)<<endl;
	     msg.data = distancebetween2points(mc[i],p);
	     distance_publish.publish(msg);
	 	}
	 }
	///imshow	
	imshow("contours",drawing);     
	if(waitKey(30)>=0)
	break;
}
///return
return 0;
}
