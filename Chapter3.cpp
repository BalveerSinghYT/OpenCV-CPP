#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace std;
using namespace cv;

////////////// Resize & Crop //////////////////

void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat resizeImg, cropImg;

	resize(img, resizeImg, Size(), 0.5, 0.5);
	
	Rect roi(100, 100, 150, 160); // React means rectangle
	cropImg = resizeImg(roi);

	imshow("Original Image", img);
	imshow("Resize Image", resizeImg);
	imshow("Crop Image", cropImg);

	waitKey(0);
}