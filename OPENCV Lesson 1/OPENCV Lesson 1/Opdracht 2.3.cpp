#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void main() {

	string path = "Resources/ballstripes.png";
	Mat img = imread(path);
	Mat imgBW, imgCanny, imgErosion, kernel, imgOpening;
	cvtColor(img, imgBW, COLOR_BGR2GRAY);
	threshold(imgBW, imgCanny, 127, 255, THRESH_BINARY);

	kernel = getStructuringElement(MORPH_RECT, Size(30, 30));	
	dilate(imgCanny, imgErosion, kernel);
	erode( imgErosion, imgOpening, kernel);




	while (true) {
		imshow("Image", img);
		imshow("Image HSV", imgErosion);
		imshow("Image Mask", kernel);
		waitKey(1);
	}
	
}