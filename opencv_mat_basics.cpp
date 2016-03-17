#include <opencv2/opencv.hpp>

#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	int rows(480), cols(640);
	int pos_x(10), pos_y(10);
	
	//create mat
	Mat img1 = Mat::zeros(rows, cols, CV_8UC1);
	Mat img2(rows, cols, CV_8UC3, Scalar(0, 255, 0));
	
	//access gray image pixel value
	int gray;
	gray = img1.at<uchar>(Point(pos_x, pos_y));
	cout << "img1 - Point(" << pos_x << ", " << pos_y << ") = (" << gray << ")" << endl;
	
	//access color image pixel value
	int b, g, r;
	b = img2.at<Vec3b>(Point(pos_x, pos_y))[0];
	g = img2.at<Vec3b>(Point(pos_x, pos_y))[1];
	r = img2.at<Vec3b>(Point(pos_x, pos_y))[2];
	cout << "img2 - Point(" << pos_x << ", " << pos_y << ") = (" << b << ", " << g << ", " << r << ")" << endl;
	
	namedWindow("img1", CV_WINDOW_AUTOSIZE);
	namedWindow("img2", CV_WINDOW_AUTOSIZE);
	imshow("img1", img1);
	imshow("img2", img2);
	waitKey(0);

	return 0;
}