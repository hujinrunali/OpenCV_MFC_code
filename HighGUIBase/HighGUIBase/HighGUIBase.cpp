// HighGUIBase.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

#define WINDOW_NAME "[线性混合示例]"
//==========================================
//			鼠标操作
//========================================

//------------【全局函数】-----------------
//			描述：全局函数的声明与定义
//----------------------------------------
void on_MouseHandle(int event, int x, int y, int flags, void *param);
void DrawRectangle(Mat& img, Rect box);
void ShowHelpText();
void TestMouse();

//-------------【全局变量声明部分】---------
//				描述：全局变量的声明
//------------------------------------------
Rect g_rectangle;
bool g_bDrawingBox = false;//是否进行绘制
RNG g_rng(12345);

//--------------------------------------------------
//				滑动条
//--------------------------------------------------

const int g_nMaxAlphaValue = 100;//Alpha值的最大值
int g_nAlphaValueSlider;//滑动条对应的变量
double g_dAlphaValue;
double g_dBetaValue;

//声明存储图像的变量
Mat g_srcImage1;
Mat g_srcImage2;
Mat g_dstImage;
//----------------------------------------
//		描述：响应滑动条的回调函数
//---------------------------------------
void on_Trackbar(int, void*)
{
	//求出当前alpha值相对于最大值的比例
	g_dAlphaValue = static_cast<double>(g_nAlphaValueSlider) / static_cast<double>(g_nMaxAlphaValue);
	//beta的值为alpha的值-1
	g_dBetaValue = 1 - g_dAlphaValue;
	//根据alpha和beta值进行混合
	addWeighted(g_srcImage1, g_dAlphaValue, g_srcImage2, g_dBetaValue, 0.0, g_dstImage);

	//显示效果图
	imshow(WINDOW_NAME, g_dstImage);
}

void TestSliderBar()
{
	//加载图像(两图像的尺寸需要相同)
	g_srcImage1 = imread("1.jpg");
	g_srcImage2 = imread("2.jpg");
	if (!g_srcImage1.data)
		printf("Read the First picture error\n");
	if (!g_srcImage2.data)
		printf("Read ther Second picture error\n");

	//设置滑动条初值70
	g_nAlphaValueSlider = 70;
	//创建窗口
	namedWindow(WINDOW_NAME, 1);
	//在创建的窗体中创建一个滑动控件
	char TrackbarName[50];
	sprintf_s(TrackbarName, "透明值%d", g_nMaxAlphaValue);
	createTrackbar(TrackbarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar);
	//结果在回调函数中显示
	on_Trackbar(g_nAlphaValueSlider, 0);
}

//////////////////////////////////////////////////////////////////////////////////

void createAlphaMat(Mat &mat)
{
	for (int i = 0; i < mat.rows; ++i)
	{
		for (int j = 0; j < mat.cols; ++j)
		{
			Vec4b &rgba = mat.at<Vec4b>(i, j);
			rgba[0] = UCHAR_MAX;
			rgba[1] = saturate_cast<uchar>((float(mat.cols - j)) / ((float)mat.cols)*UCHAR_MAX);
			rgba[2] = saturate_cast<uchar>((float(mat.rows - i)) / ((float)mat.rows)*UCHAR_MAX);
			rgba[3] = saturate_cast<uchar>(0.5*(rgba[1] + rgba[2]));
		}
	}
}

void Testimwrite()
{
	//创建带alpha通道的Mat
	Mat mat(480, 640, CV_8UC4);
	createAlphaMat(mat);
	vector<int> compression_params;
	//设置图像参数
	compression_params.push_back(IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);

	try
	{
		imwrite("透明Alpha值图.png", mat, compression_params);
		imshow("生成的PNG图", mat);
		fprintf(stdout, "PNG图片文件的alpha数据保存完毕~\n可以在工程目录下查看图片");
	}
	catch (runtime_error &ex)
	{
		fprintf(stderr, "图像转换成PNG格式错误：%s\n", ex.what());
	}
}

void BlendImage()
{
	Mat image = imread("dota.jpg");
	Mat logo = imread("dota_logo.jpg");
	//载入后先显示
	namedWindow("[原图]");
	imshow("[原图]", image);
	namedWindow("[logo图]");
	imshow("[logo图]", logo);

	//对图像进行融合
	Mat imageROI = image(Rect(800,350,logo.cols,logo.rows));
	addWeighted(imageROI, 0.5, logo, 0.3, 0,imageROI);

	namedWindow("[原图+logo图]");
	imshow("[原图+logo图]", image);
}


int main()
{
	TestMouse();
	waitKey(0);
	return 0;
}

//-------------------【on_MouseHandle()函数】------------------
//		描述：鼠标回调函数，根据不同的鼠标事件进行不同的操作
//-------------------------------------------------------------
void on_MouseHandle(int event, int x, int y, int flags, void *param)
{
	Mat &image = *(Mat*)param;
	switch (event)
	{
		//鼠标移动消息
		case EVENT_MOUSEMOVE:
		{
			
			if (g_bDrawingBox)
			{
				g_rectangle.width = x - g_rectangle.x;
				g_rectangle.height = y - g_rectangle.y;
			}
		}
		break;
		//左键按下
		case EVENT_LBUTTONDOWN:
		{
			g_bDrawingBox = true;
			g_rectangle = Rect(x, y, 0, 0);//记录起点位置
		}
		break;
		//左键抬起消息
		case EVENT_LBUTTONUP:
		{
			g_bDrawingBox = false;
			//对宽高小于0处理
			if (g_rectangle.width < 0)
			{
				g_rectangle.x += g_rectangle.width;
				g_rectangle.width *= -1;
			}
			if (g_rectangle.height < 0)
			{
				g_rectangle.y += g_rectangle.height;
				g_rectangle.height *= -1;
			}
			//调用函数进行绘制
			DrawRectangle(image, g_rectangle);
		}
		break;
	}
}

//---------------【DrawRectangle函数】------------------
//	 描述：自定义的矩形绘制函数
//------------------------------------------------------
void DrawRectangle(Mat& img, Rect box)
{
	rectangle(img, box.tl(), box.br(), Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255)));
}


//-----------------【TestMouse函数】-----------------
//		描述：测试Mouse操作的函数
//--------------------------------------------------
void TestMouse()
{
	//【1】准备参数
	g_rectangle = Rect(-1, -1, 0, 0);
	Mat srcImage(600, 800, CV_8UC3), tempImage;
	srcImage.copyTo(tempImage);
	srcImage = Scalar::all(0);
	//【2】设置鼠标回调函数
	namedWindow(WINDOW_NAME);
	setMouseCallback(WINDOW_NAME, on_MouseHandle, (void*)&srcImage);
	//【3】程序主循环，当绘制标志为真时，进行绘制
	while (1)
	{
		srcImage.copyTo(tempImage);//复制源图到临时变量
		if (g_bDrawingBox)
			DrawRectangle(tempImage, g_rectangle);
		imshow(WINDOW_NAME, tempImage);
		if (waitKey(10) == 27)
			break;
	}

}