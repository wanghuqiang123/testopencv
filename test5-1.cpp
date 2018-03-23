 #include <cv.h>
#include <highgui.h>

using namespace std;
using namespace cv;
int main(int argc, char* argv[])
{
	IplImage *srcimg = cvLoadImage("imdata/shadow.tif");
	
	cvNamedWindow("src");
	//cvNamedWindow("3*3");
	cvNamedWindow("5*5");
	//cvNamedWindow("9*9");
	cvNamedWindow("11*11");
	
	IplImage* copy_image1 = cvCreateImage(cvGetSize(srcimg),srcimg->depth,srcimg->nChannels);
	IplImage* copy_image2 = cvCreateImage(cvGetSize(srcimg),srcimg->depth,srcimg->nChannels);
	//IplImage* copy_image3 = cvCreateImage(cvGetSize(srcimg),srcimg->depth,srcimg->nChannels);
	IplImage* copy_image4 = cvCreateImage(cvGetSize(srcimg),srcimg->depth,srcimg->nChannels);
	
	//cvSmooth(srcimg,copy_image1,CV_GAUSSIAN,3,3);
	cvSmooth(srcimg,copy_image2,CV_GAUSSIAN,5,5);
	cvSmooth(copy_image2,copy_image2,CV_GAUSSIAN,5,5);
	//cvSmooth(srcimg,copy_image3,CV_GAUSSIAN,9,9);
	cvSmooth(srcimg,copy_image4,CV_GAUSSIAN,11,11);

	while(1)
	{
		cvShowImage("src",srcimg);
		//cvShowImage("3*3",copy_image1);
		cvShowImage("5*5",copy_image2);
		//cvShowImage("9*9",copy_image3);
		cvShowImage("11*11",copy_image4);
		
		if(cvWaitKey(100) == 27 )
			break;
	}

	cvDestroyWindow("src");
	//cvDestroyWindow("3*3");
	cvDestroyWindow("5*5");
	//cvDestroyWindow("9*9");
	cvDestroyWindow("11*11");

	cvReleaseImage(&srcimg);
	//cvReleaseImage(&copy_image1);
	cvReleaseImage(&copy_image2);
	//cvReleaseImage(&copy_image3);
	cvReleaseImage(&copy_image4);

	return 0;
	
}