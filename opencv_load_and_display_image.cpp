#include <opencv2/opencv.hpp>

#include <iostream>
#include <cstring>

using namespace std;
using namespace cv;

int main()
{
	string imgName = "img.bmp";
	string winName = "Image Viewer";

	//load image
	Mat img = imread(imgName, CV_LOAD_IMAGE_UNCHANGED);
	if(!img.data)
	{
		cout << "Can't open or find image!!" << endl;
		system("pause");
		return -1;
	}

	//create a window
	namedWindow(winName, CV_WINDOW_AUTOSIZE);

	//display image
	imshow(winName, img);
	waitKey(0);

	return 0;
}