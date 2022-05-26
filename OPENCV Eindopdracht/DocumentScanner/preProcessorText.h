#pragma once

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <array>

class preProcessorText {
public :
	// Preprocessing steps available
	cv::Mat convertImage(cv::Mat image);
	std::array<cv::Point, 4> collectA4(cv::Mat image);
	cv::Mat wrapA4(cv::Mat image, std::array<cv::Point, 4> points);
};