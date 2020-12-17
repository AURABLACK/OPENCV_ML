#include "opencv2/opencv.hpp" // OpenCV에서 사용하는 다양한 클래스와 함수가 선언되어 있는 opencv.hpp 헤더 파일을 include한다.
#include <iostream> // C++ 표준 출력을 위해 iostream 헤더 파일을 include
using namespace std;
using namespace cv;

int main() {
	Mat img; // Mat 클래스 타입의 변수 img 선언한다.
	img = imread("C:\\Users\\kkscc\\Desktop\\A.bmp"); // A.bmp 파일을 불러와 img 변수에 저장한다. _ image read
	
	if (img.empty()) { // A.bmp 파일을 제대로 불러오지 못했을 경우에 대한 예외 처리 코드
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("image"); // 영상을 화면에 나타내기 위한 새로운 창을 생성하고 그 창에 "image"라는 이름을 부여한다.
	imshow("image", img); // "image"라는 이름의 창에 img 객체가 가지고 있는 A.bmp 이미지를 출력한다. _ image show

	waitKey(); // 사용자의 키보드 입력을 기다리는 함수이며 사용자가 키보드를 누르기 전까지 영상을 화면에 나타나게 한다.
	return 0;
}
