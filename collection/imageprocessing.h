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
	void undistort();
	void saveImage(std::string);
    void panoramicDistortion();
	cv::Point2i getCenter();
	int verifyThrow(int x, int y);
	void resi(int cols, int rows);

private:
	cv::Mat m_image;
	cv::Mat m_imageClone;
	cv::Point m_tlCorner;
	cv::Point m_brCorner;
	cv::Point m_center;
};

#endif // IMAGEPROCESSING_H
