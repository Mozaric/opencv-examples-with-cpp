#include <opencv2/opencv.hpp>

#include <iostream>
#include <cstring>

using namespace std;
using namespace cv;

int main()
{
	string imgName = "img.bmp";
	string imgGrayName = "img_gray.bmp";
	string winName = "Color Image";
	string winGrayName = "Gray Image";

	Mat img;
	Mat imgGray;
	
	img = imread(imgName, CV_LOAD_IMAGE_COLOR);
	if(!img.data)
	{
		cout << "Can't open or find image!!" << endl;
		system("pause");
		return -1;
	}

	//convert color image to gray image
	cvtColor(img, imgGray, CV_BGR2GRAY);

	namedWindow(winName, CV_WINDOW_AUTOSIZE);
	namedWindow(winGrayName, CV_WINDOW_AUTOSIZE);
	imshow(winName, img);
	imshow(winGrayName, imgGray);
	waitKey(0);

	//save image
	imwrite(imgGrayName, imgGray);

	return 0;
}