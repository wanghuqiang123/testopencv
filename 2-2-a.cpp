
#include"cv.h"
#include"highgui.h"

int main(int argc,char** argv)
{
	CvMat* mat1 = cvCreateMat(100,100,CV_8UC3 );
	cvSetZero(mat1);
	CvPoint mat1_point = cvPoint(50,50);
	CvScalar mat1_scalar = cvScalar(0,0,255);
	cvNamedWindow("1");
	cvCircle(mat1,mat1_point,50,mat1_scalar);
	cvShowImage("1",mat1);
	cvWaitKey(0);
	return 0;
}

