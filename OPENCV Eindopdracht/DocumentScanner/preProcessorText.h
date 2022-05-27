#pragma once

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <array>

class preProcessorText {
public :
	// Preprocessing steps available
	cv::Mat convertImage(cv::Mat image);
	std::vector<cv::Point> collectA4(cv::Mat image);
	cv::Mat wrapA4(cv::Mat image, std::vector<cv::Point> points, cv::Point demensions);
};