
#include"cv.h"
#include"highgui.h"
#include<stdio.h>

int main(int argc,char** argv)
{
	IplImage* img = cvLoadImage("imdata/eight.tif");  //读取一幅图像；
	IplImage* img1 = cvCreateImageHeader(cvSize(20,30),img->depth,img->nChannels); //利用cvcreateimageheader()函数设置它的尺寸大小和深度与通道数；
	IplImage* img2 = cvCreateImageHeader(cvSize(20,30),img->depth,img->nChannels);
	img1->origin = img->origin;
	img2->origin = img->origin;			//将原点与img的原点设置为相同；
	img1->widthStep = img->widthStep;
	img2->widthStep = img->widthStep;
	img1->imageData = img->imageData + 5 * img->widthStep + 10 * img->nChannels;//imagedata指向图像的头元素，将原图像的头指针移动指向相关的区域；
	img2->imageData = img->imageData + 50 * img->widthStep + 60 * img->nChannels;
	cvNot(img1,img1);
	cvNot(img2,img2);	//取反img1中的元素，然后将重新复制给img1，因为地址是img中；
	
	cvNamedWindow("image");
	cvShowImage("image",img);
	cvWaitKey(0);

	cvDestroyWindow("video");
	cvReleaseImage(&img);

	return 0;
}

