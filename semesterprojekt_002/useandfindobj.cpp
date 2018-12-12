#include "useandfindobj.h"
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

useAndFindObj::useAndFindObj(std::string name)
{

    pic = imread(name, IMREAD_COLOR); // Read the file
    if (!pic.data) // Check for invalid input
    {
      cout << "Could not open or find the image" << endl;
      //return -1;
    }

}
useAndFindObj::useAndFindObj(int type)
{

    VideoCapture cap(type);
    if(!cap.isOpened()){
        //return -1;
    }
    //cap.set(CAP_PROP_EXPOSURE, 0.00000001);
    //cap.set(CAP_PROP_GAIN, 0.000000001);
    cap.set(CAP_PROP_FRAME_WIDTH,1448);
    cap.set(CAP_PROP_FRAME_HEIGHT,1080);

    for (int i = 0 ; i < 2 ; ++i){
        cap >> pic;
    } // get a new frame from camera
}
/*useAndFindObj::useAndFindObj(){

    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened()){  // check if we succeeded
       // return -1;
}
    cap.set(CAP_PROP_EXPOSURE, 0.00000001);
    cap.set(CAP_PROP_GAIN, 0.000000001);
    cap.set(CAP_PROP_FRAME_WIDTH,1448);
    cap.set(CAP_PROP_FRAME_HEIGHT,1080);
    namedWindow("edges",WINDOW_AUTOSIZE);
    for (;;){
        cap >> pic;
        imshow("edges",pic);
        waitKey(0);
    } // get a new frame from camera
}*/
void useAndFindObj::converttogrey(){
    Mat newcopy = pic.clone();
    cvtColor(newcopy,pic,COLOR_BGR2GRAY);
}
void useAndFindObj::resi(int cols, int rows){
     resize(pic, pic, Size(cols,rows));
}
void useAndFindObj::dilateErode(){
    Mat structuring_element = getStructuringElement( 1, Size(13,13),Point(4,4) );
    dilate(pic, pic, structuring_element);
    erode(pic,pic, structuring_element);
    erode(pic,pic, structuring_element);
    dilate(pic, pic, structuring_element);
}
cv::Mat useAndFindObj::getimage(){
    return pic;
}
void useAndFindObj::converttobinary(){
    Mat newcopy = pic.clone();
    threshold( newcopy, pic, 0, 255, THRESH_BINARY | THRESH_OTSU );
}
std::string useAndFindObj::conBinToString(){
    String sImage;
    for (int i = 0; i < pic.rows; ++i) {
        for (int j = 0; j < pic.cols; ++j) {
             int q = (int)pic.at<char>(i,j);
            if ( q == 0){
                sImage = sImage + "0";
            }
            else  {
                sImage = sImage +"1";
            }
        }
        sImage = sImage + "2";
    }
    return sImage;
}
void useAndFindObj::saveImage(string file_place){
    imwrite(file_place,pic);
    cout<< "picture saved to: "<<file_place<<endl;
}
void useAndFindObj::PanoramicDistortion(){
    Point2f inputpoint[4];
    Mat lambda(2,4,CV_32FC1);
    Point2f output[4];
    lambda = Mat::zeros(pic.rows, pic.cols, pic.type());
    inputpoint[0] = Point2f(96,882);
    inputpoint[1] = Point2f(945,890);
    inputpoint[2] = Point2f(945,155);
    inputpoint[3] = Point2f(115,163);
    //inputpoint[4] = Point2f(108,369);

    output[0]= Point2f((294+300),(-842+900));
    output[1]= Point2f((836+300),(-310+900));
    output[2]= Point2f((375+300),(165+900));
    output[3]= Point2f((-159+300),(-375+900));
    //output[4]= Point2f(100,369);

    lambda = getPerspectiveTransform(inputpoint,output);
    warpPerspective(pic,pic,lambda,pic.size());
}

void useAndFindObj::undistortimage(){
    Matx33f K(1831.6919,0,724,0,1831.6919,540,0,0,1);// intrinsic camera matrix
    Vec<float, 5> k(-0.541726, 0.420384, 0, 0, 0); // distortion coefficients
    Mat mapX, mapY;
    Size frameSize(1448, 1080);
    initUndistortRectifyMap(K, k, Matx33f::eye(), K, frameSize, CV_32FC1, mapX, mapY);
    //cv::Mat imgUndistorted;
    remap(pic,pic,mapX,mapY,1,BORDER_CONSTANT);
    cv::cvtColor(pic, pic, CV_BGR2GRAY);
}
int useAndFindObj::findTemplate() {
    cv::Mat template_img;
    cv::Mat result_mat;

    //match method options: CV_TM_SQDIFF, CV_TM_SQDIFF_NORMED, CV_TM _CCORR, CV_TM_CCORR_NORMED, CV_TM_CCOEFF, CV_TM_CCOEFF_NORMED
    int match_method = CV_TM_CCORR_NORMED;

    template_img = cv::imread("C:/Users/gusta/Documents/GitHub/semesterprojekt3gruppe3/rispude01 - template.jpg", cv::IMREAD_GRAYSCALE);
    if (!template_img.data) {
        std::cout << "Could not open template";
        return -1;
    }

    cv::imshow("Template", template_img);
    cv::waitKey(10);

    while(true) {
//Matches the template to the image using the given match method, and stores the result in result_mat
        cv::matchTemplate(pic, template_img, result_mat, match_method);
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
        cv::rectangle(pic, matchLoc, point, CV_RGB(255,0,0), 3);

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

int useAndFindObj::findCenter() {
//Find center of rectangle - and therefore object
//Center point pixel coordinates are determined by calculating from top left and bottom right corner
    m_center = cv::Point(m_tlCorner.x + ((m_brCorner.x - m_tlCorner.x)/2), m_tlCorner.y + ((m_brCorner.y - m_tlCorner.y)/2));

    std::cout << "Center point: " << m_center << std::endl;

//Draws the center point on the image
    cv::line(pic, m_center, m_center, cv::Scalar(0,0,255), 4, 8);

    cv::imshow("Result", pic);

//Wait for random key press
    cv::waitKey(0);

    return 0;
}
