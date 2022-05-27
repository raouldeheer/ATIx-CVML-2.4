#include "blobDetection.h"

cv::Mat crop(cv::Mat input)
{
	int width1 = (int)floor(input.size().width * 0.05f);
	int width2 = (int)floor(input.size().width * 0.95f);
	int height1 = (int)floor(input.size().height * 0.05f);
	int height2 = (int)floor(input.size().height * 0.95f);
	cv::Mat cropped_image = input(cv::Range(height1, height2), cv::Range(width1, width2));
	return cropped_image;
}

std::vector<cv::KeyPoint> blobDetect(cv::Mat input)
{
	cv::Mat imgGray, imgThes;
	cv::cvtColor(input, imgGray, cv::COLOR_BGR2GRAY);
	cv::threshold(imgGray, imgThes, 100, 255, cv::THRESH_BINARY);

	cv::SimpleBlobDetector::Params params;

	// Change thresholds
	params.minThreshold = 0;
	params.maxThreshold = 2000;

	// Filter by Area.
	params.filterByArea = false;
	params.minArea = 3;

	// Filter by Circularity
	params.filterByCircularity = false;
	params.minCircularity = 0.1;

	// Filter by Convexity
	params.filterByConvexity = false;
	params.minConvexity = 0.87;

	// Filter by Inertia
	params.filterByInertia = false;
	params.minInertiaRatio = 0.01;

	cv::Ptr<cv::SimpleBlobDetector> detector = cv::SimpleBlobDetector::create(params);

	std::vector<cv::KeyPoint> keypoints;
	detector->detect(imgThes, keypoints);

	return keypoints;
}
