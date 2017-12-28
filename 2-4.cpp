
#include"cv.h"
#include"highgui.h"

int main(int argc,char** argv)
{
	int x = 20;
	int y = 5;
	CvMat* mat1 = cvCreateMat(100,100,CV_8UC3 ); //CV_8UC3为无符号8位3通道；
	cvSetZero(mat1);
	CvScalar mat1_scalar = cvScalar(0,255,0);
	CvPoint mat1_point1 = cvPoint(20,5);
	CvPoint mat1_point2 = cvPoint(40,20);
	cvRectangle(mat1,mat1_point1,mat1_point2,mat1_scalar);
	for(x = 20;x<40;x++)
	{
		for(y = 5;y<20;y++)
		{
			cvSet2D(mat1,y,x,mat1_scalar);//设置矩阵中像素点的数值；
		}
	}

	cvNamedWindow("1");
	cvShowImage("1",mat1);
	cvWaitKey(0);
	cvReleaseMat(&mat1);
	cvDestroyWindow("1");
	
	return 0;
}

