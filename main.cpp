#include<opencv2/opencv.hpp>
using namespace cv;


int main(int argc,char ** argv)
{
	
	VideoCapture capture("imdata/traffic.avi");
	
	while(1)
	{
		Mat frame;
	
		capture>>frame;
		if(frame.empty())
			break;
		imshow("1",frame);
		 waitKey(30);
		
	}
	
	return 0;
}