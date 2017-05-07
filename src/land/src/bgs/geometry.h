#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>
#include <mavos/VFR_HUD.h>
#include <time.h>

using namespace std;
using namespace cv;

Mat_<double> estimaterottrans
(Mat_<double> const worldPoints,
	Mat_<double>const imagepoints);

///convert cartesian to homogenous
Mat_<double> cartesian2homo(Mat_<double> cartesian)
{
	Mat_<double> homogenous(cartesian.rows,cartesian.columns+1);
	

}

////convert homogenous to cartesian
Mat_<double> homogenous2cartesian(Mat_<double> homogenous)
{
	Mat_<double> cartesian(homogenous.rows,homogenous.columns-1);
	for(int r=0;)
}