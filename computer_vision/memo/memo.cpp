#include "opencv2\opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void blurUser(Mat src, Mat& dst, int ksize)
{
	//패딩 없는 걸 기준, f(0,-1)에 접근 못함
	dst = src.clone();
	int p = ksize / 2;

	for (int y = p; y < src.rows - p; y++) {
		for (int x = p; x < src.cols - p; x++) {
			int sum = 0;
			for (int j = -p; j <= p; j++) {
				for (int i = -p; i <= p; i++) {
					sum += src.at<uchar>(y + j, x + i);
				}
			}
			/*
			for (int j = 0; j < ksize; j++) {
				for (int i = 0; i < ksize; i++) {
					sum += src.at<uchar>(y + j - ksize / 2, x + i - ksize / 2);
				}
			}
			*/
			dst.at<uchar>(y, x) = (uchar)((float)sum / (ksize * ksize) + 0.5);
		}
	}
}
void medianBlurUser(Mat src, Mat& dst, int ksize)
{
	int p = ksize / 2;
	dst = src.clone();

	for (int r = p; r < src.rows - p; r++) {
		for (int c = p; c < src.cols - p; c++) {
			vector<uchar> vec{};
			for (int j = -p; j <= p; j++) {
				for (int i = -p; i <= p; i++) {
					vec.push_back(src.at<uchar>(r + j, c + i));
				}
			}
			sort(vec.begin(), vec.end());
			dst.at<uchar>(r, c) = (uchar)vec[vec.size() / 2];
		}
	}
}
int main()
{
	Mat src = imread("lenna_noise.bmp", IMREAD_GRAYSCALE);
	Mat dst;

	medianBlurUser(src, dst, 3);
	imshow("src", src);
	imshow("dst", dst);
	/*
	Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);
	Mat blur, usharp1, usharp2, usharp3;

	blurUser(img, blur, 3);
	int alpha = 1;
	usharp1 = (1 + alpha) * img - (alpha * blur);
	alpha++;
	usharp2 = (1 + alpha) * img - (alpha * blur);
	alpha++;
	usharp3 = (1 + alpha) * img - (alpha * blur);

	imshow("img", img);

	imshow("unsharp1", usharp1);
	imshow("unsharp2", usharp2);
	imshow("unsharp3", usharp3);
	//imshow("blur", blur);
	*/
	waitKey();
	return 0;
}
/*
	//ch3-1 마지막 RotatedRect 그리기
	Mat image(300, 500, CV_8UC1, Scalar(255));
	Point p(250, 150);
	Size2f size(200, 20);

	Rect R(p - Point(100, 10), size);
	RotatedRect R1(p, size, 45.f);
	RotatedRect R2(p, size, 90.f);
	RotatedRect R3(p, size, 135.f);

	rectangle(image, R, Scalar(0), 3);

	Point2f pts[3][4];
	R1.points(pts[0]);
	R2.points(pts[1]);
	R3.points(pts[2]);
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 4; i++) {
			line(image, pts[j][i], pts[j][(i + 1) % 4], Scalar(0), 3);
		}
}

	imshow("test", image);
	waitKey();
*/
	//ch3-3 8p
	//unsigned char* p = m1.ptr<uchar>(i + 50);

/*
	//ch3-3 reshape, resize 관련
	Mat img1 = imread("lenna.bmp", IMREAD_GRAYSCALE);
	Mat img1f;
	img1.convertTo(img1f, CV_32FC1);
	//cout << img1.elemSize1() << endl;
	//cout << img1f.elemSize1() << endl;
	uchar data1[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	Mat mat1(3, 4, CV_8UC1, data1);
	Mat mat2 = mat1.reshape(0, 1);

	cout << mat1 << endl << mat2 << endl;

	Mat mat3 = Mat::ones(1, 4, CV_8UC1) * 255;
	mat1.push_back(mat3);
	cout << mat1 << endl;

	mat1.resize(6, 100);
	cout << mat1 << endl;
	*/

	/*
		//ch4 puttext
		Mat img(200, 640, CV_8UC3, Scalar(255, 255, 255));

		const String text = "Hello OpenCV";
		int fontFace = FONT_HERSHEY_COMPLEX;
		double fontScale = 2.0;
		int thickness = 1;

		Size sizeText = getTextSize(text, fontFace, fontScale, thickness, 0);
		Size sizeImg = img.size();

		Point org((sizeImg.width - sizeText.width) / 2, (sizeImg.height + sizeText.height) / 2);

		putText(img, text, org, fontFace, fontScale, Scalar(255, 0, 0), thickness);
		rectangle(img, Rect(org + Point(0, -sizeText.height), Size(sizeText.width, sizeText.height)), Scalar(255, 0, 0), thickness);

		imshow("img", img);
		waitKey();
		*/
