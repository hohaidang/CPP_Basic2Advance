#include<opencv2/opencv.hpp>
#include<iostream>
#include <opencv\cv.h>
#include <opencv\highgui.h>
using namespace std;
using namespace cv;

void printAngle(RotatedRect calculatedRect) {
	if (calculatedRect.size.width < calculatedRect.size.height) {
		printf("Angle along longer side: %7.2f\n", calculatedRect.angle + 180);
	}
	else {
		printf("Angle along longer side: %7.2f\n", calculatedRect.angle + 90);
	}
}

int main() {
	float angle = 0;
	Mat image(200, 400, CV_8UC3, Scalar(0));
	RotatedRect originalRect;
	Point2f vertices[4];
	vector<Point2f> vertVect;
	RotatedRect calculatedRect;

	while (1) {
		// Create a rectangle, rotating it by 10 degrees more each time.
		originalRect = RotatedRect(Point2f(100, 100), Size2f(15, 100), angle);

		// Convert the rectangle to a vector of points for minAreaRect to use.
		// Also move the points to the right, so that the two rectangles aren't
		// in the same place.
		originalRect.points(vertices);
		for (int i = 0; i < 4; i++) {
			vertVect.push_back(vertices[i] + Point2f(200, 0));
		}

		// Get minAreaRect to find a rectangle that encloses the points. This
		// should have the exact same orientation as our original rectangle.
		calculatedRect = minAreaRect(vertVect);

		// Draw the original rectangle, and the one given by minAreaRect.
		for (int i = 0; i < 4; i++) {
			line(image, vertices[i], vertices[(i + 1) % 4], Scalar(0, 255, 0));
			line(image, vertVect[i], vertVect[(i + 1) % 4], Scalar(255, 0, 0));
		}
		imshow("rectangles", image);

		// Print the angle values.
		printf("---\n");
		printf("Original angle: %7.2f\n", angle);
		printf("Original Width: %7.2f\n", originalRect.size.width);
		printf("Original Height: %7.2f\n", originalRect.size.height);
		printf("minAreaRect angle: %7.2f\n", calculatedRect.angle);
		printf("minAreaRect Width: %7.2f\n", calculatedRect.size.width);
		printf("minAreaRect Height: %7.2f\n", calculatedRect.size.height);
		//printf("Angle given by minAreaRect: %7.2f\n", calculatedRect.angle);
		printf("---\n");

		// Reset everything for the next frame.
		image = Mat(200, 400, CV_8UC3, Scalar(0));
		vertVect.clear();
		angle -= 10;
		waitKey();
	}
	system("pause");
	return 0;
}