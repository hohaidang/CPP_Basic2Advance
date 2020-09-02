#include<opencv2/opencv.hpp>
#include<iostream>
#include <opencv\cv.h>
#include <opencv\highgui.h>
using namespace std;
using namespace cv;

int temp() {
	float angle = 0;
	Mat image(400, 400, CV_8UC3, Scalar(0));
	vector<Point2f> vertVect;
	RotatedRect calculatedRect;

	while (1) {
		vertVect.push_back(Point2f(91.8751, 151.739));
		vertVect.push_back(Point2f(84.3488, 128.722));
		vertVect.push_back(Point2f(192.586, 93.3297));
		vertVect.push_back(Point2f(200.113, 116.346));

		// Get minAreaRect to find a rectangle that encloses the points. This
		// should have the exact same orientation as our original rectangle.
		calculatedRect = minAreaRect(vertVect);

		// Draw the original rectangle, and the one given by minAreaRect.
		for (int i = 0; i < 4; i++) {
			line(image, vertVect[i], vertVect[(i + 1) % 4], Scalar(255, 0, 0));
		}
		imshow("rectangles", image);
		for (unsigned i = 0; i < vertVect.size(); i++)
		{
			Point2f point = vertVect.at(i);
			//point.x -= 200;
			cout << "Point[" << i << "] = " << point << endl;
		}
		cout << "width = " << calculatedRect.size.width << endl;
		cout << "height = " << calculatedRect.size.height << endl;
		printf("Angle given by minAreaRect: %7.2f\n", calculatedRect.angle);

		waitKey();
	}
	system("pause");
	return 0;
}