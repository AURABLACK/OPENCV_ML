#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

string FW = "C:\\Users\\kkscc\\Desktop\\"; // 파일 경로 설정

int main() {
	Mat src = imread(FW + "airplane.bmp", IMREAD_COLOR);
	Mat mask = imread(FW + "mask_plane.bmp", IMREAD_COLOR);
	Mat dst = imread(FW + "field.bmp", IMREAD_COLOR);

	if (src.empty() || mask.empty() || dst.empty()) {
		cerr << "Image load failed!" << endl;
		return 0;
	}

	src.copyTo(dst, mask); // mask 영상에서 흰색 영역 위치에서만 src 영상 픽셀 값을 dst로 복사한다.

	imshow("src", src);
	imshow("mask", mask);
	imshow("dst", dst);

	waitKey(0);
	destroyAllWindows();
}
