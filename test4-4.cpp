


/***************<learing opencv> test4-1.b***************/
#include"cv.h"
#include"highgui.h"
#include<iostream>
using namespace std;

int positon = 0;
int on_off = 0;
bool temp = false;
CvCapture* cap = NULL;

void my_trackcallback_frame(int pos)
{
	cvSetCaptureProperty(cap,CV_CAP_PROP_POS_FRAMES,pos);
}
void my_trackcallback_on_off(int pos)
{
	if(pos == 1)
	{
		temp = true;
	}
	else if(pos == 0)
	{
		temp = false;
	}

}
int main()
{  
	cap = cvCreateFileCapture("imdata/traffic.avi");
	cvNamedWindow("window",CV_WINDOW_AUTOSIZE);
	IplImage* img;
	int frames = (int)cvGetCaptureProperty(cap,CV_CAP_PROP_FRAME_COUNT);
	cvCreateTrackbar("on_off","window",&on_off,1,my_trackcallback_on_off);
	cvCreateTrackbar("frame","window",&positon,frames,my_trackcallback_frame);
	img = cvQueryFrame(cap);
	while(1)
	{
		if(temp == true)
		{
			img = cvQueryFrame(cap);
			positon++;
		}
		if(!img)
			break;
		cvShowImage("window",img);
		cvSetTrackbarPos("frame","window",positon);
		
	
		if(cvWaitKey(30) == 27)
				break;
	}
	cvReleaseCapture(&cap);
	cvDestroyWindow("window");
	cvReleaseImage(&img);

	return 0;

}  


