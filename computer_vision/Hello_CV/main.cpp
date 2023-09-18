#include "opencv2\opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	//std::cout << "Hello OpenCV " << CV_VERSION << std::endl;
	cout << "Hello OpenCV " << CV_VERSION << endl;

	//cv::Mat img;
	Mat img;
	img = imread("lenna.bmp");

	if (img.empty()) {
		cerr << "image load failed" << endl;
		return -1;
	}

	namedWindow("image", WINDOW_NORMAL);
	imshow("lenna", img);

	waitKey();

	return 0;
}