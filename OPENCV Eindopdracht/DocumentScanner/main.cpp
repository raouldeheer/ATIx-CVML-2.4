#include <iostream>
#include "preProcessorText.h"
#include "blobDetection.h"

int main(void) {
	preProcessorText pre = preProcessorText();
	cv::Mat image = cv::imread("text.png");
	cv::Mat paperImg = pre.wrapA4(image, pre.collectA4(pre.convertImage(image)), cv::Point(image.size().width,image.size().height));
	
	cv::Mat cropped_image = crop(paperImg);

	std::vector<cv::KeyPoint> keypoints = blobDetect(cropped_image, cv::Size(3, 3));
	std::vector<cv::KeyPoint> keypoints2 = blobDetect(cropped_image, cv::Size(4, 4));

	std::cout << "letters: " << keypoints.size() << std::endl;
	std::cout << "woorden: " << keypoints2.size() << std::endl;

	cv::waitKey();
}