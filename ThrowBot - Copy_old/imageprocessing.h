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
    void undistort();
    void saveImage(std::string);
    void perspectivTransformation();

private:
    cv::Mat m_image;
    cv::Mat m_imageClone;
    cv::Point m_tlCorner;
    cv::Point m_brCorner;
    cv::Point m_center;
};

/*
void converttogrey();
void resi(int cols, int rows);
void dilateErode();

void converttobinary();
std::string conBinToString();
void PanoramicDistortion();
*/

#endif // IMAGEPROCESSING_H
