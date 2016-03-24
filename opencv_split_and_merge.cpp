#include <opencv2/opencv.hpp>

#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat img, empty, b_img, g_img, r_img;
	vector<Mat> tmp;
	vector<Mat> bgr(3);
	
	img = imread("img.bmp", CV_LOAD_IMAGE_UNCHANGED);
	if(!img.data)
	{
		cout << "Can't open/find image!!" << endl;
		system("pause");
		return -1;
	}
	empty = Mat::zeros(img.rows, img.cols, CV_8UC1);
	
	//split color image to b, g, r image
	split(img, bgr);
	
	//merge - blue
	tmp.clear();
	tmp.push_back(bgr[0]);
	tmp.push_back(empty);
	tmp.push_back(empty);
	merge(tmp, b_img);
	
	//merge - green
	tmp.clear();
	tmp.push_back(empty);
	tmp.push_back(bgr[1]);
	tmp.push_back(empty);
	merge(tmp, g_img);
	
	//merge - red
	tmp.clear();
	tmp.push_back(empty);
	tmp.push_back(empty);
	tmp.push_back(bgr[2]);
	merge(tmp, r_img);
	
	namedWindow("source image", CV_WINDOW_AUTOSIZE);
	namedWindow("blue channel", CV_WINDOW_AUTOSIZE);
	namedWindow("green channel", CV_WINDOW_AUTOSIZE);
	namedWindow("red channel", CV_WINDOW_AUTOSIZE);
	imshow("source image", img);
	imshow("blue channel", b_img);
	imshow("green channel", g_img);
	imshow("red channel", r_img);
	waitKey(0);

	return 0;
}