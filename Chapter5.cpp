#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>

using namespace std;
using namespace cv;

///////////////// Warp Images ////////////////////
/*
Step1: Select src, dest points
Step2: Get Perspective Transformation matrix
Step3: Apply Warp Perspective
Step4: Plot points on the original image to show the selected points
Step5: Display the Original Image, Wrapped Images
*/

float w = 250, h = 350;			// resolution of Warp Image/Window
Mat matrix1, matrix2, imgWarp1, imgWarp2;

void main() {
	string path = "Resources/cards.jpg";
	Mat img = imread(path);

	// ---------------------------  King ---------------------------  //
	Point2f src1[4] = { {529, 143}, {772, 192}, {405, 392}, {675, 456} };	// Point2f mean float point, order is a[0, 0], a[0, 1], a[1, 0], a[1, 2]
	Point2f dst1[4] = { {0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h} };		// location of points in Warp Image
	
	matrix1 = getPerspectiveTransform(src1, dst1);
	warpPerspective(img, imgWarp1, matrix1, Size(w, h));
	
	for (int i = 0; i < 4; i++) {
		circle(img, Point(src1[i]), 5, Scalar(0, 0, 255), FILLED);
	}

	// ---------------------------  Queen ---------------------------  //
	Point2f src2[4] = { {63, 325}, {338, 278}, {92, 635}, {404, 572} };
	Point2f dst2[4] = { {0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h} };

	matrix2 = getPerspectiveTransform(src2, dst2);
	warpPerspective(img, imgWarp2, matrix2, Size(w, h));

	for (int i = 0; i < 4; i++) {
		circle(img, Point(src2[i]), 5, Scalar(0, 0, 255), FILLED);
	}

	// --------------------------- Display ---------------------------  //

	imshow("Cards Image", img);
	imshow("King Image", imgWarp1);
	imshow("Queen Image", imgWarp2);
	waitKey(0);
}
