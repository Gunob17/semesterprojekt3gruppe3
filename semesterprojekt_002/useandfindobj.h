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

private:
    cv::Mat pic;
};

#endif // USEANDFINDOBJ_H
