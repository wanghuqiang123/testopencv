

//掩码图像就是一个矩阵数据。里面有Width*Height个数据。像素值为0表示这点像素不处理，为1表示要处理
/***************<learing opencv> 练习2中的7小问的答案***************/
#include"cv.h"
#include"highgui.h"
#include<stdio.h>

int main(int argc,char** argv)
{
	IplImage* img = cvLoadImage("imdata/eight.tif");  //读取一幅图像；
	IplImage* rImg = cvCreateImage(cvGetSize(img), img->depth, 1);
	IplImage* gImg = cvCreateImage(cvGetSize(img), img->depth, 1);
	IplImage* bImg = cvCreateImage(cvGetSize(img), img->depth, 1);  //创建单通道r,g,b图像
	
	IplImage* clone1 = cvCreateImage(cvGetSize(img), img->depth, 1);
	IplImage* clone2 = cvCreateImage(cvGetSize(img), img->depth, 1);
	double green_maxPixel = 0;
	double green_minPixel = 0; //绿色平面最大最小值
	double thresh;  //阈值thresh
	cvSplit(img, rImg, gImg, bImg,NULL); //拆分3通道
	
	/*克隆两次*/
	cvCopy(gImg,clone1);
	cvCopy(gImg,clone2);

	/*求取最大值和最小值*/
	cvMinMaxLoc(gImg,&green_minPixel,&green_maxPixel);
	printf("the min is %d,the max is %d",green_minPixel,green_maxPixel);

	/*将clone1的所有元素复制的thresh*/
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

