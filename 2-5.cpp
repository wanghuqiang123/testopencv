
#include"cv.h"
#include"highgui.h"
#define n 210
int main(int argc,char** argv)
{
	IplImage* img = cvCreateImage(cvSize(210,210),8,1); //����IplImage��������һ��ͼ�����
	cvSetZero(img);
	int x = 0;
	int y = 0;
	int width = n;
	int lenth = n;
	int value = 0;
	while(value <= 200)
	{
		cvSetImageROI(img,cvRect(x,y,width,lenth));
		cvSet(img,cvScalar(value)); //��Ϊ��Ϊ1ͨ����
		x += 10;
		y += 10;
		width -= 20;
		lenth -= 20;
		value += 20;
		//cvResetImageROI(img);  ÿ�α���Ҫ�ͷ�ָ��ROI��ָ�룻
	}
	cvNamedWindow("image");
	cvShowImage("image",img);
	cvWaitKey(0);

	cvDestroyWindow("video");
	cvReleaseImage(&img);

	return 0;
}

