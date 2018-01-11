


/***************<learing opencv> test4-1.b***************/
#include"cv.h"
#include"highgui.h"
#include<stdio.h>
#include<iostream>
using namespace std;

CvRect rect;//矩形框  
bool draw = false;//标记画的状态  
  
void draw_rect(IplImage* img,CvRect rect)
{  
    cvRectangle(img,  
        cvPoint(rect.x,rect.y),  
        cvPoint(rect.x + rect.width,rect.y + rect.height),  
        cvScalar(0x00,0x00,0xff));  
}  
  
void my_mouse_callback(  
                       int event,  
                       int x,  
                       int y,  
                       int flags,  
                       void* param){  
    IplImage* img = (IplImage*)param;  
	IplImage* temp = cvCloneImage(img);  
    switch(event){  
        case CV_EVENT_MOUSEMOVE:{  
            if(draw){  
                rect.width = x - rect.x;  
                rect.height = y - rect.y;  
            }                     
        }  
        break;  
        case CV_EVENT_LBUTTONDOWN:{  
            draw = true;  
            rect = cvRect(x,y,0,0);  
        }  
        break;  
        case CV_EVENT_LBUTTONUP:{  
            draw = false;  
            if(rect.width < 0){  
                rect.x += rect.width;  
                rect.width *= -1;  
            }  
            if(rect.height < 0){  
                rect.y += rect.height;  
                rect.height *= -1;  
            }  
           
        }  
        break;  
    }  
}  
  
int main(){  
    IplImage* img = cvLoadImage("imdata/football.jpg");  
    rect = cvRect(-1,-1,0,0);  
    cvNamedWindow("draw rect");  
    //在内存保存副本  
    IplImage* temp = cvCloneImage(img);  
    cvSetMouseCallback("draw rect",  
        my_mouse_callback,  
        (void*)img  
        );  
    while(1){  
    
        if(draw){  
			 cvCopy(img,temp);  
            draw_rect(temp,rect);  
        }  
        cvShowImage("draw rect",temp);  
        if(cvWaitKey(15) == 27)break;  
    }  
    cvReleaseImage(&img);  
    cvReleaseImage(&temp);  
    cvDestroyWindow("draw rect");  
}  


