// BaseTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	/*图像的显示*/
	//Mat img = imread("wood.png");
	//imshow("Image",img);
	/***************/

	/**图像的腐蚀**/
	//载入图像
	//Mat srcImage = imread("cat.jpg");
	////显示图像
	//imshow("[原图]腐蚀操作",srcImage);
	////进行腐蚀操作
	//Mat element = getStructuringElement(MORPH_RECT,Size(15,15));
	//Mat DstImage;
	//
	//erode(srcImage, DstImage, element);
	////显示效果图
	//imshow("[效果图]腐蚀操作", DstImage);
	/**********************/

	/**图像模糊**/
	////载入图像
	//Mat srcImage = imread("city.jpg");
	////显示原始图像
	//imshow("[原图]中值滤波",srcImage);
	////进行中值滤波
	//Mat dstImage;
	//blur(srcImage,dstImage,Size(7,7));
	////显示效果图
	//imshow("[效果图]中值滤波", dstImage);


	/**Canny边缘检测**/
	//Mat srcImage = imread("fruit.jpg");
	//imshow("[原图]Canny边缘检测", srcImage);
	//Mat dstImage, edge, grayImage;
	////dstImage.create
	//cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
	//blur(grayImage, edge, Size(3, 3));
	//Canny(edge,edge,3,9,3);
	//imshow("[效果图]Canney边缘检测",edge);

	/**视频操作**/
	VideoCapture capture("1.avi");
	//循环显示每一帧
	while (1)
	{
		Mat frame;
		capture >> frame;
		imshow("读取视频", frame);
		waitKey(30);
	}
	waitKey(0);
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
