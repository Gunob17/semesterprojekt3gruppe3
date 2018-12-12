
#include <iostream>
#include <opencv2/calib3d.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char **argv) {

  (void)argc;
  (void)argv;

  std::vector<cv::String> fileNames;
  cv::glob("C:/Users/gusta/Desktop/images/camcal*.jpg", fileNames, false);
  cv::Size patternSize(8-1, 8-1);
  std::vector<std::vector<cv::Point2f>> q(fileNames.size());
  std::vector<std::vector<cv::Point3f>> Q;
  // Detect feature points
  std::size_t i = 0;
  bool success;
  for (auto const &f : fileNames) {
    std::cout << std::string(f) << std::endl;

    // 1. Read in the image an call cv::findChessboardCorners()
    Mat img = imread(f, 0);
    //cv::imshow("chessboard detection", img);
    findChessboardCorners(img,patternSize,q[i], CALIB_CB_NORMALIZE_IMAGE);
    //cout<<q[i]<<endl;
    // 2. Use cv::cornerSubPix() to refine the found corner detections
    cornerSubPix(img,q[i],Size(5,5),Size(-1,-1),TermCriteria(CV_TERMCRIT_EPS + CV_TERMCRIT_ITER, 30, 0.1));
    // Display
 //cout<<q[i]<<endl;
    cv::drawChessboardCorners(img, patternSize, q[i], success);
    cv::imshow("chessboard detection", img);
    cout<<success<<endl;
    cv::waitKey(0);

    vector<Point3f> p;
    for( int h = 0; h < patternSize.height; h++ ){
        for( int j = 0; j < patternSize.width; j++ ){
                  p.push_back(Point3f(float(j*20),float(h*20), 0));
                }
    }
    Q.push_back(p);
    i++;
  }

  //std::vector<std::vector<cv::Point3f>> Q;
  // 3. Generate checkerboard (world) coordinates Q. The board has 25 x 18
  // fields with a size of 15x15mm





  cv::Matx33f K(cv::Matx33f::eye());  // intrinsic camera matrix
  cv::Vec<float, 5> k(1, 1, 0, 0, 0); // distortion coefficients
  std::vector<cv::Mat> rvecs, tvecs;
  int flags = cv::CALIB_FIX_ASPECT_RATIO + cv::CALIB_FIX_K3 +
              cv::CALIB_ZERO_TANGENT_DIST + cv::CALIB_FIX_PRINCIPAL_POINT;
  cv::Size frameSize(1448, 1080);
  //K and k is calculated
  float error = cv::calibrateCamera(Q,q,frameSize,K,k,rvecs,tvecs,flags);

  std::cout << "Reprojection error = " << error << "\nK =\n"
            << K << "\nk=\n"
            << k << std::endl;

  // Precompute lens correction interpolation
  cv::Mat mapX, mapY;
  cv::initUndistortRectifyMap(K, k, cv::Matx33f::eye(), K, frameSize, CV_32FC1,
                              mapX, mapY);

  // Show lens corrected images
  for (auto const &f : fileNames) {
    std::cout << std::string(f) << std::endl;

    cv::Mat img = cv::imread(f, cv::IMREAD_COLOR);

    cv::Mat imgUndistorted;
    // 5. Remap the image using the precomputed interpolation maps.
    remap(img,imgUndistorted,mapX,mapY,1,BORDER_CONSTANT);
    //undistort(img,imgUndistorted,K,k);
    // Display
    cv::imshow("undistorted image", imgUndistorted);
    cv::waitKey(0);
  }

  return 0;
}
