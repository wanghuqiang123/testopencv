
/********** <learning opencv>test5-4.cpp  *********/
#include <iostream>
#include <cv.h>
#include <highgui.h>


using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	IplImage* src_image = cvLoadImage("imdata/binarycap.png",CV_LOAD_IMAGE_GRAYSCALE);
	CvConnectedComp m_connect = {0};
	CvPoint m_point = cvPoint(5,5);
	cvNamedWindow("dstimage");

	for(int y = 0;y<src_image->height;y++)
	{
		uchar* ptr = (uchar*)(src_image->imageData + y * src_image->widthStep);
		for(int x = 0;x<src_image->width;x++)
			if((int)(*ptr)==255)
			{
				cvFloodFill(src_image,cvPoint(x,y),cvScalar(100),cvScalar(0),cvScalar(0),&m_connect,(8|CV_FLOODFILL_FIXED_RANGE|0<<8),NULL);
				//漫水填充算法的好处是填充的区域是一个连通区域，其它的不连通的但灰度值相同的元素也是不想涂色的颜色可以不上色；
			}
	}
	cout<<m_connect.area<<endl;;
	while(1)
	{
		cvShowImage("dstimage",src_image);
		if(cvWaitKey(30) == 27)
			break;
	}

	cvReleaseImage(&src_image);
	cvDestroyWindow("dstimage");

	return 0;
}