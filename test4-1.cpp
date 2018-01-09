


/***************<learing opencv> test4-1***************/
#include"cv.h"
#include"highgui.h"
#include<stdio.h>

int main(int argc,char** argv)
{
	cvNamedWindow("origin image");
	cvNamedWindow("gray image");
	cvNamedWindow("canny image");
	CvCapture* filecap = cvCreateFileCapture("imdata/traffic.avi");
	IplImage* frame;
	IplImage* frame1;
	IplImage* frame2;
	while(1)
	{
		if(filecap == NULL)
			break;
		frame = cvQueryFrame(filecap);
		frame1 = cvCreateImage(CvSize(cvGetSize(frame)),IPL_DEPTH_8U,1);
		frame2 = cvCreateImage(CvSize(cvGetSize(frame)),IPL_DEPTH_8U,1);
		cvConvertImage(frame,frame1,IPL_DEPTH_8U);
		cvCanny(frame,frame2,10,100);

		cvShowImage("origin image",frame);
		cvShowImage("gray image",frame1);
		cvShowImage("canny image",frame2);
		cvWaitKey(30);
		cvReleaseImage(&frame1);
	}
	cvDestroyWindow("origin image");
	cvDestroyWindow("gray image");
	cvDestroyWindow("canny image");
	cvReleaseImage(&frame2);
	cvReleaseImage(&frame1);
	cvReleaseCapture(&filecap);
	cvReleaseImage(&frame);
	return 0;
}


