/// by Sarah Trohl and Gustav Nobel

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
	if (!cap.isOpened()) {
		std::cout << "Cap is not open" << std::endl;
	}

	cap.set(cv::CAP_PROP_EXPOSURE, 0.00000001);
	cap.set(cv::CAP_PROP_GAIN, 0.000000001);
	cap.set(cv::CAP_PROP_FRAME_WIDTH, 1440);
	cap.set(cv::CAP_PROP_FRAME_HEIGHT, 1080);

	namedWindow("Camera", cv::WINDOW_AUTOSIZE);

	while (true) {
		cap >> m_image;
		cv::imshow("Camera", m_image);
		if (cv::waitKey(30) >= 0)
			break;
	}                                                                           // Get a new frame from camera
}

ImageProcessing::ImageProcessing(std::string loc) {
	m_image = cv::imread(loc, cv::IMREAD_COLOR);                                // Read the file
	if (!m_image.data) {                                                        // Check for invalid input
		std::cout << "Could not open or find the image" << std::endl;
	}
	cv::imshow("Image", m_image);
	cv::waitKey(0);
}

void ImageProcessing::undistort() {
	cv::Matx33f K(1831.6919, 0, 724, 0, 1831.6919, 540, 0, 0, 1);               // intrinsic camera matrix
	cv::Vec<float, 5> k(-0.541726, 0.420384, 0, 0, 0);                          // distortion coefficients
	cv::Mat mapX, mapY;
	cv::Size frameSize(1448, 1080);
	cv::initUndistortRectifyMap(K, k, cv::Matx33f::eye(), K, frameSize, CV_32FC1, mapX, mapY);
	cv::remap(m_image, m_image, mapX, mapY, 1, cv::BORDER_CONSTANT);
	//Convert the image to grayscale (necessary for template matching)
	cv::cvtColor(m_image, m_image, CV_BGR2GRAY);                                
}

cv::Mat ImageProcessing::getimage() {
	// returns a matrix image object 
	return m_image;
}

int ImageProcessing::findTemplate() {
	cv::Mat template_img;
	cv::Mat result_mat;

	template_img = cv::imread("./images/rispude01 - template.jpg", cv::IMREAD_GRAYSCALE);
	if (!template_img.data) {
		std::cout << "Could not open template" << std::endl;
		return -1;
	}

	int match_method = CV_TM_CCORR_NORMED;

	while (true) {
		//Matches the template to the image using the given match method, and stores the result in result_mat
		cv::matchTemplate(m_image, template_img, result_mat, match_method);
		cv::normalize(result_mat, result_mat, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());

		double minVal, maxVal;
		cv::Point minLoc, maxLoc;
		//Finds the minimum and maximum values of the array (the corners in the part of the image, that matches the template)
		cv::minMaxLoc(result_mat, &minVal, &maxVal, &minLoc, &maxLoc, cv::Mat());

		//Defines the bottom right corner
		cv::Point point = cv::Point(maxLoc.x + template_img.cols, maxLoc.y + template_img.rows);

		//A rectangle is drawn around the area where the template has a match
		cv::rectangle(m_image, maxLoc, point, CV_RGB(255, 0, 0), 3);

		//Wait
		int k = cv::waitKey(0);
		if (k == 27 || k == 13) {               //Exits loop when ESC/Enter is pressed (27 = decimal value for ESC, 13 for Enter)
			m_tlCorner = maxLoc;                //Corner values are saved in member variables for later use
			m_brCorner = point;
			std::cout << "Top left corner of template: " << m_tlCorner << std::endl;
			std::cout << "Bottom right corner of template: " << m_brCorner << std::endl;
			break;
		}
	}
	return 0;
}

int ImageProcessing::findCenter() {
	cv::destroyAllWindows();
	//Find center of rectangle - and therefore object
	//Center point pixel coordinates are determined by calculating from top left and bottom right corner
	m_center = cv::Point(m_tlCorner.x + ((m_brCorner.x - m_tlCorner.x) / 2), m_tlCorner.y + ((m_brCorner.y - m_tlCorner.y) / 2));

	//Print the center point in pixel coordinates and then robot coordinates
	std::cout << "Center point: " << m_center << std::endl;
	std::cout << "Center point recalculated: " << m_center.x - 300 << ", " << m_center.y - 900 << std::endl;

	//Draws the center point on the image
	cv::line(m_image, m_center, m_center, cv::Scalar(0, 0, 255), 4, 8);
	cv::imshow("Result", m_image);

	//Wait for random key press
	cv::waitKey(0);

	return 0;
}

int ImageProcessing::setDestination(int x, int y) {
	//Converts the input coordinates from the GUI to pixel coordinates
	cv::Point point = cv::Point(x + 300, y + 900);

	//Draws the point on the image
	cv::line(m_image, point, point, cv::Scalar(0, 0, 255), 4, 8);
	cv::imshow("Image", m_image);

	//Wait for random key press
	cv::waitKey(0);

	return 0;
}

void ImageProcessing::perspectiveTransformation() {
	cv::Point2f inputpoint[4];
	cv::Mat ptMatrix(2, 4, CV_32FC1);
	cv::Point2f output[4];

	ptMatrix = cv::Mat::zeros(m_image.rows, m_image.cols, m_image.type());
	//pixels coordinates found in an undistorted image 
	inputpoint[0] = cv::Point2f(96, 882);
	inputpoint[1] = cv::Point2f(945, 890);
	inputpoint[2] = cv::Point2f(945, 155);
	inputpoint[3] = cv::Point2f(115, 163);

	//coordinates found using a UR robot 
	output[0] = cv::Point2f((294 + 300), (-842 + 900));
	output[1] = cv::Point2f((836 + 300), (-310 + 900));
	output[2] = cv::Point2f((375 + 300), (165 + 900));
	output[3] = cv::Point2f((-159 + 300), (-375 + 900));
	//
	ptMatrix = cv::getPerspectiveTransform(inputpoint, output);
	cv::warpPerspective(m_image, m_image, ptMatrix, m_image.size());
}

cv::Point2i ImageProcessing::getCenter() {
	//returns center point 
	return m_center;
}

int ImageProcessing::verifyThrow(int x, int y) {
	//Converts the input coordinates from the GUI to pixel coordinates
	cv::Point point = cv::Point(x + 300, y + 900);

	//Draws the destination point from the GUI on the image
	cv::line(m_image, point, point, cv::Scalar(0, 0, 255), 4, 8);
	this->findTemplate();
	this->findCenter();
	cv::line(m_image, point, m_center, cv::Scalar(0, 200, 255), 4, 8);

	cv::imshow("Result", m_image);

	//Wait for random key press
	cv::waitKey(0);

	return 0;
}