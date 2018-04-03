
/********** <learning opencv>test5-9.cpp  *********/
#include <iostream>
#include <cv.h>
#include <highgui.h>


using namespace std;
using namespace cv;



int main(int argc, char* argv[])
{
	IplImage* image = cvLoadImage("imdata/sushe1.jpg");
	IplImage* dst_image1 = cvCreateImage(cvSize(image->width/2,image->height/2),image->depth,image->nChannels);
	IplImage* dst_image2 = cvCreateImage(cvSize(dst_image1->width/2,dst_image1->height/2),dst_image1->depth,dst_image1->nChannels);
	IplImage* dst_image3 = cvCreateImage(cvSize(dst_image2->width/2,dst_image2->height/2),dst_image2->depth,dst_image2->nChannels);
	IplImage* dst_image4 = cvCreateImage(cvSize(image->width/2,image->height/2),image->depth,image->nChannels);
	IplImage* dst_image5 = cvCreateImage(cvSize(dst_image4->width/2,dst_image4->height/2),dst_image4->depth,dst_image4->nChannels);
	IplImage* dst_image6 = cvCreateImage(cvSize(dst_image5->width/2,dst_image5->height/2),dst_image5->depth,dst_image5->nChannels);

	cvResize(image,dst_image1);
	cvResize(dst_image1,dst_image2);
	cvResize(dst_image2,dst_image3);

	cvPyrDown(image,dst_image4);
	cvPyrDown(dst_image4,dst_image5);
	cvPyrDown(dst_image5,dst_image6);

	cvNamedWindow("src_image");
	cvNamedWindow("image1");
	cvNamedWindow("image2");
	cvNamedWindow("image3");
	cvNamedWindow("image4");
	cvNamedWindow("image5");
	cvNamedWindow("image6");
	while(1)
	{
		cvShowImage("src_image",image);
		cvShowImage("image1",dst_image1);
		cvShowImage("image2",dst_image2);
		cvShowImage("image3",dst_image3);
		cvShowImage("image4",dst_image4);
		cvShowImage("image5",dst_image5);
		cvShowImage("image6",dst_image6);
		if(cvWaitKey(30) == 27)
			break;
	}

	cvDestroyAllWindows();
	cvReleaseImage(&image);
	cvReleaseImage(&dst_image1);
	cvReleaseImage(&dst_image2);
	cvReleaseImage(&dst_image3);
	cvReleaseImage(&dst_image4);
	cvReleaseImage(&dst_image5);
	cvReleaseImage(&dst_image6);
	
	return 0;
}

//总结  降采样用高斯金字塔更好 图像越小但像素值比较清晰。