#include "preProcessorText.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <array>
#include <vector>

cv::Mat preProcessorText::convertImage(cv::Mat image)
{
	// Preprocessoing edges.
	cv::Mat imgResize, imgGray, imgBlur, imgCanny, imgDilation;
	cv::resize(image, imgResize, cv::Size(), 0.3, 0.3);
	cv::cvtColor(imgResize, imgGray,  cv::COLOR_BGR2GRAY);
	cv::GaussianBlur( imgGray, imgBlur, cv::Size(3, 3), 3, 0);
	cv::Canny(imgBlur, imgCanny,  25, 75);
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	cv::dilate( imgCanny, imgDilation, kernel);

	cv::imshow("Dilated", imgDilation);
	cv::waitKey();

	return imgDilation;
}

std::array<cv::Point, 4> preProcessorText::collectA4(cv::Mat image)
{
	// Collecting contours of the image
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierachy;
	cv::findContours(image, contours, hierachy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

	// Variables of the biggest.
	int maxArea = 0;
	std::vector<cv::Point> biggest;

	// Finding the A4 countours
	for (int i = 0; i < contours.size(); i++) {
		int area = cv::contourArea(contours.at(i));

		if (area > maxArea){
			maxArea = area;
			cv::approxPolyDP(contours[i], biggest, 0.02f * cv::arcLength(contours[i], true), true);
		}
	}

	// Checking if valid an porting to array;
	if (biggest.size() == 4) {
		std::array<cv::Point, 4> result;
		std::copy_n(std::make_move_iterator(biggest.begin()), 4, result.begin());
		return result;
	}

	return std::array<cv::Point, 4>();
}

cv::Mat preProcessorText::wrapA4(cv::Mat image, std::array<cv::Point, 4> points)
{
	//matrix = getPerspectiveTransform(src, dst);
	//warpPerspective(img, imgWarp, matrix, Point(w, h));

	return cv::Mat();
}
