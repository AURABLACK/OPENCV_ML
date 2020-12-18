#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

String fileway = "C:\\Users\\kkscc\\Desktop\\"; // 파일 경로 설정

int main() {
	Mat src = imread(fileway + "lenna.bmp", IMREAD_COLOR);
	Mat mask = imread(fileway + "mask_smile.bmp", IMREAD_GRAYSCALE);

	if (src.empty() || mask.empty()) {
		cerr << "Image load failed!" << endl;
		return 0;
	}

	src.setTo(Scalar(0, 255, 255), mask); // mask 영상에서 픽셀 값이 0이 아닌 위치에서만 src 영상 픽셀을 노란색으로 설정한다.

	imshow("src", src);
	imshow("mask", mask);

	waitKey(0);
	destroyAllWindows();
}
