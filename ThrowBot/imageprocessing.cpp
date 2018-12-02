#include "imageprocessing.h"
#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

ImageProcessing::ImageProcessing() {
}

ImageProcessing::ImageProcessing(int inputSource) {
    cv::VideoCapture cap(inputSource);
    if(!cap.isOpened()){
        std::cout << "Cap is not open";
    }
    cap.set(cv::CAP_PROP_EXPOSURE, 0.00000001);
    cap.set(cv::CAP_PROP_GAIN, 0.000000001);
    cap.set(cv::CAP_PROP_FRAME_WIDTH,1448);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT,1080);

    namedWindow("Camera", cv::WINDOW_AUTOSIZE);

    for (;;){
        cap >> m_image;
        imshow("Camera", m_image);
        if(cv::waitKey(30)>=0)
            break;
    } // get a new frame from camera

    cv::cvtColor(m_image, m_image, CV_BGR2GRAY);        //Convert the image to grayscale (necessary for template matching)
}

ImageProcessing::ImageProcessing(std::string loc) {
    m_image = cv::imread(loc, cv::IMREAD_GRAYSCALE); // Read the file
    if (!m_image.data) // Check for invalid input
    {
      std::cout << "Could not open or find the image" << std::endl;
    }
}

void ImageProcessing::undistort() {
    cv::Matx33f K(1831.6919, 0, 724, 0, 1831.6919, 540, 0, 0, 1);// intrinsic camera matrix
    //array<float> K = {};
    cv::Vec<float, 5> k(-0.541726, 0.420384, 0, 0, 0); // distortion coefficients
    cv::Mat mapX, mapY;
    cv::Size frameSize(1448, 1080);
    cv::initUndistortRectifyMap(K, k, cv::Matx33f::eye(), K, frameSize, CV_32FC1, mapX, mapY);
    m_imageClone = m_image.clone();
    cv::remap(m_image, m_image, mapX, mapY, 1, cv::BORDER_CONSTANT);
}

void ImageProcessing::saveImage(std::string savePath) {
    //Which image should be saved - image or undistImg?
    imwrite(savePath, m_image);
}

cv::Mat ImageProcessing::getimage(){
    return m_image;
}

int ImageProcessing::findTemplate() {
    cv::Mat template_img;
    cv::Mat result_mat;

    //match method options: CV_TM_SQDIFF, CV_TM_SQDIFF_NORMED, CV_TM _CCORR, CV_TM_CCORR_NORMED, CV_TM_CCOEFF, CV_TM_CCOEFF_NORMED
    int match_method = CV_TM_CCORR_NORMED;

    template_img = cv::imread("C:/Users/sarah/OneDrive - Syddansk Universitet/UNI/Tredje Semester/Semesterprojekt (tredje semester)/Images/rispude01 - template.jpg", cv::IMREAD_GRAYSCALE);
    if (!template_img.data) {
        std::cout << "Could not open template";
        return -1;
    }

    cv::imshow("Template", template_img);
    cv::waitKey(10);

    while(true) {
//Matches the template to the image using the given match method, and stores the result in result_mat
        cv::matchTemplate(m_image, template_img, result_mat, match_method);
        cv::normalize(result_mat, result_mat, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());

        double minVal, maxVal;
        cv::Point minLoc, maxLoc, matchLoc;
//Finds the minimum and maximum values of the array (the corners in the part of the image, that matches the template)
        cv::minMaxLoc(result_mat, &minVal, &maxVal, &minLoc, &maxLoc, cv::Mat() );
        if( match_method  == CV_TM_SQDIFF || match_method == CV_TM_SQDIFF_NORMED )
            matchLoc = minLoc;
        else
            matchLoc = maxLoc;

//Defines the bottom right corner
        cv::Point point = cv::Point(matchLoc.x + template_img.cols , matchLoc.y + template_img.rows);

//A rectangle is drawn around the area where the template has a match
        cv::rectangle(m_image, matchLoc, point, CV_RGB(255,0,0), 3);

//        cv::imshow("Result", image);

//Wait
        int k = cv::waitKey(0);
        if (k == 27 || k == 13)         //Exits loop when ESC/Enter is pressed (27 = decimal value for ESC, 13 for Enter)
            m_tlCorner = matchLoc;      //Corner values are saved in member variables for later use
            m_brCorner = point;
            std::cout << "Top left corner of template: " << m_tlCorner << std::endl;
            std::cout << "Bottom right corner of template: " << m_brCorner << std::endl;
            break;
        }

    return 0;
}

int ImageProcessing::findCenter() {
//Find center of rectangle - and therefore object
//Center point pixel coordinates are determined by calculating from top left and bottom right corner
    m_center = cv::Point(m_tlCorner.x + ((m_brCorner.x - m_tlCorner.x)/2), m_tlCorner.y + ((m_brCorner.y - m_tlCorner.y)/2));

    std::cout << "Center point: " << m_center << std::endl;

    std::cout << "Center point recalculated: " << m_center.x-300 << ", " << m_center.y-900 << std::endl;

//Draws the center point on the image
    cv::line(m_image, m_center, m_center, cv::Scalar(0,0,255), 4, 8);

    cv::imshow("Result", m_image);

//Wait for random key press
    cv::waitKey(0);

    return 0;
}

void ImageProcessing::PanoramicDistortion(){
    cv::Point2f inputpoint[4];
    cv::Mat lambda(2,4,CV_32FC1);
    cv::Point2f output[4];
    lambda = cv::Mat::zeros(m_image.rows, m_image.cols, m_image.type());
    inputpoint[0] = cv::Point2f(96,882);
    inputpoint[1] = cv::Point2f(945,890);
    inputpoint[2] = cv::Point2f(945,155);
    inputpoint[3] = cv::Point2f(115,163);

    output[0]= cv::Point2f((294+300),(-842+900));
    output[1]= cv::Point2f((836+300),(-310+900));
    output[2]= cv::Point2f((375+300),(165+900));
    output[3]= cv::Point2f((-159+300),(-375+900));

    lambda = cv::getPerspectiveTransform(inputpoint,output);
    cv::warpPerspective(m_image,m_image,lambda,m_image.size());
}
