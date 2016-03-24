#include <opencv2/opencv.hpp>

#include <iostream>

using namespace std;
using namespace cv;

Mat img;

void onMouseCallback(int Event, int x, int y, int flags, void* param)
{
	switch(Event)
	{
	//when mouse left button down, show the (x, y) and (b, g, r)
	case CV_EVENT_LBUTTONDOWN:
		Mat dst;
		img.copyTo(dst);
		
		int b = dst.at<Vec3b>(Point(x, y))[0];
		int g = dst.at<Vec3b>(Point(x, y))[1];
		int r = dst.at<Vec3b>(Point(x, y))[2];
		
		stringstream ss1, ss2;
		ss1 << "x: " << x << " y: " << y;
		ss2 << "b: " << b << " g: " << g << " r: " << r;
		
		putText(dst, ss1.str(), Point(x, y), FONT_HERSHEY_COMPLEX, 0.75, Scalar(0, 0, 255));
		putText(dst, ss2.str(), Point(x, y+20), FONT_HERSHEY_COMPLEX, 0.75, Scalar(0, 0, 255));
		imshow("img", dst);
	}
}

int main()
{
	img = imread("img.bmp", CV_LOAD_IMAGE_UNCHANGED);
	if(!img.data)
	{
		cout << "Can't open/find image!!" << endl;
		system("pause");
		return -1;
	}
	
	cout << "Right click on the image, then will show the position and color of the point." << endl;

	namedWindow("img", CV_WINDOW_AUTOSIZE);
	
	//set mouse callback function
	setMouseCallback("img", onMouseCallback);
	
	imshow("img", img);
	waitKey(0);
	
	return 0;
}