 #include <cv.h>
#include <highgui.h>

using namespace std;
using namespace cv;
int main(int argc, char* argv[])
{
	IplImage *img = cvCreateImage(cvSize(100,100),8,1);
	cvNamedWindow("srcimg");
	cvNamedWindow("resultimg");
	cvZero(img);
	cvSet2D(img,50,50,255);
	IplImage* result_img = cvCloneImage(img);
	cvSmooth(img,result_img,CV_GAUSSIAN,5,5);

	while(1)
	{
		cvShowImage("srcimg",img);
		cvShowImage("resultimg",result_img);

		if(cvWaitKey(30) == 27)
			break;
	}
	cvDestroyWindow("srcimg");
	cvDestroyWindow("resultimg");

	cvReleaseImage(&img);
	cvReleaseImage(&result_img);

	return 0;
	
}