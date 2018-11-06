#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "sstream"
using namespace std;
using namespace  cv;



Mat getpic(/*string name*/){
    VideoCapture cap(1); // open the default camera
    if(!cap.isOpened()){  // check if we succeeded
        //return -1;
}
    cap.set(CAP_PROP_EXPOSURE, 0.00000001);
    cap.set(CV_CAP_PROP_GAIN, 0.000000001);
    cap.set(CV_CAP_PROP_FRAME_WIDTH,1448);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT,1080);

    Mat image;
    for (int i = 0 ; i < 2 ; ++i){

        cap >> image;} // get a new frame from camera
    return image;

}
Mat getpic(string name){
    Mat image;
    image = imread(name, IMREAD_COLOR); // Read the file
    if (!image.data) // Check for invalid input
    {
      cout << "Could not open or find the image" << endl;
    }
    return image;
}

void converttogrey(Mat &pic){
    Mat newcopy = pic.clone();
    cvtColor(newcopy,pic,CV_BGR2GRAY);
    //return newcopy;
}

void resi(Mat &image){
    resize(image, image, Size(144*8,108*8));
}
void dilateErode(Mat &pic){
    Mat structuring_element = getStructuringElement( 1, Size(13,13),Point(4,4) );
    dilate(pic, pic, structuring_element);
    erode(pic,pic, structuring_element);
    erode(pic,pic, structuring_element);
    dilate(pic, pic, structuring_element);
}

void converttobinary(Mat &pic){
    Mat newcopy = pic.clone();
    threshold( newcopy, pic, 0, 255, THRESH_BINARY | THRESH_OTSU );
}

String conBinToString(Mat image){
    String sImage;
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
             int q = (int)image.at<char>(i,j);
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

Mat conStringToBin(string s){
    Mat image = Mat(50,50,CV_8UC3);
    int j =0;
    for (int i = 0; i < s.size(); ++i) {


            if ( s[i] == '0'){
                image.row(i).col(j) = 0;
            }
            else if(s[i] == '2'){
                ++j;

            }
            else  {
                image.row(i).col(j) = 1;
            }
        }
    return image;
}

void PanoramicDistortion(Mat &image){
    Point2f inputpoint[4];
    Mat lambda(2,4,CV_32FC1);
    Mat output;
    lambda = Mat::zeros(image.rows, image.cols, image.type());
    inputpoint[0] = Point2f();
    inputpoint[1] = Point2f();
    inputpoint[2] = Point2f();
    inputpoint[3] = Point2f();
}

/*static void onMouse(int event,int x,int y,int,void*)
{
    //this function will be called every time you move your mouse over the image
    // the coordinates will be in x and y variables
    Mat img2;pic.copyTo(img2);
    line(img2,Point(x,0),Point(x,img2.cols),Scalar(0,0,255),2);
    line(img2,Point(0,y),Point(img2.rows,y),Scalar(0,0,255),2);
    imshow("Image",img2);
}*/


int main()
{
    Mat pic, pics;
    string s;
    pic = getpic(/*"C:/Users/gusta/OneDrive - Syddansk Universitet/3,semester/cv/images/ORings/ORing01.jpg"*/);
    PanoramicDistortion(pic);
    //converttogrey(pic);
    //converttobinary(pic);
    //dilateErode(pic);
    resi(pic);
    namedWindow("edges",WINDOW_AUTOSIZE);
    imshow("edges", pic);
   // setMouseCallback("edges",onMouse);
    waitKey(0);
    //while (true){
    //if(waitKey(30) >= 0) break;

    resi(pic);



    s = conBinToString(pic);
    //cout << s <<endl;

    cout <<s<<endl;


   // pics = conStringToBin(s);
    //namedWindow("test1",1080);
    //imshow("test1", pics);
    //waitKey(0);


    return 0;
}
