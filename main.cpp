#include<opencv2/opencv.hpp>
#include"opencv2/highgui/highgui.hpp"
using namespace cv;
void example2_4(Mat img)
{
	IplImage image = img;
	cvNamedWindow("origin img");
	cvNamedWindow("output img",CV_WINDOW_AUTOSIZE);
	cvShowImage("origin img",&image);
	IplImage* out= cvCreateImage(cvGetSize(&image),IPL_DEPTH_8U,3);
	
	cvSmooth(&image,out,CV_GAUSSIAN,3,3);
	cvShowImage("ouput img",out);
	cvReleaseImage(&out);

	waitKey(0);
	cvDestroyWindow("origin img");
	cvDestroyWindow("output img");
}

int main(int argc,char **argv)
{
	Mat img = imread("sushe.jpg");
	example2_4(img);
	return 0;
}