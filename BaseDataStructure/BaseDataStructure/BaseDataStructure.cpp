// BaseDataStructure.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
int main()
{
	//【1】载入图像
	Mat srcImage = imread("cat.jpg"), dstImage;
	//【2】颜色空间转换
	cvtColor(srcImage, dstImage, COLOR_BGR2Lab);
	//【3】显示效果图
	imshow("【效果图】", dstImage);
	waitKey(0);
}


