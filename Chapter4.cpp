#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace std;
using namespace cv;

////////////// Draw Shapes & Writing Text  //////////////////

void main() {
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));	// CV_8UC3 means, 8 bit(0 - 255) unsigned 3 channels (BGR)
													// Scaler is used for giving colour in order (BGR)

	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);  // (output_image, location of circle in image, radius, color, thickness/FILLED)
	rectangle(img, Point(130, 226), Point(382, 286) , Scalar(255, 250, 255), FILLED);
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 5, 9);
	putText(img, "www.balveersingh.in", Point(145, 262), FONT_HERSHEY_SCRIPT_COMPLEX, 0.8, Scalar(255, 69, 169), 2);

	imshow("BG Image", img);

	waitKey(0);

}
