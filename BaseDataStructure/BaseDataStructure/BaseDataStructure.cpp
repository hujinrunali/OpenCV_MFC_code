//// BaseDataStructure.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
////
//
//#include <iostream>
//#include <opencv2/opencv.hpp>
//using namespace cv;
//#define WINDOW_WIDTH 600
//#define WINDOW_NAME1 "【绘制图1】"
//#define WINDOW_NAME2 "【绘制图2】"
////-----------------------------【DrawEllipse()函数】------------------------------
////		描述：自定义绘制函数，实现了绘制不同角度、相同尺寸的椭圆
////--------------------------------------------------------------------------------
//void DrawEllipse(Mat img, double angle)
//{
//	int thickness = 2;
//	int linetype = 8;
//	ellipse(img,
//		Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2),
//		Size(WINDOW_WIDTH / 4, WINDOW_WIDTH / 16),
//		angle,
//		0,
//		360,
//		Scalar(255,129,0),
//		thickness,
//		linetype
//		);
//}
//
////------------------------【DrawFilledCircle()函数】--------------------------
////			描述；自定义圆形绘制函数
////---------------------------------------------------------------------------
//void DrawFilledCircle(Mat img, Point center)
//{
//	int thickness = -1;
//	int lineType = 8;
//	circle(img,
//		center,
//		WINDOW_WIDTH / 32,
//		Scalar(0, 0, 255),
//		thickness,
//		lineType
//	);
//}
//
////------------------------【DrawPolygon()函数】--------------------------
////			描述:自定义绘制凹多边形
////----------------------------------------------------------------------
//void DrawPolygon(Mat img)
//{
//	int lineType = 8;
//	//创建一些点
//	Point rookPoints[1][20];
//	rookPoints[0][0] = Point(WINDOW_WIDTH / 4, 7 * WINDOW_WIDTH / 8);
//	rookPoints[0][1] = Point(3*WINDOW_WIDTH / 4, 7 * WINDOW_WIDTH / 8);
//	rookPoints[0][2] = Point(3*WINDOW_WIDTH / 4, 13* WINDOW_WIDTH / 16);
//	rookPoints[0][3] = Point(11*WINDOW_WIDTH / 16, 13 * WINDOW_WIDTH / 16);
//	rookPoints[0][4] = Point(19*WINDOW_WIDTH / 32, 3* WINDOW_WIDTH / 8);
//	rookPoints[0][5] = Point(3*WINDOW_WIDTH / 4, 3 * WINDOW_WIDTH / 8);
//	rookPoints[0][6] = Point(3*WINDOW_WIDTH / 4, WINDOW_WIDTH / 8);
//	rookPoints[0][7] = Point(26*WINDOW_WIDTH / 40, WINDOW_WIDTH / 8);
//	rookPoints[0][8] = Point(26*WINDOW_WIDTH / 40, WINDOW_WIDTH / 4);
//	rookPoints[0][9] = Point(22*WINDOW_WIDTH / 40, WINDOW_WIDTH / 4);
//	rookPoints[0][10] = Point(22 * WINDOW_WIDTH / 40,WINDOW_WIDTH / 8);
//	rookPoints[0][11] = Point(18*WINDOW_WIDTH / 40, WINDOW_WIDTH / 8);
//	rookPoints[0][12] = Point(18 * WINDOW_WIDTH / 40,WINDOW_WIDTH / 4);
//	rookPoints[0][13] = Point(14*WINDOW_WIDTH / 40,  WINDOW_WIDTH / 4);
//	rookPoints[0][14] = Point(14*WINDOW_WIDTH / 40, WINDOW_WIDTH / 8);
//	rookPoints[0][15] = Point(WINDOW_WIDTH / 4,  WINDOW_WIDTH / 8);
//	rookPoints[0][16] = Point(WINDOW_WIDTH / 4, 3 * WINDOW_WIDTH / 8);
//	rookPoints[0][17] = Point(13*WINDOW_WIDTH / 32, 3* WINDOW_WIDTH / 8);
//	rookPoints[0][18] = Point(5*WINDOW_WIDTH / 16, 13 * WINDOW_WIDTH / 16);
//	rookPoints[0][19] = Point(WINDOW_WIDTH / 4, 13 * WINDOW_WIDTH / 16);
//
//	const Point* ppt[1] = { rookPoints[0] };
//	int npt[] = { 20 };
//
//	fillPoly(
//		img,
//		ppt,
//		npt,
//		1,
//		Scalar(255,255,255),
//		lineType
//	);
//}
//
////------------------------【DrawLine()函数】--------------------------
////			描述：自定义线条绘制函数
////------------------------------------------------------
//void DrawLine(Mat img, Point start, Point end)
//{
//	int thickness = 2;
//	int lineType = 8;
//	line(
//		img,
//		start,
//		end,
//		Scalar(0, 0, 0),
//		thickness,
//		lineType
//	);
//}
//
//
//int main()
//{
////	//【1】载入图像
////	Mat srcImage = imread("cat.jpg"), dstImage;
////	//【2】颜色空间转换
////	cvtColor(srcImage, dstImage, COLOR_BGR2Lab);
////	//【3】显示效果图
////	imshow("【效果图】", dstImage);
//
//
//	//创建空白图像
//	Mat atomImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
//	Mat rookImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
//	//----------------<1>绘制化学中的原子示例图--------------------
//	//【1.1】先绘制椭圆
//	DrawEllipse(atomImage, 90);
//	DrawEllipse(atomImage, 0);
//	DrawEllipse(atomImage, 45);
//	DrawEllipse(atomImage, -45);
//	//【1.2】再绘制圆心
//	DrawFilledCircle(atomImage, Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2));
//
//	//-------------------<2>绘制组合图-----------------------------
//	//【2.1】先绘制多边形
//	DrawPolygon(rookImage);
//	//【2.2】绘制矩形
//	rectangle(rookImage, Point(0, 7 * WINDOW_WIDTH / 8), Point(WINDOW_WIDTH, WINDOW_WIDTH), Scalar(0, 255, 255), -1, 8);
//	//【2.3】绘制一些线段
//	DrawLine(rookImage, Point(0, 15 * WINDOW_WIDTH / 16), Point(WINDOW_WIDTH, 15 * WINDOW_WIDTH / 16));
//	DrawLine(rookImage, Point(WINDOW_WIDTH/4, 7 * WINDOW_WIDTH / 8), Point(WINDOW_WIDTH/4, WINDOW_WIDTH));
//	DrawLine(rookImage, Point(WINDOW_WIDTH/2,  7*WINDOW_WIDTH / 8), Point(WINDOW_WIDTH/2, WINDOW_WIDTH));
//	DrawLine(rookImage, Point(3*WINDOW_WIDTH/4, 7* WINDOW_WIDTH / 8), Point(3*WINDOW_WIDTH/4, WINDOW_WIDTH));
//
//	//----------------<3>显示图像-----------------------------
//	imshow(WINDOW_NAME1, atomImage);
//	moveWindow(WINDOW_NAME1, 0, 200);
//	imshow(WINDOW_NAME2, rookImage);
//	moveWindow(WINDOW_NAME2, WINDOW_WIDTH, 200);
//
//
//	waitKey(0);
//}
//
//
