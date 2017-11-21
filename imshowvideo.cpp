#include<opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
using namespace cv;

int  g_slider_position  = 0;//滚动条的位置变量
CvCapture* g_capture = NULL;//视频文件结构体

void onTrackbarSlider(int pos)//回调函数
{
    cvSetCaptureProperty(//cvGetCaptureProperty设置CvCapture对象的各种属性。
            g_capture,
            CV_CAP_PROP_POS_FRAMES,//以帧数设置读入的位置，将FRAMES替换为AVIRATIO则可以通过视频长度设置读入的位置
            pos
    );
}

int main( int argc, char** argv ) 
{
    cvNamedWindow( "Pirate", 0);//创建窗口
    g_capture = cvCreateFileCapture("imdata/traffic.avi" );//获取视频结构体
    int frames = (int) cvGetCaptureProperty(    //获取视频文件的总帧数
                    g_capture,
                    CV_CAP_PROP_FRAME_COUNT
                );

    if( frames!= 0 ) {
        cvCreateTrackbar(
            "Position", //滚动条的名字
            "Pirate",   //滚动条所属的窗口的名字
            &g_slider_position, //绑定滚动条的位置变量
            frames, //总帧数
            onTrackbarSlider    //回调函数
        );
    }
    
    IplImage* frame;//图像结构体
    // While loop (as in Example 2) capture & show video
    while(1){
        frame = cvQueryFrame(g_capture);
        if(!frame)break;
        cvShowImage("Pirate",frame);
        
        cvSetTrackbarPos( "Position", "Pirate", g_slider_position++);//设置进度条的位置
        
        char c = cvWaitKey(5);
        if(c == 27)break;
    }
    // Release memory and destroy window
    cvReleaseCapture(&g_capture);
    cvDestroyWindow("Pirate");
    
    return(0);

}