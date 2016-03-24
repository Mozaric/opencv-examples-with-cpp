#include <opencv2/opencv.hpp>

#include <iostream>

using namespace std;
using namespace cv;

Mat img;

void TrackbarFunction(int a)
{
	Mat dst;
	threshold(img, dst, a, 255, CV_THRESH_BINARY);
	
	imshow("img", dst);
}

int main()
{
	int init_value(0), stop_value(255);
	
	img = imread("img.bmp", CV_LOAD_IMAGE_GRAYSCALE);
	if(!img.data)
	{
		cout << "Can't open/find image!!" << endl;
		system("pause");
		return -1;
	}
	
	namedWindow("img", CV_WINDOW_AUTOSIZE);
	
	//trackbar
	cvCreateTrackbar("binary threshold", "img", &init_value, stop_value, TrackbarFunction);
	
	imshow("img", img);
	waitKey(0);
	
	return 0;
}