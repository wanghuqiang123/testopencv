#include<opencv2/opencv.hpp>
using namespace cv;
void example2_5(const Mat& image)
{
	namedWindow("originimage",WINDOW_AUTOSIZE);
	namedWindow("outputimage",WINDOW_AUTOSIZE);
	imshow("otiginimage",image);
	Mat outimg;
	GaussianBlur(image,outimg,Size(5,5),500,500);
	GaussianBlur(outimg,outimg,Size(5,5),200,200);
	imshow("outputimage",outimg);
	waitKey(50);
}
int main(int argc,char ** argv)
{
	VideoCapture capture(0);
	while(1)
	{
		Mat frame;
		capture>>frame;
		if(!frame.empty())
			example2_5(frame);
	}
	return 0;
}