#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/////////////// Color Detection /////////////////

string path = "Resources/shapes.png";
Mat imgHSV, mask;

void main() {
	
	Mat img = imread(path);
	
	// Step1: changing color from BGR to HSV (Hue, Saturation, Value)
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	// Step2: create a mask of color range that you want to extract from the imgHSV

	/*-------------- using a custom Mask----------------------
	int hmin = 0, smin = 110, vmin = 153;
	int hmax = 19, smax = 240, vmax = 255;
	Scalar lower(hmin, smin, vmin);
	Scalar upper(hmax, smax, vmax);
	inRange(imgHSV, lower, upper, mask);


	imshow("Org Image", img);
	imshow("HSV Image", imgHSV);
	imshow("Mask Image", mask);

	waitKey(0);
	*/


	//--------------- using track bars ------------------------
	int hmin = 0, smin = 0, vmin = 0;
	int hmax = 179, smax = 255, vmax = 255;

	namedWindow("Track Bar", (640, 200));
	createTrackbar("Hue min", "Track Bar", &hmin, 179);
	createTrackbar("Hue max", "Track Bar", &hmax, 179);
	createTrackbar("Sat min", "Track Bar", &smin, 255);
	createTrackbar("Sat max", "Track Bar", &smin, 255);
	createTrackbar("Val min", "Track Bar", &vmin, 255);
	createTrackbar("Val max", "Track Bar", &vmin, 255);

	while (true) {
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);

		imshow("Org Image", img);
		imshow("HSV Image", imgHSV);
		imshow("Mask Image", mask);

		waitKey(1);
	}	
}