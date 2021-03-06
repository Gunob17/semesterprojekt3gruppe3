/// by Sarah Trohl and Gustav Nobel
#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

class ImageProcessing
{
public:
	ImageProcessing();
	ImageProcessing(int);
	ImageProcessing(std::string);

	cv::Mat getimage();
	int findTemplate();
	int findCenter();
	int setDestination(int x, int y);
	int verifyThrow(int x, int y);
	void undistort();
	void perspectiveTransformation();
	cv::Point2i getCenter();

private:
	cv::Mat m_image;
	cv::Point m_tlCorner;
	cv::Point m_brCorner;
	cv::Point m_center;
};

#endif // IMAGEPROCESSING_H
