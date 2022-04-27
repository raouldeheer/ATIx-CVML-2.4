#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

//////////////  Draw Shapes and Text //////////////////////

void main() {

	cv::Scalar pink(255, 0, 255);
	cv::Scalar orange(0, 69, 255);
	cv::Scalar white(255, 255, 255);
	cv::Point leftEar(128, 128);
	cv::Point rightEar(128 + 256, 128);
	const cv::String& text = "Onze CV workshop";

	// Blank Image 
	cv::Mat img(512, 512, CV_8UC3, white);

	circle(img, leftEar, 64, pink, cv::FILLED);
	circle(img, rightEar, 64, pink, cv::FILLED);
	circle(img, cv::Point(256, 256), 155, orange, cv::FILLED);
	rectangle(img, cv::Point(130, 226), cv::Point(382, 286), white, cv::FILLED);
	line(img, cv::Point(130, 296), cv::Point(382, 296), white, 2);

	putText(img, text, cv::Point(137, 262), cv::FONT_HERSHEY_DUPLEX, 0.75, orange, 2);

	imshow("Image", img);
	cv::waitKey(0);
}
