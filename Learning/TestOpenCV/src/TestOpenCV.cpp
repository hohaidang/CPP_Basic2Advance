//============================================================================
// Name        : TestOpenCV.cpp
// Author      : Dang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
	Mat img = imread("lena.jpg");
	namedWindow("image", WINDOW_NORMAL);
	imshow("image", img);
	waitKey(0);
	return 0;
}
