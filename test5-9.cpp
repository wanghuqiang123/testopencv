
/********** <learning opencv>test5-9.cpp  *********/
#include <iostream>
#include <cv.h>
#include <highgui.h>


using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	IplImage* src_img = cvLoadImage("imdata/trees.tif",CV_LOAD_IMAGE_GRAYSCALE);
	IplImage* image = cvCloneImage(src_img);

	cvNamedWindow("src_image");
	cvNamedWindow("dst_image");
	cvNamedWindow("image1");

	IplConvKernel* temp = cvCreateStructuringElementEx(3,3,1,1,CV_SHAPE_RECT);
	cvMorphologyEx(src_img,image,NULL,temp,CV_MOP_TOPHAT);
	
	IplImage* image1 = cvCreateImage(cvGetSize(image),IPL_DEPTH_8U,1);
	cvSmooth(image,image1,CV_BLUR,5,5,0,0);
	cvThreshold(image,image1,30,255,CV_THRESH_BINARY);

	while(1)
	{
		cvShowImage("src_image",src_img);
		cvShowImage("dst_image",image);
		cvShowImage("image1",image1);
		if(cvWaitKey(30) == 27)
			break;
	}

	cvDestroyAllWindows();
	cvReleaseImage(&src_img);
	cvReleaseImage(&image);
	cvReleaseImage(&image1);
	return 0;
}