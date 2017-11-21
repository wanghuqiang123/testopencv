#include<opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat img = imread("sushe.jpg");
	imshow("nn",img);
	namedWindow("111");
	waitKey(0);
	return 0;
}