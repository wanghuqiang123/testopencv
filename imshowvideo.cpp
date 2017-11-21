#include<opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
using namespace cv;

int  g_slider_position  = 0;//��������λ�ñ���
CvCapture* g_capture = NULL;//��Ƶ�ļ��ṹ��

void onTrackbarSlider(int pos)//�ص�����
{
    cvSetCaptureProperty(//cvGetCaptureProperty����CvCapture����ĸ������ԡ�
            g_capture,
            CV_CAP_PROP_POS_FRAMES,//��֡�����ö����λ�ã���FRAMES�滻ΪAVIRATIO�����ͨ����Ƶ�������ö����λ��
            pos
    );
}

int main( int argc, char** argv ) 
{
    cvNamedWindow( "Pirate", 0);//��������
    g_capture = cvCreateFileCapture("imdata/traffic.avi" );//��ȡ��Ƶ�ṹ��
    int frames = (int) cvGetCaptureProperty(    //��ȡ��Ƶ�ļ�����֡��
                    g_capture,
                    CV_CAP_PROP_FRAME_COUNT
                );

    if( frames!= 0 ) {
        cvCreateTrackbar(
            "Position", //������������
            "Pirate",   //�����������Ĵ��ڵ�����
            &g_slider_position, //�󶨹�������λ�ñ���
            frames, //��֡��
            onTrackbarSlider    //�ص�����
        );
    }
    
    IplImage* frame;//ͼ��ṹ��
    // While loop (as in Example 2) capture & show video
    while(1){
        frame = cvQueryFrame(g_capture);
        if(!frame)break;
        cvShowImage("Pirate",frame);
        
        cvSetTrackbarPos( "Position", "Pirate", g_slider_position++);//���ý�������λ��
        
        char c = cvWaitKey(5);
        if(c == 27)break;
    }
    // Release memory and destroy window
    cvReleaseCapture(&g_capture);
    cvDestroyWindow("Pirate");
    
    return(0);

}