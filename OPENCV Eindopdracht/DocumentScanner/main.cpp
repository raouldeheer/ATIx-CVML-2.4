#include <iostream>
#include "preProcessorText.h"

int main(void) {
	preProcessorText pre = preProcessorText();
	cv::Mat image = cv::imread("text.png");
	cv::resize(image, image, cv::Size(), 0.3, 0.3);

	pre.wrapA4(image, pre.collectA4(pre.convertImage(image)), cv::Point(200,400));
	

}