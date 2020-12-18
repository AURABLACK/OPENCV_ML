#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main() {
	VideoCapture cap("C:\\Users\\kkscc\\Desktop\\C.mp4"); // C.mp4 파일을 불러와서 cap 객체를 생성

	if (!cap.isOpened()) { // 동영상 파일이 제대로 열리지 않으면
		cerr << "Video open failed!" << endl; // 에러를 띄우고
		return 0; // 종료한다.
	}
	/*
	동영상 파일을 재생하는 프로그램을 만들 경우
	해당 동영상의 FPS 값을 고려하지 않으면 동영상이 너무 빠르거나 느리게 재생되는 경우가 발생합니다.
	그러므로 동영상을 적절한 속도로 재생하려면 동영상의 FPS 값을 참고해야 한다.
	*/
	double fps = cap.get(CAP_PROP_FPS); // 매 프레임 사이의 시간 간격을 계산한다.
	int delay = cvRound(1000 / fps); // FPS 값으로부터 각 프레임 사이의 시간 간격 delay(밀리초 단위)를 계산한다.

	Mat frame, inversed;

	while (true) {
		cap >> frame;
		if (frame.empty())
			break;

		inversed = ~frame;
		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(delay) == 27) // delay 시간만큼 키 입력을 기다리고, Esc 키가 눌리면 break한다.
			break;
	}
	destroyAllWindows();
}
