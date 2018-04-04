
/********** <learning opencv>test5-12.cpp  *********/
#include <iostream>
#include <cv.h>
#include <highgui.h>


using namespace std;
using namespace cv;



int main(int argc, char* argv[])
{
	IplImage* src_image = cvLoadImage("imdata/autumn.tif",CV_LOAD_IMAGE_GRAYSCALE);
	IplImage* dat_image = cvCreateImage(cvSize(src_image->width,src_image->height),src_image->depth,src_image->nChannels);
	cvNamedWindow("src_image");
	cvNamedWindow("dst_image");

	cvAdaptiveThreshold(src_image,dat_image,255,CV_ADAPTIVE_THRESH_GAUSSIAN_C,CV_THRESH_BINARY,3,-5);

	cvShowImage("src_image",src_image);
	cvShowImage("dst_image",dat_image);

	cvWaitKey(0);

	cvDestroyAllWindows();
	cvReleaseImage(&src_image);
	cvReleaseImage(&dat_image);

	return 0;
}
