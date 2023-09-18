#include "opencv2\opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	//형변환 관련 반올림
	/*cv::Point_<float> pt1(0.1f, 0.1f);
	cv::Point_<float> pt2(0.2f, 0.2f);
	cv::Point_<float> pt3(0.3f, 0.3f);
	cv::Point_<float> pt4(0.4f, 0.4f);
	cv::Point_<float> pt5(0.5f, 0.5f);

	cv::Point ptA1 = pt1 + pt1;
	cv::Point ptA2 = pt2 + pt2;
	cv::Point ptA3 = pt3 + pt3;
	cv::Point ptA4 = pt4 + pt4;
	cv::Point ptA5 = pt5 + pt5;

	std::cout << "ptA1 = " << ptA1 << std::endl;
	std::cout << "ptA2 = " << ptA2 << std::endl;
	std::cout << "ptA3 = " << ptA3 << std::endl;
	std::cout << "ptA4 = " << ptA4 << std::endl;
	std::cout << "ptA5 = " << ptA5 << std::endl;
	*/

	//rect 클래스 예제
	/*Rect rectA(30, 40, 100, 200);
	Rect rectB = rectA + Point(10, 15) + Size(20, 30);
	Rect rectC = rectA & rectB;

	cout << "rectA = " << rectA << endl;
	cout << "rectB = " << rectB << endl;
	cout << "rectC = " << rectC << endl;
	*/

	//사각형 두개 배치 문제
	/*Mat A(100, 200, CV_8UC1, Scalar(0));
	Rect R(90, 40, 20, 20);
	Rect R1, R2;

	Point P1(-60, -10);
	Point P2(40, -10);
	Size S(20, 20);

	R1 = R + S + P1;
	R2 = R + S + P2;


	rectangle(A, R1, Scalar(255));
	rectangle(A, R2, Scalar(255));

	imshow("test", A);
	waitKey(0);
	*/

	//Vec클래스 사칙연산
	/*Vec2i a(3, 2), b(4, 3);
	Vec2i c, d;
	c = a + b;
	d = a - b;

	cout << c << endl;
	cout << d << endl;

	Vec2i a(1, 2), aa;
	Vec2d b(4.0, 3.0), bb;
	aa = a + (Vec2i)b;
	bb = (Vec2d)a - b;
	cout << aa << endl;
	cout << bb << endl;
	*/

	//컬러 rect 그리기
	/*Mat A(100, 200, CV_8UC3, Scalar(255, 255, 255));
	Rect R(90, 40, 20, 20);
	Rect R1, R2, R3;
	Point P(50, 0);

	R1 = R - P;
	R2 = R;
	R3 = R + P;

	rectangle(A, R1, Scalar(0,0,255));
	rectangle(A, R2, Scalar(255,0,0));
	rectangle(A, R3, Scalar(0,255,0));

	imshow("test", A);
	waitKey(0);
	*/

	//Mat 클래스 간단 실습
	int data1[] = {
		500,100,-500,1000,0,
		500,100,-500,2000,0
	};
	float data2[] = {
		0.1f,5.1f,-0.2f,
		0.1f,4.1f,-0.3f,
		0.1f,3.1f,-0.4f
	};

	Mat m1(2, 5, CV_32S, data1);
	Mat m2(3, 3, CV_32F, data2);

	cout << "[m1]= " << endl << m1 << endl;
	cout << "[m2]= " << endl << m2 << endl;
	

	/*
	Mat m1(5, 3, CV_16SC3);
	cout << "차원 수 = " << m1.dims << endl;
	cout << "행 개수 = " << m1.rows << endl;
	cout << "열 개수 = " << m1.cols << endl;
	cout << "행렬 크기 = " << m1.size() << endl << endl;

	cout << "전체 원소 개수 = " << m1.total() << endl;
	cout << "한 원소의 크기 = " << m1.elemSize() << endl;
	cout << "채널당 한 원소의 크기 = " << m1.elemSize1() << endl << endl;

	cout << "타입 = " << m1.type() << endl;
	cout << "타입(채널 수|깊이) = "<<((m1.channels() - 1) << 3) + m1.depth() << endl;
	cout << "깊이 = " << m1.depth() << endl;
	cout << "채널 = " << m1.channels() << endl << endl;

	cout << "step = " << m1.step << endl;
	cout << "step1() = " << m1.step1() << endl;
	*/
	
	//Mat_ 생성
	Mat_<int> m1_(3, 2);
	Mat_<float> m2_(2, 3);
	m1_ << 1, 1, 2, 2, 3, 3;
	m2_ << 0.1, 5.1, -0.2, 0.1, 4.1, -0.3;

	cout << "m1 = " << endl << m1_ << endl;
	cout << "m2 = " << endl << m2_ << endl;

	
	return 0;
}