#include <opencv2/opencv.hpp>

#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("img.bmp", CV_LOAD_IMAGE_UNCHANGED);
	if(!img.data)
	{
		cout << "Can't open/find image!!" << endl;
		system("pause");
		return -1;
	}
	
	//put text on img
	putText(img, "This is an image.", Point(30, 30), FONT_HERSHEY_COMPLEX, 0.75, Scalar(255, 255, 255));
	
	namedWindow("img", CV_WINDOW_AUTOSIZE);
	imshow("img", img);
	waitKey(0);

	return 0;
}