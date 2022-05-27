#include "preProcessorText.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <array>
#include <vector>
#include <iostream>

cv::Mat preProcessorText::convertImage(cv::Mat image)
{
	// Preprocessoing edges.
	cv::Mat imgGray, imgBlur, imgCanny, imgDilation;
	cv::cvtColor(image, imgGray,  cv::COLOR_BGR2GRAY);
	cv::GaussianBlur( imgGray, imgBlur, cv::Size(3, 3), 3, 0);
	cv::Canny(imgBlur, imgCanny,  25, 75);
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	cv::dilate( imgCanny, imgDilation, kernel);

	cv::imshow("Dilated", imgDilation);
	cv::waitKey();

	return imgDilation;
}

std::vector<cv::Point> preProcessorText::collectA4(cv::Mat image)
{
	// Collecting contours of the image
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierachy;
	cv::findContours(image, contours, hierachy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

	// Variables of the biggest.
	int maxArea = 0;
	std::vector<cv::Point> biggest;
	std::vector<std::vector<cv::Point>> conPoly(contours.size());


	// Finding the A4 countours
	for (int i = 0; i < contours.size(); i++) {
		int area = cv::contourArea(contours[i]);
		float peri = cv::arcLength(contours[i], true);
		cv::approxPolyDP(contours[i], conPoly[i], (0.02 * peri) , true);

		if (area > maxArea){
			maxArea = area;
			biggest = conPoly[i];
		}
	}

	// Checking if valid an porting to array;
	if (biggest.size() == 4) {
		cv::drawContours(image, conPoly, -1, cv::Scalar(255, 0, 0), 10);
		cv::imshow("Contours", image);
		cv::waitKey();
	}

	return biggest;
}

cv::Mat preProcessorText::wrapA4(cv::Mat image, std::vector<cv::Point> points, cv::Point demensions)
{
	// Drawing the edges
	for (int i = 0; i < 4; i++)
	{
		cv::circle(image, points[i], 10, cv::Scalar(0, 0, 255), cv::FILLED);
	}

	cv::imshow("Edges", image);
	cv::waitKey();

	//Sorting the input vector to array
	cv::Point2f src[4];
	src[0] = points[0];
	for (int i = 0; i < 4; i++) {
		if (points[i].x + points[i].y < src[0].x + src[0].y) {
			src[0] = points[i];
		}
		else if (points[i].x - points[i].y > src[1].x - src[1].y) {
			src[1] = points[i];
		}
		else if (points[i].x - points[i].y < src[2].x - src[2].y) {
			src[2] = points[i];
		}
		else if (points[i].x + points[i].y > src[3].x + src[3].y) {
			src[3] = points[i];
		}
	}

	cv::Point2f dst[4] = { {0.0f,0.0f},{(float)demensions.x,0.0f},{0.0f,(float)demensions.y},{(float)demensions.x,(float)demensions.y} };

	// Wrapping the image
	cv::Mat imgWarp;

	cv:: Mat matrix =  cv::getPerspectiveTransform(src, dst);
	warpPerspective(image, imgWarp, matrix, demensions);

	cv::imshow("Wrap", imgWarp);
	cv::waitKey();


	return imgWarp;
}
