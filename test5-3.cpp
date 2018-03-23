#include <cv.h>
#include <highgui.h>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	IplImage *img = cvLoadImage("imdata/shadow.tif");
	IplImage *copy_image1 = cvCloneImage(img); 
	IplImage *copy_image2 = cvCloneImage(img); 
	IplImage *copy_image3 = cvCloneImage(img); 

	cvNamedWindow("src");
	cvNamedWindow("parameter3 = 1");
	cvNamedWindow("parameter3 = 4");
	cvNamedWindow("parameter3 = 6");

	cvSmooth(img,copy_image1,CV_GAUSSIAN,0,0,9,9);//patrameter3 = sigma  sigma = (n/2-1)*0.3+0.8; ��parameter1,2 = 0ʱ  ��parameter3������1��2������Ȼ��1��2��������ֵʱ��3����Ϊ0ʱ  ��1��2����������sigma��
	cvSmooth(copy_image1,copy_image1,CV_GAUSSIAN,0,0,0,0);
	cvSmooth(img,copy_image2,CV_GAUSSIAN,0,0,4);
	cvSmooth(img,copy_image3,CV_GAUSSIAN,0,0,6);

	while(1)
	{
		cvShowImage("src",img);
		cvShowImage("parameter3 = 1",copy_image1);
	//	cvShowImage("parameter3 = 4",copy_image2);
	//	cvShowImage("parameter3 = 6",copy_image3);


		if(cvWaitKey(30) == 27)
			break;
	}

	cvDestroyWindow("src");
	cvDestroyWindow("parameter3 = 1");
	cvDestroyWindow("parameter3 = 4");
	cvDestroyWindow("parameter3 = 6");

	cvReleaseImage(&img);
	cvReleaseImage(&copy_image1);
	cvReleaseImage(&copy_image2);
	cvReleaseImage(&copy_image3);

	return 0;
	
}