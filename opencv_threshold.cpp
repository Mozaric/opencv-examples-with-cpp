#include <opencv2/opencv.hpp>

#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("img.bmp", CV_LOAD_IMAGE_GRAYSCALE);
	if(!img.data)
	{
		cout << "Can't open/find image!!" << endl;
		system("pause");
		return -1;
	}
	
	//calculate mean value
	int mean(0);
	for(int i=0; i<img.cols; ++i)
	{
		for(int j=0; j<img.rows; ++j)
		{
			mean += img.at<uchar>(Point(i, j));
		}
	}
	mean /= (img.cols * img.rows);
	cout << "mean value: " << mean << endl;
	
	//threshold(binarization)
	threshold(img, img, mean, 255, CV_THRESH_BINARY);
	
	namedWindow("binary image", CV_WINDOW_AUTOSIZE);
	imshow("binary image", img);
	waitKey(0);

	return 0;
}