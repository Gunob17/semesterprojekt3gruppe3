#include "throwbot.h"
//#include "findobject.h"
#include "imageprocessing.h"
#include <QApplication>
#include <iostream>

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


static void onMouse(int event,int x,int y,int,void*)
{
    //this function will be called every time you move your mouse over the image
    //the coordinates will be in x and y variables
    cv::Mat p;
    cv::Mat img2;p.copyTo(img2);
    cv::line(img2, cv::Point(x,0), cv::Point(x,img2.cols), cv::Scalar(0,0,255),2);
    cv::line(img2, cv::Point(0,y), cv::Point(img2.rows,y), cv::Scalar(0,0,255),2);

    imshow("edges",p);
    std::cout<< "                                   "<<"\r";
    std::cout<< x<<","<<y<<"\r";
}

int main(int argc, char* argv[])
{
//    QApplication a(argc, argv);

    //Reads the image at the given location and saves it in the member variable
    ImageProcessing image("C:/Users/sarah/OneDrive - Syddansk Universitet/UNI/Tredje Semester/Semesterprojekt (tredje semester)/Images/rispude05.jpg");

    //Takes the input from the given source (0 = default/webcam, ?1 = robotcam?)
    //ImageProcessing image(1);

    //cv::namedWindow("Image", cv::WINDOW_AUTOSIZE);

//    cv::imshow("Image", image);

    image.undistort();
    cv::namedWindow("test");
    cv::imshow("test", image.getimage());
    cv::waitKey(0);
    image.findTemplate();
    image.findCenter();

/*
    image.undistortimage();
    namedWindow("edges", cv::WINDOW_AUTOSIZE);
    cv::setMouseCallback("edges", onMouse);
    image.saveImage("C:/Users/gusta/Desktop/images/calb-rispude01.jpg");
    cv::imshow("edges",image.getimage());
    cv::waitKey(0);
*/

    return 0;

//From original main-funtion:
//    myTemplate.show();
//    return a.exec();
}
