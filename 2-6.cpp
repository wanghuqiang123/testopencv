
#include"cv.h"
#include"highgui.h"
#include<stdio.h>

int main(int argc,char** argv)
{
	IplImage* img = cvLoadImage("imdata/eight.tif");  //��ȡһ��ͼ��
	IplImage* img1 = cvCreateImageHeader(cvSize(20,30),img->depth,img->nChannels); //����cvcreateimageheader()�����������ĳߴ��С�������ͨ������
	IplImage* img2 = cvCreateImageHeader(cvSize(20,30),img->depth,img->nChannels);
	img1->origin = img->origin;
	img2->origin = img->origin;			//��ԭ����img��ԭ������Ϊ��ͬ��
	img1->widthStep = img->widthStep;
	img2->widthStep = img->widthStep;
	img1->imageData = img->imageData + 5 * img->widthStep + 10 * img->nChannels;//imagedataָ��ͼ���ͷԪ�أ���ԭͼ���ͷָ���ƶ�ָ����ص�����
	img2->imageData = img->imageData + 50 * img->widthStep + 60 * img->nChannels;
	cvNot(img1,img1);
	cvNot(img2,img2);	//ȡ��img1�е�Ԫ�أ�Ȼ�����¸��Ƹ�img1����Ϊ��ַ��img�У�
	
	cvNamedWindow("image");
	cvShowImage("image",img);
	cvWaitKey(0);

	cvDestroyWindow("video");
	cvReleaseImage(&img);

	return 0;
}

