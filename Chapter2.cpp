#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

///////////////// Basic Image Functions ///////////

void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCannyEdge, imgDilation, imgErode;

	// In python, we genrally write
	// imgGray = cvtColor(img, COLOR_BGR2GRAY)
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);
	Canny(imgBlur, imgCannyEdge, 25, 55);			// edges in blured image are more visible

	// Dilation is the process of increasing thikness of edges to fill the gaps
	Mat kernal = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCannyEdge, imgDilation, kernal);

	// Erosion is the process of decreasing thickness, inorder to increase the gap. Helps in seprating out edges
	erode(imgDilation, imgErode, kernal);
	
	imshow("Orignal Image", img);
	imshow("Gray scale Image", imgGray);
	imshow("Blur Image", imgBlur);
	imshow("Canny Edge Detection", imgCannyEdge);
	imshow("Dilation on Canny", imgDilation);
	imshow("Erossion on Dilated Image", imgErode);
	waitKey(0);
}