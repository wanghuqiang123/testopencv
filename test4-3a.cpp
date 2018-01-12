


/***************<learing opencv> test4-1.b***************/
#include"cv.h"
#include"highgui.h"
#include<stdio.h>
#include<iostream>
using namespace std;

CvRect rect;//矩形框  
bool draw = false;//标记画矩形框的状态  
bool draw_hist = false;//鼠标左键弹起开始画直方图  
  
//绘制直方图的函数  
void draw_rect(IplImage* img,CvRect rect){  
    cvSetImageROI(img,rect);  
    IplImage* src= cvCreateImage(  
        cvSize(rect.width,rect.height),  
        IPL_DEPTH_8U,  
        3);  
    cvCopy(img,src);  
    cvResetImageROI(img);  
    IplImage* r_img = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);  
    IplImage* g_img = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);  
    IplImage* b_img = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);  
    IplImage* gray_img = cvCreateImage(cvGetSize(src),IPL_DEPTH_8U,1);  
    //分离R,G,B分量  
    cvSplit(src,r_img,g_img,b_img,NULL);  
    //灰度转换  
    cvCvtColor(src,gray_img,CV_BGR2GRAY);  
    int size = 256;  
    float range[] = {0,255};  
    float* ranges[] = {range};  
    //创建直方图  
    CvHistogram* r_hist = cvCreateHist(1,&size,CV_HIST_ARRAY,ranges,1);  
    CvHistogram* g_hist = cvCreateHist(1,&size,CV_HIST_ARRAY,ranges,1);  
    CvHistogram* b_hist = cvCreateHist(1,&size,CV_HIST_ARRAY,ranges,1);  
    CvHistogram* gray_hist = cvCreateHist(1,&size,CV_HIST_ARRAY,ranges,1);  
    //红色分量直方图  
    cvCalcHist(&r_img,r_hist,0,NULL);  
   
	IplImage* r_dst = cvCreateImage(cvSize(400,300),IPL_DEPTH_8U,3);  
   
	cvSet(r_dst,cvScalarAll(255),0);  
    
	float r_max = 0;  

    cvGetMinMaxHistValue(r_hist,NULL,&r_max,NULL,NULL);  
    
	double r_bin_width = (double)r_dst ->width / size;  
    double r_bin_unith = (double)r_dst ->height / r_max;//高度比例  
    for(int i = 0;i < size;++i)
	{  
        //获得矩形左上角和右下角坐标  
        CvPoint p0 = cvPoint(i * r_bin_width,r_dst ->height);  
        CvPoint p1 = cvPoint((i + 1) * r_bin_width, r_dst ->height - cvGetReal1D(r_hist ->bins,i) * r_bin_unith);  //在CvHistogram中的bins变量数组已经将各个灰度级的像素数目放入；
        cvRectangle(r_dst,p0,p1,cvScalar(255,0,0),-1,8,0);//-1表示画实心矩形	//利用画矩形的函数当做画图函数。
    }																	
  
    //绿色分量直方图  
    cvCalcHist(&g_img,g_hist,0,NULL);  
    IplImage* g_dst = cvCreateImage(cvSize(400,300),IPL_DEPTH_8U,3);  
    cvSet(g_dst,cvScalarAll(255),0);  
    float g_max = 0;  
    cvGetMinMaxHistValue(g_hist,NULL,&g_max,NULL,NULL);  
    double g_bin_width = (double)g_dst ->width / size;  
    double g_bin_unith = (double)g_dst ->height / g_max;//高度比例  
    for(int i = 0;i < size;++i){  
        //获得矩形左上角和右下角坐标  
        CvPoint p0 = cvPoint(i * g_bin_width,g_dst ->height);  
        CvPoint p1 = cvPoint((i + 1) * g_bin_width,  
            g_dst ->height - cvGetReal1D(g_hist ->bins,i) * g_bin_unith);  
        cvRectangle(g_dst,p0,p1,cvScalar(0,255,0),-1,8,0);//-1表示画实心矩形  
    }  
  
    //蓝色分量直方图  
    cvCalcHist(&b_img,b_hist,0,NULL);  
    IplImage* b_dst = cvCreateImage(cvSize(400,300),IPL_DEPTH_8U,3);  
    cvSet(b_dst,cvScalarAll(255),0);  
    float b_max = 0;  
    cvGetMinMaxHistValue(b_hist,NULL,&b_max,NULL,NULL);  
    double b_bin_width = (double)b_dst ->width / size;  
    double b_bin_unith = (double)b_dst ->height / b_max;//高度比例  
    for(int i = 0;i < size;++i){  
        //获得矩形左上角和右下角坐标  
        CvPoint p0 = cvPoint(i * b_bin_width,b_dst ->height);  
        CvPoint p1 = cvPoint((i + 1) * b_bin_width,  
            b_dst ->height - cvGetReal1D(b_hist ->bins,i) * b_bin_unith);  
        cvRectangle(b_dst,p0,p1,cvScalar(0,0,255),-1,8,0);//-1表示画实心矩形  
    }  
  
    //灰度图直方图  
    cvCalcHist(&gray_img,gray_hist,0,NULL);  
    IplImage* gray_dst = cvCreateImage(cvSize(400,300),IPL_DEPTH_8U,3);  
    cvSet(gray_dst,cvScalarAll(255),0);  
    float gray_max = 0;  
    cvGetMinMaxHistValue(gray_hist,NULL,&gray_max,NULL,NULL);  
    double gray_bin_width = (double)gray_dst ->width / size;  
    double gray_bin_unith = (double)gray_dst ->height / gray_max;//高度比例  
    for(int i = 0;i < size;++i){  
        //获得矩形两个顶点的坐标  
        CvPoint p0 = cvPoint(i * gray_bin_width,gray_dst ->height);  
        CvPoint p1 = cvPoint((i + 1) * gray_bin_width,  
            gray_dst ->height - cvGetReal1D(gray_hist ->bins,i) * gray_bin_unith);  //因为原点在左上角
        cvRectangle(gray_dst,p0,p1,cvScalar(0),-1,8,0);//-1表示画实心矩形  
    }  
  
    //把四个直方图在一幅图片上显示出来  
    IplImage* dst = cvCreateImage(cvSize(800,600),8,3);  
    cvSetZero(dst);  
    //拷贝红色分量直方图  
    CvRect rect = cvRect(0,0,400,300);  
    cvSetImageROI(dst,rect);  
    cvCopy(r_dst,dst);  
    //拷贝绿色分量直方图  
     rect = cvRect(400,0,400,300);  
    cvSetImageROI(dst,rect);  
    cvCopy(g_dst,dst);  
    //拷贝蓝色分量直方图  
    rect = cvRect(0,300,400,300);  
    cvSetImageROI(dst,rect);  
    cvCopy(b_dst,dst);  
    //拷贝灰度图分量直方图  
    rect = cvRect(400,300,400,300);  
    cvSetImageROI(dst,rect);  
    cvCopy(gray_dst,dst);  
  
    cvResetImageROI(dst);  
  
    cvNamedWindow("src",1);  
    cvShowImage("src",src);  
    cvNamedWindow("dst",1);  
    cvShowImage("dst",dst);  
    cvSaveImage("dst.jpg",dst);  
    cvWaitKey(0);  
    cvDestroyAllWindows();  
    cvReleaseImage(&r_img);  
    cvReleaseImage(&g_img);  
    cvReleaseImage(&b_img);  
    cvReleaseImage(&gray_img);  
    cvReleaseImage(&src);  
    cvReleaseImage(&dst);  
    cvReleaseImage(&r_dst);  
    cvReleaseImage(&g_dst);  
    cvReleaseImage(&b_dst);  
          
}  
  
