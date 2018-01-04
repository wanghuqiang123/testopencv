


/***************<learing opencv> ��ϰ2�е�7С�ʵĴ�***************/
#include"cv.h"
#include"highgui.h"
#include<stdio.h>

int main(int argc,char** argv)
{
	IplImage* img = cvLoadImage("imdata/eight.tif");  //��ȡһ��ͼ��
	IplImage* rImg = cvCreateImage(cvGetSize(img), img->depth, 1);
	IplImage* gImg = cvCreateImage(cvGetSize(img), img->depth, 1);
	IplImage* bImg = cvCreateImage(cvGetSize(img), img->depth, 1);  //������ͨ��r,g,bͼ��
	
	IplImage* clone1 = cvCreateImage(cvGetSize(img), img->depth, 1);
	IplImage* clone2 = cvCreateImage(cvGetSize(img), img->depth, 1);
	double green_maxPixel = 0;
	double green_minPixel = 0; //��ɫƽ�������Сֵ
	double thresh;  //��ֵthresh
	cvSplit(img, rImg, gImg, bImg,NULL); //���3ͨ��
	
	/*��¡����*/
	cvCopy(gImg,clone1);
	cvCopy(gImg,clone2);

	/*��ȡ���ֵ����Сֵ*/
	cvMinMaxLoc(gImg,&green_minPixel,&green_maxPixel);
	printf("the min is %d,the max is %d",green_minPixel,green_maxPixel);

	/*��clone1������Ԫ�ظ��Ƶ�thresh*/
	thresh = green_maxPixel - green_minPixel;
	cvSet(clone1,thresh);

	/* e*/
	cvSetZero(clone2);
	cvCmp(gImg,clone1,clone2,2);
	
	/*f*/
	cvSubS(gImg,thresh/2,gImg,clone2);

	cvNamedWindow("image");
	cvShowImage("image",img);
	cvNamedWindow("change image");
	cvShowImage("change image",gImg);
	cvWaitKey(0);

	cvDestroyWindow("video");
	cvReleaseImage(&img);
	cvReleaseImage(&rImg);
	cvReleaseImage(&gImg);
	cvReleaseImage(&bImg);
	cvReleaseImage(&clone1);
	cvReleaseImage(&clone2);

	return 0;
}

