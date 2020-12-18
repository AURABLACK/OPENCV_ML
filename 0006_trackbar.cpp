#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

void on_level_change(int pos, void* userdata); // 트랙바 콜백 함수를 선언한다.

int main() {
	Mat img = Mat::zeros(400, 800, CV_8UC1); // 픽셀 값이 0으로 초기화된 400x800 크기의 영상 img를 생성한다.

	namedWindow("image");
	createTrackbar("level", "image", 0, 16, on_level_change, (void*)&img); // 트랙바 이름은 "level", 최대 위치는 16, img 이미지 객체의 주소를 사용자 데이터로 지정한다.
	
	imshow("image", img);
	waitKey(0);

	return 0;
}

void on_level_change(int pos, void* userdata) {
	Mat img = *(Mat*)userdata; // void* 타입의 인자 userdata를 Mat* 타입으로 형변환한 후 img 변수로 참조한다.

	img.setTo(pos * 16); // 트랙바 위치 pos에 16을 곱한 결과를 img 영상의 전체 픽셀 값으로 설정한다.
	imshow("image", img); // 픽셀 값이 설정된 img 영상을 image 창에 출력한다.
}
