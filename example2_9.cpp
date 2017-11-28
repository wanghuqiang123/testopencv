#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
int main(int argc,char**argv)
{
	Mat img_pyr,img_rgb,img_gry,img_pyr2,img_cny;
	img_rgb = imread("sushe.jpg");
	cvtColor(img_rgb,img_gry,CV_BGR2GRAY);
	pyrDown(img_gry,img_pyr);
	pyrDown(img_pyr,img_pyr2);
	Canny(img_pyr2,img_cny,10,100,3,true);
	int x = 16,y = 32;
	Vec3b intensity = img_rgb.at<Vec3b>(y,x);

	uchar blue = intensity[0];
	uchar green = intensity[1];
	uchar red = intensity[2];

	std::cout<<"at(x,y) = ("<<x<<","<<y<<"):(blue,green,red)=("<<(unsigned int)blue<<","<<(unsigned int)green<<","<<(unsigned int )red<<")"<<std::endl;
	std::cout<<"Gray pixel there is:"<<(unsigned int)img_gry.at<uchar>(y,x)<<std::endl;
	
	x /= 4;
	y /= 4;
	std::cout<<"pyramid2 pixel there is:"<<(unsigned int)img_pyr2.at<uchar>(y,x)<<std::endl;

	img_cny.at<uchar>(x,y) = 128;

	waitKey(0);
	return 0;
}