/*
	//ch5 waitkey 실습, clone()함수 사용
	Mat img = imread("lenna.bmp");
	imshow("img", img);
	while (true) {
		int input = waitKey();
		if (input == 27)
			break;
		else if (input >= 'a' && input <= 'z') {
			Mat img2 = img.clone();
			char tmp = (char)input;
			int fontFace = FONT_HERSHEY_SCRIPT_COMPLEX;
			double fontScale = 3.0;
			int thickness = 2;
			Size tbox = getTextSize(&tmp, fontFace, fontScale, thickness, 0);
			Point org((img.cols - tbox.width) / 2, (img.rows + tbox.height) / 2);
			putText(img2, &tmp, org, fontFace, fontScale, Scalar(255, 0, 0), thickness);
			imshow("img", img2);
		}
	}
	destroyAllWindows();
	*/
	/*
		//ch5 waitkey 실습, clone()함수 사용
		Mat img = imread("lenna.bmp");
		imshow("img", img);
		while (true) {
			int input = waitKey();
			if (input == 27)
				break;
			else if (input >= 'a' && input <= 'z') {
				Mat img2 = img.clone();
				char tmp = (char)input;
				int fontFace = FONT_HERSHEY_SCRIPT_COMPLEX;
				double fontScale = 3.0;
				int thickness = 2;
				Size tbox = getTextSize(&tmp, fontFace, fontScale, thickness, 0);
				Point org((img.cols - tbox.width) / 2, (img.rows + tbox.height) / 2);
				putText(img2, &tmp, org, fontFace, fontScale, Scalar(255, 0, 0), thickness);
				imshow("img", img2);
			}
		}
		destroyAllWindows();
	*/
	/*
		//ch5 11p 영상 밝기 조절
	Mat img = imread("lenna.bmp", IMREAD_COLOR);
	if (img.empty()) {
		cerr << "image load failed" << endl;
		return 0;
	}
	Mat src;
	cvtColor(img, src, COLOR_BGR2GRAY);
	Mat dst(src.rows, src.cols, src.type());
	//Mat dst;
	for (int j = 0; j < dst.rows; j++) {
		for (int i = 0; i < dst.cols; i++) {
			dst.at<uchar>(j, i) = saturate_cast<uchar>(src.at<uchar>(j, i) + 100);
			/*
			//dst.at<uchar>(j, i) = src.at<uchar>(j, i) + 100;
			int v = src.at<uchar>(j, i) + 100;
			//dst.at<uchar>(j, i) = v > 255 ? 255 : v < 0 ? 0 : v;
			if (v > 255)
				dst.at<uchar>(j, i) = 255;
			else if (v < 0)
				dst.at<uchar>(j, i) = 0;
			else
				dst.at<uchar>(j, i) = v;
				*//*
		}
	}

	imshow("src", src);
	imshow("dst", dst);
	waitKey();
	destroyAllWindows();
		*/
/*
//ch4 21p 화소처리 형변환
	Mat img1 = imread("lenna.bmp", IMREAD_GRAYSCALE);
	Mat m2(img1.rows, img1.cols, CV_32SC1);
	m2 = img1 + 100;
	Mat m3 = m2 - 100;
	cout << img1.elemSize1() << endl << m2.elemSize1() << endl << m3.elemSize1() << endl;
	imshow("img1", img1);
	imshow("img2", m2);
	imshow("img3", m3);

	waitKey();

	img1.convertTo(img1, CV_32SC1);
	Mat img2 = img1 + 100;
	Mat img3 = img2 - 100;

	cout << img1.elemSize1() << endl << img2.elemSize1() << endl << img3.elemSize1() << endl;
	img1.convertTo(img1, CV_8UC1);
	img2.convertTo(img2, CV_8UC1);
	img3.convertTo(img3, CV_8UC1);
	cout << img1.elemSize1() << endl << img2.elemSize1() << endl << img3.elemSize1() << endl;
	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);

	waitKey();
*/
/*
	//ch5 22p 컬러 영상 화소 처리
	Mat img = imread("lenna.bmp", IMREAD_COLOR);
	Mat origin = img.clone();
	for (int j = 0; j < img.rows; j++) {
		for (int i = 0; i < img.cols; i++) {
			img.at<Vec<uchar, 3>>(j, i)[0] /= 2;
		}
	}
	Mat m1(5, 5, CV_8UC3, Scalar(128, 128, 128));
	Mat m2;
	m1.copyTo(m2);
	for (int j = 0; j < m1.rows; j++) {
		for (int i = 0; i < m1.rows; i++) {
			m1.at<Vec3b>(j, i)[0] /= 2;
		}
	}
	cout << "m1=" << endl << m1 << endl << "m2=" << endl << m2 << endl;
	Mat test = origin / Scalar(2, 1, 1);
	imshow("test", test);

	imshow("origin", origin);
	imshow("img", img);

	waitKey();
	*/
	/*
		//ch5 35p 명암비 조절
		Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

		float s = 2.f;
		//Mat dst = s * src;

		float alpha = 1.f;
		int sum = 0;
		for (int j = 0; j < src.rows; j++) {
			for (int i = 0; i < src.cols; i++) {
				sum += src.at<uchar>(j, i);
			}
		}
		int avg = sum / (src.rows * src.cols);

		Mat dst = src + (src - avg) * alpha;
		Mat test = src + (src - 128) * alpha;
		cout << avg << endl;

		imshow("src", src);
		imshow("dst", dst);
		imshow("test", test);

		waitKey();
		*/
		/*
			//ch7 15p filter2D함수를 이용한 blur
			Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);
			Mat blur;
			Mat kernel = Mat::ones(3, 3, CV_32FC1) / 9;
			filter2D(img, blur, -1, kernel);

			imshow("img", img);
			imshow("blur", blur);
			waitKey();
			*/
			/*
				//ch7 23p 평균값 필터
				Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

				if (src.empty()) {
					cerr << "image error" << endl;
					return 0;
				}

				imshow("src", src);
				Mat dst;
				for (int ksize = 3; ksize <= 7; ksize += 2) {
					blur(src, dst, Size(ksize, ksize));

					String desc = format("Mean: %dx%d", ksize, ksize);
					putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
					imshow("dst", dst);
					waitKey();
				}

				destroyAllWindows();
				*/