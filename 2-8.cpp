


/***************<learing opencv> 练习2中的8小问的答案***************/
#include"cv.h"
#include"highgui.h"
#include<stdio.h>

typedef struct my_struct
{
	int n;
	CvPoint p;
	CvRect R;
}my_struct;
void write_my_struct(CvFileStorage* fs , const char * name , my_struct* ms)
{

}

void read_my_struct(CvFileStorage* fs , CvFileNode* ms_node , my_struct *ms)
{

}

int main(int argc,char** argv)
{

	return 0;
}

