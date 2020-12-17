#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

Mat img;
Point pt;
void on_mouse(int event, int x, int y, int flags, void*); // 마우스 이벤트 처리 함수

int main() {
	img = imread("C:\\Users\\kkscc\\Desktop\\A.bmp");

	if (img.empty()) {
		cerr << "Image load failed!" << endl;
		return 0;
	}

	namedWindow("img");
	setMouseCallback("img", on_mouse); // "img" 창에서 마우스 이벤트가 발생하면 on_mouse 함수가 자동으로 호출되도록 한다.

	imshow("img", img);
	waitKey(0);

	return 0;
}

void on_mouse(int event, int x, int y, int flags, void*) { // 마우스 이벤트 처리 함수
	switch (event) { // 이벤트에 따라 스위치
	case EVENT_LBUTTONDOWN: // 마우스 왼쪽 버튼이 눌리면
		pt = Point(x, y);
		cout << "EVENT_LBUTTONDOWN: " << x << ", " << y << endl; // 눌린 좌표 출력
		break;
	case EVENT_LBUTTONUP: // 눌렸던 마우스 왼쪽 버튼이 떼어지면
		cout << "EVENT_LBUTTONUP: " << x << ", " << y << endl; // 좌표 출력
		break;
	case EVENT_MOUSEMOVE: // 마우스가 움직이면
		if (flags & EVENT_FLAG_LBUTTON) { // 마우스 왼쪽 버튼이 눌러진 상태에서
			line(img, pt, Point(x, y), Scalar(0, 255, 255), 2); // img 영상에 선을 그린다.
			imshow("img", img); // 선이 그려진 img를 보여준다.
			pt = Point(x, y);
		}
		break;
	default:
		break;
	}
}
