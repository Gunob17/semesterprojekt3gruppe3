#ifndef USEANDFINDOBJ_H
#define USEANDFINDOBJ_H
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


class useAndFindObj
{
public:
    useAndFindObj(int type);
    useAndFindObj(std::string name);
    //useAndFindObj();

    void converttogrey();
    void resi(int cols, int rows);
    void dilateErode();
    cv::Mat getimage();
    void converttobinary();
    std::string conBinToString();
    void saveImage(std::string file_place);
    void PanoramicDistortion();
    void undistortimage();
    int findTemplate();
    int findCenter();

private:
    cv::Mat pic;
    cv::Point m_tlCorner;
    cv::Point m_brCorner;
    cv::Point m_center;
};

#endif // USEANDFINDOBJ_H
