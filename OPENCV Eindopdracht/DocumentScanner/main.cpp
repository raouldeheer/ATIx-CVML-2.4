#include <iostream>
#include "preProcessorText.h"
#include "blobDetection.h"

int main(void) {
	preProcessorText pre = preProcessorText();
	cv::Mat image = cv::imread("text.png");
	cv::Mat paperImg = pre.wrapA4(image, pre.collectA4(pre.convertImage(image)), cv::Point(image.size().width,image.size().height));
	
	cv::Mat cropped_image = crop(paperImg);
	std::vector<cv::KeyPoint> keypoints = blobDetect(cropped_image);

	cv::Mat image_with_keypoints;
	cv::drawKeypoints(cropped_image, keypoints, image_with_keypoints, cv::Scalar(0, 0, 255), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
	cv::imshow("points", image_with_keypoints);
	std::cout << "letters: " << keypoints.size() << std::endl;

	cv::waitKey();
}