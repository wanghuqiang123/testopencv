


/***************<learing opencv> test4-5.a***************/
#include"cv.h"
#include"highgui.h"
#include<iostream>
#include<math.h>

using namespace std;

bool erase = false;
bool draw_box = false;
bool draw_circle = false;
bool draw_line = false;
double circle_radio = 0;
IplImage* img = NULL;
CvRect box;
CvPoint circle_point;
int position = 0;
const char* text[5] = {"box","circle","ellipse","polygon","line"};
CvFont font;


void mymousecallback(int event,int x,int y,int flag,void* param);
void draw_box1(IplImage* image)
{
	cvRectangle( image,
				cvPoint(box.x,box.y),
				cvPoint(box.x+box.width,box.y+box.height),
				cvScalar(0,0,255),-1);
}
void draw_circle_function(IplImage* image,CvPoint circle_point )
{
	cvCircle(image,circle_point,(int)circle_radio,cvScalar(0,255,0),-1); 
}

void draw_line_function(IplImage* image)
{
	cvLine( image,
			cvPoint(box.x,box.y),
			cvPoint(box.x+box.width,box.y+box.height),
			cvScalar(255,0,0));
}
int main()
{  
	img = cvCreateImage(cvSize(1200,600),IPL_DEPTH_8U,3);
	cvNamedWindow("window");

	cvSetZero(img);
	box = cvRect(-1,-1,0,0);
	cvSetMouseCallback("window",mymousecallback,(void*)img);
	IplImage* tempimage = cvCloneImage(img);
	IplImage* img1 = cvCreateImage(cvSize(1200,600),IPL_DEPTH_8U,3);
	cvCopy(img,img1);
	cvCreateTrackbar("Selection of graphics","window",&position,4,NULL);
	cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX,1.0,1.0);
	while(1)
	{ 
		cvCopy(img,tempimage);
			if(draw_box)
			  {
				 draw_box1(tempimage);
			  }
			  if(draw_circle)
			  {
				draw_circle_function(tempimage,circle_point);
			  }
			  if(draw_line)
			  {
				  draw_line_function(tempimage);
			  }
		  if(erase)
		  {
			  cvCopy(img1,tempimage);
			  cvCopy(img1,img);
		  }
		  cvPutText(tempimage,text[position],cvPoint(50,50),&font,cvScalar(255,255,0));
		  cvShowImage("window",tempimage);
		  
		  
		  if(cvWaitKey(30) == 27)
			  break;
	}

	cvReleaseImage(&img);
	cvDestroyWindow("window");
	
	cvReleaseImage(&tempimage);
	cvReleaseImage(&img1);

	return 0;
}


void mymousecallback(int event,int x,int y,int flag,void* param)
{
	IplImage *img = (IplImage*)param;
	
	switch (event)
	{
		case CV_EVENT_MOUSEMOVE:
			switch (position)
			{
			case 0:
				if(draw_box)
				{
					box.width = x-box.x;
					box.height = y-box.y;
				}
				break;
			case 1:
				if(draw_circle)
				{
					circle_radio = sqrt((x-circle_point.x)*(x-circle_point.x)+(y-circle_point.y)*(y-circle_point.y));
				}
				break;
			case 4:
				if(draw_line)
				{
					box.width = x-box.x;
					box.height = y-box.y;
				}
				break;
			}
			break;
		case CV_EVENT_LBUTTONDOWN:
			switch (position)
			{
			case 0:
				{
					draw_box = true;
					box = cvRect(x,y,0,0);
				}
				break;
			case 1:
				{
					draw_circle = true;
					circle_point = cvPoint(x,y);
				}
				break;
			case 4:
				{
					draw_line = true;
					box = cvRect(x,y,0,0);
				}
				break;
			}
			break;
		case CV_EVENT_LBUTTONUP:
			switch (position)
			{
			case 0:
				{
				    draw_box = false;
					if(box.width<0)
					{
						box.x += box.width;
						box.width *= -1;
					}
					if(box.height<0)
					{
						box.y += box.height;
						box.height *= -1;
					}
					draw_box1(img);
				}
				break;
			case 1:
				{
					draw_circle = false;
					circle_radio = sqrt((x-circle_point.x)*(x-circle_point.x)+(y-circle_point.y)*(y-circle_point.y));
					draw_circle_function(img,circle_point);
					circle_radio = 0;
				}
				break;
			case 4:
				{				
				    draw_line = false;
					draw_line_function(img);
				}
				break;
			}
			break;
		case CV_EVENT_RBUTTONDOWN:
			{
				erase = true;
			}
			break;
		case CV_EVENT_RBUTTONUP:
			{
				erase = false;
			}
			break;
	}
}


