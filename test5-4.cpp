
/********** <learning opencv>test5-4.cpp  *********/
#include <cv.h>
#include <highgui.h>
#include <iostream>


using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	IplImage *src = cvLoadImage("imdata/sushe1.jpg");
	IplImage *src1 = cvLoadImage("imdata/sushe2.jpg");
	IplImage *dst = cvCreateImage(cvGetSize(src),src->depth,src->nChannels);
	cvAbsDiff(src,src1,dst);
	cvNamedWindow("dst",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("src",CV_WINDOW_AUTOSIZE);
	cvErode(dst,dst);
	cvDilate(dst,dst);

	while(1)
	{
		cvShowImage("src",src);
		cvShowImage("dst",dst);
		if(cvWaitKey(30) == 27)
			break;
	}

	cvDestroyWindow("dst");
	cvDestroyWindow("src");

	cvReleaseImage(&dst);
	cvReleaseImage(&src);
	cvReleaseImage(&src1);
	


	return 0;
	
}