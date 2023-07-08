///////////////// Face Detection using Viola-Jones Algorithm //////////////////////
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void main() {
	Mat img = imread("Resources/test.png");

	// object of class CascadeClassifier
	CascadeClassifier faceCascade;

	// pre-trained model
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");

	if (faceCascade.empty()) { cout<< "Cascade Classifier not loaded!" << endl; }

	vector<Rect> faces;

	faceCascade.detectMultiScale(img, faces);

	for (int i = 0; i < faces.size(); i++) {
		// faces[i].tl() -> top left corner, faces[i].br() -> bottom right corner
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 255, 0), 3);
	}

	imshow("Image", img);
	waitKey(0);
}
