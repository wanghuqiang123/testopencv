


/***************<learing opencv> test4-1.b***************/
#include"cv.h"
#include"highgui.h"
#include<stdio.h>
//Canny��Ե����㷨  
IplImage* doCanny(  
    IplImage* in,  
    int lowThresh,  
    int highThresh,  
    int aperture  
    ){  
        if(in->nChannels != 1)return 0;  
        IplImage* out = cvCreateImage(  
            cvGetSize(in),  
            IPL_DEPTH_8U,  
            1);  
        cvCanny(in,out,lowThresh,highThresh,aperture);  
        return out;  
}  
  
int main()
{  
    CvCapture* capture = cvCreateFileCapture("imdata/traffic.avi");  
    //������������һ������������ʾ  
    cvNamedWindow("window_all");  
  
    //��Ƶ��ÿһ֡  
    IplImage* frame = NULL;  
    frame = cvQueryFrame(capture);  
    //��Ƶ֡ͼ��Ŀ�Ⱥ͸߶�  
    int width = (int)cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_WIDTH);  
    int height = (int)cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_HEIGHT);  
    //�������֣���Ϊ��ʹ����ͼ���ͨ����һ��������һ����ʾ  
    //��ͨ���Ҷ�ͼ��  
    IplImage* gray = cvCreateImage(  
        cvSize(width, height),  
        IPL_DEPTH_8U,  
        1);  
    //3ͨ���Ҷ�ͼ��  
  /*  IplImage* frame_gray = cvCreateImage(  
        cvSize(width, height),  
        IPL_DEPTH_8U,  
        3);  */
    //��ͨ��Canny��Ե���ͼ��  
    IplImage* Canny = cvCreateImage(  
        cvSize(width, height),  
        IPL_DEPTH_8U,  
        1);  
    //3ͨ��Canny��Ե���ͼ��  
    IplImage* frame_Canny = cvCreateImage(  
        cvSize(width, height),  
        IPL_DEPTH_8U,  
        3);  
    //��3��ͼ�����һ����ʾ  
    IplImage* frame_all = cvCreateImage(  
        cvSize(width * 3,height),  
        IPL_DEPTH_8U,  
        frame ->nChannels);  
    cvZero(frame_all);  
    //��������ͼ��ͷ  
    IplImage* img1 = cvCreateImageHeader(cvSize(width, height),frame ->depth,3);  
    IplImage* img2 = cvCreateImageHeader(cvSize(width, height),frame ->depth,3);  
    IplImage* img3 = cvCreateImageHeader(cvSize(width, height),frame ->depth,3);  
    img1 ->origin = frame ->origin;  
    img1 ->widthStep = frame_all ->widthStep;  
    img1->depth = frame->depth;  
    img1 ->nChannels = 3;  
    img2 ->origin = frame ->origin;  
    img2 ->widthStep = frame_all ->widthStep;  
    img2->depth = frame->depth;  
    img2 ->nChannels = 3;  
    img3 ->origin = frame ->origin;  
    img3 ->widthStep = frame_all ->widthStep;  
    img3->depth = frame->depth;  
    img3 ->nChannels = 3;  
  
    while(1)
	{  
		 IplImage* frame_gray = cvCreateImage(  
        cvSize(width, height),  
        IPL_DEPTH_8U,  
        3);
        frame = cvQueryFrame(capture);  
        if(!frame)
		{  
            return 1;  
        }  
        //����ɫͼ��ת��Ϊ��ɫͼ��  
        cvCvtColor(frame,gray,CV_RGB2GRAY);  
        cvCvtColor(gray,frame_gray,CV_GRAY2BGR);  
        Canny = doCanny(gray,10,100,3);  
        cvCvtColor(Canny,frame_Canny,CV_GRAY2BGR);  
  
        img1 ->imageData = frame_all ->imageData;  
        cvCopy(frame,img1);  

        img2 ->imageData = frame_all ->imageData + frame ->widthStep;  
        cvCopy(frame_gray,img2);   
        img3 ->imageData = frame_all ->imageData + 2 * frame ->widthStep;  
        cvCopy(frame_Canny,img3);		//��copy��ͬʱ�����ڴ�ռ�
		//printf("%d ",frame->widthStep);  //��opencv3���Ѿ�������step������widthStwp��ʾ�еĳ��ȣ���λΪ�ֽڣ�
        CvFont textfont = cvFont(10.0,1);  
        cvInitFont(&textfont, CV_FONT_HERSHEY_SIMPLEX, 0.5f, 0.5f, 0, 1);  
        cvPutText(frame_all, "Frame", cvPoint(10,20), &textfont, cvScalar(0,0,255));  
        cvPutText(frame_all, "Frame_Gray", cvPoint(width+10,20), &textfont, cvScalar(255,0,0));  
        cvPutText(frame_all, "Frame_Canny", cvPoint(width*2+10, 20), &textfont, cvScalar(0,255,0));  
		cvReleaseImage(&frame_gray); 
        cvShowImage("window_all",frame_all);  
  
        if(cvWaitKey(33) == 27)
		{//ÿ����ʾ30֡  
            break;  
        }  
    }  
    cvReleaseImage(&frame);  
    cvReleaseImage(&gray);  
  //  cvReleaseImage(&frame_gray);  
    cvReleaseImage(&Canny);  
    cvReleaseImage(&frame_Canny);  
    cvReleaseImage(&img1);  
    cvReleaseImage(&img2);  
    cvReleaseImage(&img3);  
    cvReleaseCapture(&capture);  
    cvDestroyWindow("window_all");
	

	return 0;
}  


