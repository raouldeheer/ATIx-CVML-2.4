#pragma once

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <array>

cv::Mat crop(cv::Mat input);
std::vector<cv::KeyPoint> blobDetect(cv::Mat input, cv::Size dilKernel);
