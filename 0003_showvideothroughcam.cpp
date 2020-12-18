#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

void cam() {
	VideoCapture cap(0); // VideoCapture 객체를 생성하고, 컴퓨터에 연결된 기본 카메라를 사용하도록 설정한다.

	if (!cap.isOpened()) { // 만약 카메라 장치가 성공적으로 열리지 않았다면
		cerr << "Camera open failed!" << endl; // 에러 메시지를 출력하고
		return; // 함수를 종료한다.
	}

	Mat frame, inversed;

	while (true) {
		cap >> frame; // 카메라 장치로부터 한 프레임을 받아 와서 frame 변수에 저장한다.
		if (frame.empty())
			break;

		inversed = ~frame; // 현재 프레임을 반전하여 inversed 변수에 저장한다.

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(10) == 27) // 10ms 시간 동안 키보드 입력을 대기한다. 만약 Esc 키를 누르면 break한다.
			break;
	}

	destroyAllWindows(); // 모든 창을 닫는다.
}

int main() {
	cam();
}
