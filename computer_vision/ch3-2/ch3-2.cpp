#include "opencv2\opencv.hpp"
#include <iostream>
#include <opencv2/imgcodecs.hpp> //imwrite()

using namespace std;
using namespace cv;
void blurUser(Mat src, Mat& dst, int ksize);
void medianBlurUser(Mat src, Mat& dst, int ksize);


int main()
{
	//Mat 클래스 간단 실습
	/*int data1[] = {
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
	*/

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
	/*
	Mat_<int> m1_(3, 2);
	Mat_<float> m2_(2, 3);
	m1_ << 1, 1, 2, 2, 3, 3;
	m2_ << 0.1, 5.1, -0.2, 0.1, 4.1, -0.3;

	cout << "m1 = " << endl << m1_ << endl;
	cout << "m2 = " << endl << m2_ << endl;
	*/
	
	/*Mat m1(2, 2, CV_8UC3);
	Mat m2(2, 2, CV_8UC3);
	Mat m3(2, 2, CV_8UC3);
	Mat m4(2, 2, CV_8UC3);
	Mat m5(2, 2, CV_8UC3);
	Mat m6(2, 2, CV_8UC3);
	
	m1 = 255;
	m2 = Scalar(255, 0, 0);
	m3 = Scalar(255, 255, 255);
	m4.setTo(255);
	m5.setTo(Scalar(255, 0, 0));
	m6.setTo(Scalar(255, 255, 255));

	cout << m1 << endl;
	cout << m2 << endl;
	cout << m3 << endl;
	cout << m4 << endl;
	cout << m5 << endl;
	cout << m6 << endl;
	*/

	/*
	Mat img1 = imread("dog.bmp");

	Mat img2 = img1;
	Mat img3;
	img3 = img1;

	Mat img4 = img1.clone();
	Mat img5;
	img1.copyTo(img5);

	img1.setTo(Scalar(0, 255, 255)); //노랑

	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);
	imshow("img4", img4);
	imshow("img5", img5);

	waitKey();
	destroyAllWindows();
	*/

	/*
	Mat m1(10, 15, CV_32SC1, Scalar(100));
	Mat s1 = m1(Rect(3, 1, 5, 4));
	Mat s2 = m1(Rect(8, 5, 5, 4));
	Mat s3 = m1(Rect(6, 3, 5, 4));

	s1 = Scalar(200);
	s2 = Scalar(300);
	s3 = Scalar(555);

	cout << m1 << endl;
	*/

	/*
	Mat m1(200, 300, CV_8UC1, Scalar(0));
	for (int j = 50; j < 150; j++) {
		for (int i = 0; i < m1.cols; i++)
			m1.at<uchar>(j, i) = 255;
	}

	//imshow("img", m1);
	//waitKey();

	imwrite("test.jpg", m1);
	*/
	/*
	Mat m2(200, 300, CV_8UC3, Scalar(0, 0, 0));

	for (int j = 50; j < 150; j++) {
		for (int i = 0; i < m2.cols; i++)
			m2.at<Vec3b>(j, i) = Vec3b(0, 255, 0);
	}

	imshow("img", m2);
	waitKey();
	*/
	/*
	Mat img;
	img = imread("read_gray.jpg", IMREAD_GRAYSCALE);
	Point2i pt;

	for (int j = 1; j < img.rows - 1; j++) {
		for (int i = 1; i < img.cols - 1; i++) {
			if (img.at<uchar>(j, i) == 175)
				if (img.at<uchar>(j - 1, i) == 255)
					if (img.at<uchar>(j + 1, i) == 223)
						if (img.at<uchar>(j, i + 1) == 254)
							if (img.at<uchar>(j, i - 1) == 244) {
								pt.x = i;
								pt.y = j;
							}
		}
	}

	cout << pt << endl;
	//(165,155)
	*/
	/*
	float A[] = { 2,1,1,4,-6,0,-2,7,2 };
	float B[] = { 3,10,-5 };

	Mat mA(3, 3, CV_32FC1, A);
	Mat mB(3, 1, CV_32FC1, B);
	Mat result;

	Mat inv_mA = mA.inv();
	result = inv_mA * mB;

	cout << result << endl;
	*/
	
/*
	Mat img1 = imread("cat.bmp");

	if (img1.empty()) {
		cerr << "image load failed" << endl;
		return 0;
	}

	Mat img2 = img1.clone();
	Mat ROI = img2(Rect(220, 120, 340, 240));

	ROI.setTo(Scalar(255, 255, 255));

	addWeighted(img1, 0.5, img2, 0.5, 0, img1);

	imshow("img1", img1);
	imshow("img2", img2);

	waitKey();
	destroyAllWindows();
	*/

	//ch3-3 reshape
	
/*
	Mat m1(2, 6, CV_8U, Scalar(0,0,0));
	Mat m2 = m1.reshape(2);
	Mat m3 = m1.reshape(3, 2);

	m1 = 1;
	cout << endl << "m1=1" << endl;
	cout << "m1=" << endl << m1 << endl;
	cout << "m2=" << endl << m2 << endl;
	cout << "m3=" << endl << m3 << endl;

	m2 = 2;
	cout << endl << "m2=2" << endl;
	cout << "m1=" << endl << m1 << endl;
	cout << "m2=" << endl << m2 << endl;
	cout << "m3=" << endl << m3 << endl;

	m3 = 3;
	cout << endl << "m3=3" << endl;
	cout << "m1=" << endl << m1 << endl;
	cout << "m2=" << endl << m2 << endl;
	cout << "m3=" << endl << m3 << endl;
	cout << m3.cols << endl;
	*/
/*
	Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));
	circle(img, Point(100, 100), 100, Scalar(0, 255, 0), -1);
	circle(img, Point(300, 100), 100, Scalar(0, 255, 0), -1);
	circle(img, Point(100, 300), 100, Scalar(0, 255, 0), -1);
	circle(img, Point(300, 300), 100, Scalar(0, 255, 0), -1);

	vector<Point> pts;
	pts.push_back(Point(200, 100));
	pts.push_back(Point(300, 200));
	pts.push_back(Point(300, 300));
	pts.push_back(Point(100, 300));
	pts.push_back(Point(100, 200));

	polylines(img, pts, true, Scalar(0, 0, 255), 2);

	imshow("img", img);
	waitKey(0);

	destroyAllWindows();
	*/

	/*
	Mat img(200, 600, CV_8UC3, Scalar(255, 255, 255));
	const String s = "skku";
	const String c = "comedu";
	int fontFace = FONT_HERSHEY_SIMPLEX;
	double fontScale = 2.0;
	int thickness = 1;

	Size s_sizeText = getTextSize(s, fontFace, fontScale, thickness, 0);
	Size c_sizeText = getTextSize(c, fontFace, fontScale, thickness, 0);
	Size sizeImg = img.size();
	
	Point s_org(0, sizeImg.height - 1);
	Point c_org(sizeImg.width - 1 - c_sizeText.width, sizeImg.height - 1);

	rectangle(img, s_org, s_org + Point(s_sizeText.width, -s_sizeText.height), Scalar(255, 0, 0), -1);
	putText(img, s, s_org, fontFace, fontScale, Scalar(255, 255, 255), thickness);

	rectangle(img, s_org + Point(s_sizeText.width, 0), c_org + Point(0, -c_sizeText.height), Scalar(0, 0, 255), -1);
	
	rectangle(img, c_org, c_org + Point(c_sizeText.width, -c_sizeText.height), Scalar(255, 0, 0), -1);
	putText(img, c, c_org, fontFace, fontScale, Scalar(255, 255, 255), thickness);
	
	imshow("img", img);
	waitKey(0);
	*/
/*
	Mat img;
	Mat img2 = imread("lenna.bmp");
	int fontFace = FONT_HERSHEY_SIMPLEX;
	double fontScale = 2.0;
	int thickness = 1;
	string ckey = "";

	while (1)
	{
		img = img2.clone();
		int key = waitKey();
		if (key == 27)
		{
			break;
		}
		else if (key >= 'a' && key <= 'z')
		{
			ckey = (char)key;
		}
		putText(img, ckey, Point(img.cols / 2 - 1, img.rows / 2 - 1), fontFace, fontScale, Scalar(255, 255, 255), thickness);
		imshow("img", img);
	}
	destroyAllWindows();
	*/
/*
	Mat img1 = imread("lenna.bmp",IMREAD_GRAYSCALE);
	img1.convertTo(img1, CV_32SC1);
	//Mat img2(img1.rows, img1.cols, CV_32SC1);

	Mat img2 = img1 + 100;
	Mat img3 = img2 - 100;
	img3.convertTo(img3, CV_8UC1);
	img1.convertTo(img1, CV_8UC1);
	img2.convertTo(img2, CV_8UC1);
	*/

/*
	Mat m1 = imread("lenna.bmp", IMREAD_COLOR);
	Mat m2 = m1.clone();
	Mat test = m1 / Scalar(2, 1, 1);

	for (int j = 0; j < m2.rows; j++) {
		for (int i = 0; i < m2.cols; i++) {
			//m2.at<Vec3b>(j, i)[0] = m2.at<Vec3b>(j, i)[0] / 2;
			//m2.at<Vec3b>(j, i)[1] = m2.at<Vec3b>(j, i)[1];
			//m2.at<Vec3b>(j, i)[2] = m2.at<Vec3b>(j, i)[2];

			if (i % 3 == 0)
				m2.at<Vec3b>(j, i)[0] /= 2;
		}
	}

	imshow("m1", m1);
	imshow("m2", m2);
	imshow("test", test);
	
	waitKey(0);
	destroyAllWindows();
	*/
/*
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	Mat dst;
	Mat mask(3, 3, CV_32FC1, Scalar(1));

	filter2D(src, dst, -1, mask);

	imshow("dest", dst);
	waitKey();
	destroyAllWindows();
	*/
/*
	Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);
	Mat blur, unsharp1, unsharp2, unsharp3;

	blurUser(img, blur, 5);

	unsharp1 = (1 + 1) * img - 1 * blur;
	unsharp2 = (1 + 2) * img - 2 * blur;
	unsharp3 = (1 + 3) * img - 3 * blur;

	imshow("img", img);
	//imshow("blur", blur);
	imshow("unsharp1", unsharp1);
	imshow("unsharp2", unsharp2);
	imshow("unsharp3", unsharp3);

	waitKey();
	destroyAllWindows();
	*/
	Mat src = imread("lenna_noise.bmp", IMREAD_GRAYSCALE);
	Mat dst;

	medianBlurUser(src, dst, 3);

	imshow("src", src);
	imshow("dst", dst);

	waitKey();
	destroyAllWindows();

	return 0;
}

void medianBlurUser(Mat src, Mat& dst, int ksize)
{
	int p = ksize / 2;
	int tsize = ksize * ksize;

	dst = src.clone();

	for (int r = p; r < src.rows - p; r++) {
		for (int c = p; c < src.cols - p; c++) {
			vector<uchar> vec{};
			for (int u = -p; u <= p; u++) {
				for (int v = -p; v <= p; v++) {
					vec.push_back(src.at<uchar>(r + u, c + v));
				}
			}
			sort(vec.begin(), vec.end());
			int center = vec.size() / 2;
			dst.at<uchar>(r, c) = (uchar)vec[center];
		}
	}

}

void blurUser(Mat src, Mat& dst, int ksize)
{
	int p = ksize / 2;
	int tsize = ksize * ksize;

	dst = src.clone();

	for (int r = p; r < src.rows - p; r++) {
		for (int c = p; c < src.cols - p; c++) {
			int sum = 0;

			for (int u = -p; u <= p; u++) {
				for (int v = -p; v <= p; v++) {
					sum += src.at<uchar>(r + u, c + v);
				}
			}
			
			dst.at<uchar>(r, c) = (uchar)((float)sum / tsize + 0.5);
		}
	}

}