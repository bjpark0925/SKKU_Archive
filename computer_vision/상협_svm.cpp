#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace cv::ml;
using namespace std;

Ptr<SVM> training_hog_svm(const HOGDescriptor& hog);

int main() {
	HOGDescriptor hog(Size(50, 50), Size(10, 10), Size(5, 5), Size(5, 5), 9);
	Ptr<SVM> svm = training_hog_svm(hog);
	int correct_count = 0;
	int test_count = 0;

	if (svm.empty()) {
		cerr << "Training failed!" << endl;
		return -1;
	}
	else cout << "Model Complete!\n"<< "================================================================" << endl;
	for (int i = 0; i < 10; i++) {
		int test_good = 0;
		int each_correct = 0;
		for (int j = 601; j < 801; j += 2) {
			string file_name = "./" + to_string(i) + "/" + to_string(j) + ".jpg";
			Mat test_img;

			test_img = imread(file_name, IMREAD_GRAYSCALE);
			if (test_img.empty()) {
				cerr << "Image load failed!" << endl;
				return 0;
			}
			else test_good++;
			if (test_good == 100) cout << i << " Testing complete" << endl;
			else if (test_good > 100) cout << "Somethings wrong..." << endl;

			vector<float> desc;
			hog.compute(test_img, desc);

			Mat desc_mat(desc);
			int res = cvRound(svm->predict(desc_mat.t()));
			if (res == i) {
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


Ptr<SVM> training_hog_svm(const HOGDescriptor& hog) {

	Mat train_hog, train_labels;
	int train_count = 0;

	for (int i = 0; i < 10; i++) {
		int train_good = 0;
		for (int j = 1; j < 401; j++) {
			string file_name = "./" + to_string(i) + "/" + to_string(j) + ".jpg";
			Mat train_img;

			train_img = imread(file_name, IMREAD_GRAYSCALE);
			if (train_img.empty()) {
				cerr << "Image load failed!" << endl;
				return 0;
			}
			else train_good++;
			if (train_good == 400) cout << i << " Training complete" << endl;
			else if (train_good > 400) cout << "Somethings wrong..." << endl;

			vector<float> desc;
			hog.compute(train_img, desc);

			Mat desc_mat(desc);
			train_hog.push_back(desc_mat.t());
			train_labels.push_back(i);
			train_count++;
		}
	}
	if (train_count == 4000) cout << "Training ALL complete" << endl;
	else cout << "Somethings wrong..." << endl;
	cout << "================================================================" << endl;

	Ptr<SVM> svm = SVM::create();
	svm->setType(SVM::Types::C_SVC);
	svm->setKernel(SVM::KernelTypes::RBF);
	svm->trainAuto(train_hog, ROW_SAMPLE, train_labels);
	cout << "C: " << svm->getC() << endl;
	cout << "Gamma: " << svm->getGamma() << endl;
	return svm;
}