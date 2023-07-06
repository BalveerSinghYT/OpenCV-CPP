#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/**
 * This function extracts contours from a binary image and performs shape detection on the contours.
 *
 * @param imgDil Binary image after dilation
 * @param img Original image
 */
void getContours(Mat imgDil, Mat img) {

	// Containers for contours and hierarchy
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	// Find contours in the binary image
	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	// Vector to store approximated polygons and bounding rectangles for contours
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		// Calculate the area of the contour
		int area = contourArea(contours[i]);
		cout << "Contour Area: " << area << endl;
		string objectType;

		// Process only if the contour area is larger than a threshold (1000 in this case)
		if (area > 1000)
		{
			// Calculate the perimeter of the contour
			float peri = arcLength(contours[i], true);

			// Approximate the contour with a polygon
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			cout << "Polygon Size: " << conPoly[i].size() << endl;

			// Calculate the bounding rectangle for the polygon
			boundRect[i] = boundingRect(conPoly[i]);

			// Determine the number of corners of the polygon
			int objCor = (int)conPoly[i].size();

			// Classify the shape based on the number of corners
			if (objCor == 3) { objectType = "Tri"; }
			else if (objCor == 4)
			{
				// Calculate the aspect ratio of the bounding rectangle
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				cout << "Aspect Ratio: " << aspRatio << endl;

				// Classify the shape as a square or rectangle based on the aspect ratio
				if (aspRatio > 0.95 && aspRatio < 1.05) { objectType = "Square"; }
				else { objectType = "Rect"; }
			}
			else if (objCor > 4) { objectType = "Circle"; }

			// Draw the contour and bounding rectangle on the original image
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			putText(img, objectType, { boundRect[i].x,boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 2);
			cout << endl;
		}
	}
}

int main() {

	string path = "Resources/shapes.png";

	// Load the image
	Mat img = imread(path);

	// Preprocessing
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	// Perform shape detection on the contours
	getContours(imgDil, img);

	// Display the original image with detected shapes
	imshow("Image", img);

	waitKey(0);
	return 0;
}
