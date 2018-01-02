
#include"cv.h"
#include"highgui.h"
#define n 210
int main(int argc,char** argv)
{
	IplImage* img = cvCreateImage(cvSize(210,210),8,1); //利用IplImage函数创建一个图像矩阵；
	cvSetZero(img);
	int x = 0;
	int y = 0;
	int width = n;
	int lenth = n;
	int value = 0;
	while(value <= 200)
	{
		cvSetImageROI(img,cvRect(x,y,width,lenth));
		cvSet(img,cvScalar(value)); //因为此为1通道；
		x += 10;
		y += 10;
		width -= 20;
		lenth -= 20;
		value += 20;
		//cvResetImageROI(img);  每次必须要释放指向ROI的指针；
	}
	cvNamedWindow("image");
	cvShowImage("image",img);
	cvWaitKey(0);

	cvDestroyWindow("video");
	cvReleaseImage(&img);

	return 0;
}

