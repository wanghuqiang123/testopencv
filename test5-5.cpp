
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
		//a :取其差的绝对值并显示出来，带有噪声的水杯掩码
		cvSub(src_image1,src_image2,dst_a,NULL);
		cvAbs(dst_a,dst_a);
		//b :对图像进行二值化阈值操作,
		cvThreshold(dst_a,dst_b,15,255,CV_THRESH_BINARY_INV);
		//c :对图像进行 CV_MOP_OPEN 操作,进一步清除噪声
		IplConvKernel* temp=cvCreateStructuringElementEx(3,3,1,1,CV_SHAPE_RECT,NULL);
		cvMorphologyEx(dst_b,dst_c,NULL,temp,CV_MOP_OPEN);
		cvReleaseStructuringElement(&temp);
		cvNamedWindow("未放水杯");
		cvNamedWindow("放水杯后");
		cvNamedWindow("取差的绝对值");
		cvNamedWindow("二值化阈值");
		cvNamedWindow("开运算");
		cvShowImage("未放水杯",src_image1);
		cvShowImage("放水杯后",src_image2);
		cvShowImage("取差的绝对值",dst_a);
		cvShowImage("二值化阈值",dst_b);
		cvShowImage("开运算",dst_c);
		cvWaitKey();
		cvReleaseImage(&src_image1);
		cvReleaseImage(&src_image2);
		cvReleaseImage(&dst_a);
		cvReleaseImage(&dst_b);
		cvReleaseImage(&dst_c);
		cvDestroyAllWindows();
		return 0;
	
}