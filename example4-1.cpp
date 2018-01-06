


/***************<learing opencv> ***************/
#include"cv.h"
#include"highgui.h"
#include<stdio.h>

void my_mouse_callback(int event,int x,int y,int flags,void* param);
CvRect box;
bool drawing_box = false;

void draw_box(IplImage* img,CvRect rect)
{
	cvRectangle(img,cvPoint(box.x , box.y),cvPoint(box.x + box.width ,box.y + box.height),cvScalar(0xff,0x00,0x00) );
}

int main(int argc,char** argv)
{
	box = cvRect(-1,-1,0,0);
	IplImage* image = cvCreateImage(cvSize(600,600),IPL_DEPTH_8U,3 );

	cvZero(image);
	IplImage* temp = cvCloneImage(image);
	cvNamedWindow("box example");

	cvSetMouseCallback("box example",my_mouse_callback,(void*) image); //在opencv中注册此回调函数 my_mouse_callback()为回调函数名，

	/**  当注册回调函数后 每次当在窗口中有鼠标事件发生时便会产生触发事件来调用回调函数 */
	while(1)
	{
		cvCopy(image,temp);
		if(drawing_box)
			draw_box(temp,box);
		cvShowImage("box example",temp);

		if(cvWaitKey( 15 ) == 27)
			break;
	}

	cvReleaseImage(&image);
	cvReleaseImage(&temp);
	cvDestroyWindow("box example");
	
	return 0;
}


void my_mouse_callback(int event,int x,int y,int flags,void* param)  //回调函数必须满足规定的形参列表格式  才能与opencv匹配
	{
		IplImage* image = (IplImage*) param;

		switch (event)
		{
		case CV_EVENT_MOUSEMOVE:
			{
				if(drawing_box)
				{
					box.width = x - box.x;
					box.height = y - box.y;
				}
			}
			break;
		case CV_EVENT_LBUTTONDOWN:
			{
				drawing_box = true;
				box = cvRect(x,y,0,0);
			}
			break;
		case CV_EVENT_LBUTTONUP:
			{
				drawing_box = false;
				if(box.width < 0)
				{
					box.x += box.width;
					box.width *= -1;
				}
				if(box.height < 0)
				{
					box.y += box.height;
					box.height *= -1;
				}
				draw_box(image,box);
			}
			break;
		}
	}