//我的鼠标响应函数  
void my_mouse_callback(  
                       int event,  
                       int x,  
                       int y,  
                       int flags,  
                       void* param){  
    IplImage* img = (IplImage*)param;  
    switch(event){  
        case CV_EVENT_MOUSEMOVE:{  
            if(draw){  
                rect.width = x - rect.x;  
                rect.height = y - rect.y;  
            }  
            draw_hist = false;  
        }  
        break;  
        case CV_EVENT_LBUTTONDOWN:{  
            draw = true;  
            rect = cvRect(x,y,0,0);  
            draw_hist = false;  
        }  
        break;  
        case CV_EVENT_LBUTTONUP:{  
            draw = false;  
            draw_hist = true;  
            if(rect.width < 0){  
                rect.x += rect.width;  
                rect.width *= -1;  
            }  
            if(rect.height < 0){  
                rect.y += rect.height;  
                rect.height *= -1;  
            }  
            draw_rect(img,rect);  
        }  
        break;  
    }  
}  
  
int main(){  
    IplImage* img = cvLoadImage("imdata/football.jpg");  
    rect = cvRect(-1,-1,0,0);  
    cvNamedWindow("draw rect");  
    //在内存保存副本  
    IplImage* temp = cvCloneImage(img);   //创建一个真正的图像副本
    cvSetMouseCallback("draw rect",  
        my_mouse_callback,  
        (void*)img  
        );  
    while(1){  
        cvCopy(img,temp);  
        if(draw_hist){  
            draw_rect(temp,rect);  
        }  
        cvShowImage("draw rect",temp);  
        if(cvWaitKey(15) == 27)break;  
    }  
    cvReleaseImage(&img);  
    cvReleaseImage(&temp);  
    cvDestroyWindow("draw rect");  
}  


