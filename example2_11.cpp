#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
int main(int argc,char**argv)
{
	namedWindow("originimage",WINDOW_AUTOSIZE);
	namedWindow("outputimage",WINDOW_AUTOSIZE);
	VideoCapture capture(0);
	double fps = capture.get(CAP_PROP_FRAME_WIDTH);
	cv::Size size((int)capture.get(CAP_PROP_FRAME_WIDTH),(int)capture.get(CAP_PROP_FRAME_HEIGHT));

	VideoWriter writer;
	writer.open("2.avi",CV_FOURCC('M','J','P','G'),fps,size);

	Mat logpolar_frame,bgr_frame;
	for(;;)
	{
		capture>>bgr_frame;
		if(bgr_frame.empty())
			break;
		imshow("originimage",bgr_frame);
		logPolar(bgr_frame,logpolar_frame,Point2f(bgr_frame.cols/2,bgr_frame.rows/2),40,WARP_FILL_OUTLIERS);
		imshow("outputimage",logpolar_frame);
		writer<<logpolar_frame;
		char c = waitKey(10);
		if(c == 27) 
			break;
	}
	capture.release();
	return 0;
}