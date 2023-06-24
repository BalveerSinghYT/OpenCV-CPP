#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>

using namespace std;
using namespace cv;

///////////////// Warp Images ////////////////////

float w = 250, h = 350;			// resolution of Warp Image/Window
Mat matrix, imgWarp1, imgWarp2;

void main() {
	string path = "Resources/cards.jpg";
	Mat img = imread(path);

	// King
	Point2f src[4] = { {529, 143}, {772, 192}, {405, 392}, {675, 456} };	// Point2f mean float point, order is a[0, 0], a[0, 1], a[1, 0], a[1, 2]
	Point2f dst[4] = { {0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h} };		// location of points in Warp Image
	
	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp1, matrix, Size(w, h));
	
	for (int i = 0; i < 4; i++) {
		circle(img, Point(src[i]), 5, Scalar(0, 0, 255), FILLED);
	}

	// Queen
	Point2f src[4] = { {63, 325}, {338, 278}, {92, 635}, {404, 572} };
	Point2f dst[4] = { {0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h} };


	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp2, matrix, Size(w, h));

	for (int i = 0; i < 4; i++) {
		circle(img, Point(src[i]), 5, Scalar(0, 0, 255), FILLED);
	}

	imshow("Cards Image", img);
	imshow("King Image", imgWarp1);
	imshow("Queen Image", imgWarp2);
	waitKey(0);
}