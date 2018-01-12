


/***************<learing opencv> test4-1.b***************/
#include"cv.h"
#include"highgui.h"
#include<stdio.h>
#include<iostream>
using namespace std;

CvRect rect;//���ο�  
bool draw = false;//��ǻ����ο��״̬  
bool draw_hist = false;//����������ʼ��ֱ��ͼ  
  
//����ֱ��ͼ�ĺ���  
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
    //����R,G,B����  
    cvSplit(src,r_img,g_img,b_img,NULL);  
    //�Ҷ�ת��  
    cvCvtColor(src,gray_img,CV_BGR2GRAY);  
    int size = 256;  
    float range[] = {0,255};  
    float* ranges[] = {range};  
    //����ֱ��ͼ  
    CvHistogram* r_hist = cvCreateHist(1,&size,CV_HIST_ARRAY,ranges,1);  
    CvHistogram* g_hist = cvCreateHist(1,&size,CV_HIST_ARRAY,ranges,1);  
    CvHistogram* b_hist = cvCreateHist(1,&size,CV_HIST_ARRAY,ranges,1);  
    CvHistogram* gray_hist = cvCreateHist(1,&size,CV_HIST_ARRAY,ranges,1);  
    //��ɫ����ֱ��ͼ  
    cvCalcHist(&r_img,r_hist,0,NULL);  
   
	IplImage* r_dst = cvCreateImage(cvSize(400,300),IPL_DEPTH_8U,3);  
   
	cvSet(r_dst,cvScalarAll(255),0);  
    
	float r_max = 0;  

    cvGetMinMaxHistValue(r_hist,NULL,&r_max,NULL,NULL);  
    
	double r_bin_width = (double)r_dst ->width / size;  
    double r_bin_unith = (double)r_dst ->height / r_max;//�߶ȱ���  
    for(int i = 0;i < size;++i)
	{  
        //��þ������ϽǺ����½�����  
        CvPoint p0 = cvPoint(i * r_bin_width,r_dst ->height);  
        CvPoint p1 = cvPoint((i + 1) * r_bin_width, r_dst ->height - cvGetReal1D(r_hist ->bins,i) * r_bin_unith);  //��CvHistogram�е�bins���������Ѿ��������Ҷȼ���������Ŀ���룻
        cvRectangle(r_dst,p0,p1,cvScalar(255,0,0),-1,8,0);//-1��ʾ��ʵ�ľ���	//���û����εĺ���������ͼ������
    }																	
  
    //��ɫ����ֱ��ͼ  
    cvCalcHist(&g_img,g_hist,0,NULL);  
    IplImage* g_dst = cvCreateImage(cvSize(400,300),IPL_DEPTH_8U,3);  
    cvSet(g_dst,cvScalarAll(255),0);  
    float g_max = 0;  
    cvGetMinMaxHistValue(g_hist,NULL,&g_max,NULL,NULL);  
    double g_bin_width = (double)g_dst ->width / size;  
    double g_bin_unith = (double)g_dst ->height / g_max;//�߶ȱ���  
    for(int i = 0;i < size;++i){  
        //��þ������ϽǺ����½�����  
        CvPoint p0 = cvPoint(i * g_bin_width,g_dst ->height);  
        CvPoint p1 = cvPoint((i + 1) * g_bin_width,  
            g_dst ->height - cvGetReal1D(g_hist ->bins,i) * g_bin_unith);  
        cvRectangle(g_dst,p0,p1,cvScalar(0,255,0),-1,8,0);//-1��ʾ��ʵ�ľ���  
    }  
  
    //��ɫ����ֱ��ͼ  
    cvCalcHist(&b_img,b_hist,0,NULL);  
    IplImage* b_dst = cvCreateImage(cvSize(400,300),IPL_DEPTH_8U,3);  
    cvSet(b_dst,cvScalarAll(255),0);  
    float b_max = 0;  
    cvGetMinMaxHistValue(b_hist,NULL,&b_max,NULL,NULL);  
    double b_bin_width = (double)b_dst ->width / size;  
    double b_bin_unith = (double)b_dst ->height / b_max;//�߶ȱ���  
    for(int i = 0;i < size;++i){  
        //��þ������ϽǺ����½�����  
        CvPoint p0 = cvPoint(i * b_bin_width,b_dst ->height);  
        CvPoint p1 = cvPoint((i + 1) * b_bin_width,  
            b_dst ->height - cvGetReal1D(b_hist ->bins,i) * b_bin_unith);  
        cvRectangle(b_dst,p0,p1,cvScalar(0,0,255),-1,8,0);//-1��ʾ��ʵ�ľ���  
    }  
  
    //�Ҷ�ͼֱ��ͼ  
    cvCalcHist(&gray_img,gray_hist,0,NULL);  
    IplImage* gray_dst = cvCreateImage(cvSize(400,300),IPL_DEPTH_8U,3);  
    cvSet(gray_dst,cvScalarAll(255),0);  
    float gray_max = 0;  
    cvGetMinMaxHistValue(gray_hist,NULL,&gray_max,NULL,NULL);  
    double gray_bin_width = (double)gray_dst ->width / size;  
    double gray_bin_unith = (double)gray_dst ->height / gray_max;//�߶ȱ���  
    for(int i = 0;i < size;++i){  
        //��þ����������������  
        CvPoint p0 = cvPoint(i * gray_bin_width,gray_dst ->height);  
        CvPoint p1 = cvPoint((i + 1) * gray_bin_width,  
            gray_dst ->height - cvGetReal1D(gray_hist ->bins,i) * gray_bin_unith);  //��Ϊԭ�������Ͻ�
        cvRectangle(gray_dst,p0,p1,cvScalar(0),-1,8,0);//-1��ʾ��ʵ�ľ���  
    }  
  
    //���ĸ�ֱ��ͼ��һ��ͼƬ����ʾ����  
    IplImage* dst = cvCreateImage(cvSize(800,600),8,3);  
    cvSetZero(dst);  
    //������ɫ����ֱ��ͼ  
    CvRect rect = cvRect(0,0,400,300);  
    cvSetImageROI(dst,rect);  
    cvCopy(r_dst,dst);  
    //������ɫ����ֱ��ͼ  
     rect = cvRect(400,0,400,300);  
    cvSetImageROI(dst,rect);  
    cvCopy(g_dst,dst);  
    //������ɫ����ֱ��ͼ  
    rect = cvRect(0,300,400,300);  
    cvSetImageROI(dst,rect);  
    cvCopy(b_dst,dst);  
    //�����Ҷ�ͼ����ֱ��ͼ  
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
  
//�ҵ������Ӧ����  
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
    //���ڴ汣�渱��  
    IplImage* temp = cvCloneImage(img);   //����һ��������ͼ�񸱱�
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


