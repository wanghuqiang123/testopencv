#include "cv.h"
#include "highgui.h"

int main(int argc,char** argv)
{
	IplImage* src;

	char x1[2] = {'8','0'};
	char y1[2] = {'8','0'};
	char width1[2] = {'2','0'};
	char height1[2] = {'2','0'};
	char adds1[3] = {'1','0','0'};
	
	if( ( src = cvLoadImage("cameraman.tif",0)) != 0 )
	{
		int x = atoi( x1 );
		int y = atoi( y1 );
		int width = atoi( width1);
		int height = atoi( height1);
		int add = atoi(adds1);
		cvSetImageROI(src,cvRect(x,y,width,height));
		cvAddS(src,cvScalar(add),src);
		cvResetImageROI(src);
		cvNamedWindow("ROI_ADD",1);
		cvShowImage("ROI_Add",src);
		cvWaitKey();
	}
	
	return 0;
}

