#include <iostream>
#include "preProcessorText.h"

int main(void) {
	preProcessorText pre = preProcessorText();
	cv::Mat image = cv::imread("text.png");
	pre.collectA4(pre.convertImage(image));
	

}