


/***************<learing opencv> test4-6************/
#include<cv.h>
#include<highgui.h>
#include<iostream>
#include<math.h>

using namespace std;

bool text;
CvFont font;
void myMouseCallback(int event,int x,int y,int flags,void* image)
{
	IplImage* img = (IplImage*)image;

	if(event == CV_EVENT_LBUTTONDOWN)
	{
		cvPutText(img,"image",cvPoint(x,y),&font,cvScalar(0,255,0));
	}
}

int main(int argc,char** argv)
{
	IplImage* img = cvCreateImage(cvSize(600,600),8,3);
	cvSetZero(img);
	cvNamedWindow("image");
	cvShowImage("image",img);
	cvSetMouseCallback("image",myMouseCallback,(void*)img);
	cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX,1.0,1.0);
	while(1)
	{
		cvShowImage("image",img);
		if( cvWaitKey(30) == 27 )
			break;
	}

	cvDestroyWindow("image");
	cvReleaseImage(&img);

	return 0;
}

