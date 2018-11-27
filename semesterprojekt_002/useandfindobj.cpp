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
    cap.set(CAP_PROP_EXPOSURE, 0.00000001);
    cap.set(CAP_PROP_GAIN, 0.000000001);
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
    inputpoint[0] = Point2f(132,0);
    inputpoint[1] = Point2f(121,828);
    inputpoint[2] = Point2f(756,0);
    inputpoint[3] = Point2f(763,850);
    //inputpoint[4] = Point2f(108,369);

    output[0]= Point2f(100,0);
    output[1]= Point2f(100,828);
    output[2]= Point2f(624,0);
    output[3]= Point2f(624,828);
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
}
