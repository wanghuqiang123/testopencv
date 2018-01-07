


/***************<learing opencv> ***************/
#include"cv.h"
#include"highgui.h"
#include<stdio.h>

int g_switch_value = 0;


void switch_off_function()
{
	printf("open\n");
}
void switch_on_function()
{
	printf("on\n");
}
void switch_callback (int position)
{
	if(position == 0)
	{
		switch_off_function();
	}
	else
	{
		switch_on_function();
		
	}
}

int main(int argc,char** argv)
{
	cvNamedWindow("demo window",1);
	cvCreateTrackbar("switch","demo window",&g_switch_value, 1 ,switch_callback); //当滑动条有滑动时，switch_callback()回调函数被调用
	while(1)
	{
		if(cvWaitKey(15) == 27)
			break;
	}	
	cvDestroyWindow("box example");
	
	return 0;
}


