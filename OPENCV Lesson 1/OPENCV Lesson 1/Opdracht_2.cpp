#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/////////////////  Images  //////////////////////

void main() {
	// Loading in the image
	string path = "Resources/duck.png";
	Mat raw_img = imread(path);
	Mat small_img, crop_img;

	// Resize image
	resize(raw_img, small_img, Size(), 0.5, 0.5);

	// Cropping image
	Rect roi(400, 300, 400, 200);
	crop_img = raw_img(roi);

	// Drawing image
	imshow("Image", raw_img);
	imshow("Image Resize", small_img);
	imshow("Image Crop", crop_img);

	waitKey(0);

}
