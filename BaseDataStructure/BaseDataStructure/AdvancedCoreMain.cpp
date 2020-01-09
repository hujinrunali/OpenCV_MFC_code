//#include <iostream>
//#include <opencv2/opencv.hpp>
//using namespace cv;
//
////------------------------【全局函数声明】--------------------------
////			描述：全局函数声明
////------------------------------------------------------------------
//
////------------------------【colorReducePointer()函数】--------------------------
////			描述：全局函数，用指针访问像素
////------------------------------------------------------------------------------
//void colorReducePointer(Mat& inputImage, Mat &outputImage, int div);//指针最快
//
//
////------------------------【colorReduceIterator()函数】--------------------------
////			描述：全局函数，通过迭代器访问像素
////-------------------------------------------------------------------------------
//void colorReduceIterator(Mat& inputImage, Mat &outputImage, int div);
//
//
////------------------------【colorReduceDynamic()函数】--------------------------
////			描述：全局函数，通过动态地址访问像素
////------------------------------------------------------------------------------
//void colorReduceDynamic(Mat& inputImage, Mat &outputImage, int div);
//
//
////------------------------【ROI_AddImage()函数】--------------------------
////			描述：提取图像的ROI，并将两幅图像混合
////------------------------------------------------------------------------
//bool ROI_AddImage()
//{
//	//【1】读入图像
//	Mat srcImage = imread("dota_pa.jpg");
//	Mat logoImage = imread("dota_logo.jpg");
//	if (!srcImage.data)
//	{
//		printf("读取srcImage错误");
//		return false;
//	}
//	if (!logoImage.data)
//	{
//		printf("读取srcImage错误");
//		return false;
//	}
//	//【2】定义一个Mat类型并给其设定ROI区域
//	Mat imageROI = srcImage(Rect(200, 250, logoImage.cols, logoImage.rows));
//	//【3】加载掩膜
//	Mat mask = imread("dota_logo.jpg", 0);
//	//【4】将掩膜复制到ROI
//	logoImage.copyTo(imageROI, mask);
//	//【5】显示结果
//	namedWindow("利用ROI实现图像叠加示例窗口");
//	imshow("利用ROI实现图像叠加示例窗口", srcImage);
//	return true;
//}
//
//
////------------------------【】--------------------------
////			描述：
////------------------------------------------------------
//bool LinearBlending()
//{
//	//【0】定义一些局部变量
//	double alphaValue = 0.5;
//	double betaValue;
//	Mat srcImage2, srcImage3, dstImage;
//	//【1】读取图像(两幅图像的尺寸需要相同)
//	srcImage2 = imread("mogu.jpg");
//	srcImage3 = imread("rain.jpg");
//	if (!srcImage2.data)
//	{
//		printf("读取srcImage错误");
//		return false;
//	}
//	if (!srcImage3.data)
//	{
//		printf("读取srcImage错误");
//		return false;
//	}
//	//【2】做图像混合加权操作
//	betaValue = 1.0 - alphaValue;
//	addWeighted(srcImage2, alphaValue, srcImage3, betaValue, 0.0, dstImage);
//	//【3】创建窗口并显示
//	namedWindow("线性混合【原图】");
//	imshow("线性混合【原图】", srcImage2);
//	namedWindow("线性混合【效果图】");
//	imshow("线性混合【效果图】", dstImage);
//	return true;
//}
//
//int main()
//{
//	/*Mat srcImage = imread("cat.jpg");
//	imshow("原始图像", srcImage);
//	Mat dstImage;
//	dstImage.create(srcImage.rows, srcImage.cols, srcImage.type());
//	double time0 = static_cast<double>(getTickCount());
//	colorReducePointer(srcImage, dstImage, 32);
//	time0 = (static_cast<double>(getTickCount()) - time0) / getTickFrequency();
//	std::cout << "运行时间为：" << time0;
//	imshow("效果图", dstImage);*/
//	LinearBlending();
//	waitKey(0);
//	return 0;
//}
//
//void colorReducePointer(Mat& inputImage, Mat &outputImage, int div)
//{
//	//参数准备
//	outputImage = inputImage.clone();
//	int rowNumber = outputImage.rows;
//	int colNumber = outputImage.cols*outputImage.channels();
//	//双重循环访问像素
//	for (int i = 0; i < rowNumber; ++i)
//	{
//		uchar *data = outputImage.ptr<uchar>(i);//获取第i行首地址
//		for (int j = 0; j < colNumber; ++j)
//		{
//			data[j] = data[j] / div * div + div / 2;
//		}
//	}
//}
//
//void colorReduceIterator(Mat& inputImage, Mat &outputImage, int div)
//{
//	//参数准备
//	outputImage = inputImage.clone();
//	//获取迭代器
//	Mat_<Vec3b>::iterator it = outputImage.begin<Vec3b>();//起始位置
//	Mat_<Vec3b>::iterator itend = outputImage.end<Vec3b>();//终止位置
//	
//	//存储彩色图像
//	for (; it != itend; it++)
//	{
//		(*it)[0] = (*it)[0] / div * div + div / 2;
//		(*it)[1] = (*it)[1] / div * div + div / 2;
//		(*it)[2] = (*it)[2] / div * div + div / 2;
//	}
//}
//
//void colorReduceDynamic(Mat& inputImage, Mat &outputImage, int div)
//{
//	//参数准备
//	outputImage = inputImage.clone();
//	int rowNumber = outputImage.rows;
//	int colNumber = outputImage.cols;
//	//存取彩色图像的像素
//	for (int i = 0; i < rowNumber; ++i)
//	{
//		for (int j = 0; j < colNumber; ++j)
//		{
//			outputImage.at<Vec3b>(i, j)[0] = outputImage.at<Vec3b>(i, j)[0] / div * div + div / 2;//蓝色通道
//			outputImage.at<Vec3b>(i, j)[1] = outputImage.at<Vec3b>(i, j)[1] / div * div + div / 2;//绿色通道
//			outputImage.at<Vec3b>(i, j)[2] = outputImage.at<Vec3b>(i, j)[2] / div * div + div / 2;//红色通道
//		}
//	}
//}
//
