

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace cv::ml;
using namespace std;

Ptr<KNearest> train_knn();

int main() {
		Ptr<KNearest> knn = train_knn();
		int correct_count = 0;
		int test_count = 0;

		if (knn.empty()){
			cerr << "Training failed!" << endl;
			return -1;
		}

		for (int i = 0; i < 10; i++) {
			int test_good = 0;
			int each_correct = 0;
			for (int j = 601; j < 801; j += 2) {
				string file_name = "./" + to_string(i) + "/" + to_string(j) + ".jpg";
				Mat test_img, test_img_float, test_img_flatten, res;

				test_img = imread(file_name, IMREAD_GRAYSCALE);
				if (test_img.empty()) {
					cerr << "Image load failed!" << endl;
					return 0;
				}
				else test_good++;
				if (test_good == 100) cout << i << " Testing complete" << endl;
				else if (test_good > 100) cout << "Somethings wrong..." << endl;


				test_img.convertTo(test_img_float, CV_32F);
				test_img_flatten = test_img_float.reshape(1, 1);

				knn->findNearest(test_img_flatten, 3, res);
				if (res.at<float>(0, 0) == i) {
					correct_count++;
					each_correct++;
				}
				test_count++;
			}
			cout << "num of correct : " << each_correct << "   ||   percent: " << (each_correct / (double)test_good) * 100 << endl;
		}
		if (test_count == 1000) cout << "Testing ALL complete" << endl;
		else cout << "Somethings wrong..." << endl;
		cout << "================================================================" << endl;
		cout << "num of correct : " << correct_count << "   ||   percent: " << (correct_count / (double)test_count) * 100 << endl;
		return 0;
}

Ptr<KNearest> train_knn() {

	Mat train_images, train_labels;
	int train_count = 0;

	for (int i = 0; i < 10; i++) {
		int train_good = 0;
		for (int j = 1; j < 401; j++) {
			string file_name = "./" + to_string(i) + "/" + to_string(j) + ".jpg";
			Mat train_img, train_img_float, train_img_flatten;

			train_img = imread(file_name, IMREAD_GRAYSCALE);
			if (train_img.empty()) {
				cerr << "Image load failed!" << endl;
				return 0;
			}
			else train_good++;
			if (train_good == 400) cout << i << " Training complete" << endl;
			else if (train_good > 400) cout << "Somethings wrong..." << endl;

			train_img.convertTo(train_img_float, CV_32F);
			train_img_flatten = train_img_float.reshape(1, 1);

			train_images.push_back(train_img_flatten);
			train_labels.push_back(i);
			train_count++;
		}
	}
	if (train_count == 4000) cout << "Training ALL complete" << endl;
	else cout << "Somethings wrong..." << endl;
	cout << "================================================================" << endl;

	Ptr<KNearest> knn = KNearest::create();
	knn->train(train_images, ROW_SAMPLE, train_labels);

	return knn;
}