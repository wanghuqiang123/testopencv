
/********** <learning opencv>test5-4.cpp  *********/
#include <iostream>
#include <cv.h>
#include <highgui.h>


using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
		IplImage* src_image1=cvLoadImage("imdata/glass1.bmp",CV_LOAD_IMAGE_GRAYSCALE);
		assert(src_image1!=NULL);
		IplImage* src_image2=cvLoadImage("imdata/glass2.bmp",CV_LOAD_IMAGE_GRAYSCALE);
		assert(src_image2!=NULL);
		IplImage *dst_a=cvCloneImage(src_image1);
		assert(dst_a!=NULL);
		IplImage *dst_b=cvCloneImage(src_image1);
		assert(dst_b!=NULL);
		IplImage *dst_c=cvCloneImage(src_image1);
		assert(dst_c!=NULL);
		//a :ȡ���ľ���ֵ����ʾ����������������ˮ������
		cvSub(src_image1,src_image2,dst_a,NULL);
		cvAbs(dst_a,dst_a);
		//b :��ͼ����ж�ֵ����ֵ����,
		cvThreshold(dst_a,dst_b,15,255,CV_THRESH_BINARY_INV);
		//c :��ͼ����� CV_MOP_OPEN ����,��һ���������
		IplConvKernel* temp=cvCreateStructuringElementEx(3,3,1,1,CV_SHAPE_RECT,NULL);
		cvMorphologyEx(dst_b,dst_c,NULL,temp,CV_MOP_OPEN);
		cvReleaseStructuringElement(&temp);
		cvNamedWindow("δ��ˮ��");
		cvNamedWindow("��ˮ����");
		cvNamedWindow("ȡ��ľ���ֵ");
		cvNamedWindow("��ֵ����ֵ");
		cvNamedWindow("������");
		cvShowImage("δ��ˮ��",src_image1);
		cvShowImage("��ˮ����",src_image2);
		cvShowImage("ȡ��ľ���ֵ",dst_a);
		cvShowImage("��ֵ����ֵ",dst_b);
		cvShowImage("������",dst_c);
		cvWaitKey();
		cvReleaseImage(&src_image1);
		cvReleaseImage(&src_image2);
		cvReleaseImage(&dst_a);
		cvReleaseImage(&dst_b);
		cvReleaseImage(&dst_c);
		cvDestroyAllWindows();
		return 0;
	
}