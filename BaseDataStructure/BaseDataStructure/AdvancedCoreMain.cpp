//#include <iostream>
//#include <opencv2/opencv.hpp>
//using namespace cv;
//
////------------------------��ȫ�ֺ���������--------------------------
////			������ȫ�ֺ�������
////------------------------------------------------------------------
//
////------------------------��colorReducePointer()������--------------------------
////			������ȫ�ֺ�������ָ���������
////------------------------------------------------------------------------------
//void colorReducePointer(Mat& inputImage, Mat &outputImage, int div);//ָ�����
//
//
////------------------------��colorReduceIterator()������--------------------------
////			������ȫ�ֺ�����ͨ����������������
////-------------------------------------------------------------------------------
//void colorReduceIterator(Mat& inputImage, Mat &outputImage, int div);
//
//
////------------------------��colorReduceDynamic()������--------------------------
////			������ȫ�ֺ�����ͨ����̬��ַ��������
////------------------------------------------------------------------------------
//void colorReduceDynamic(Mat& inputImage, Mat &outputImage, int div);
//
//
////------------------------��ROI_AddImage()������--------------------------
////			��������ȡͼ���ROI����������ͼ����
////------------------------------------------------------------------------
//bool ROI_AddImage()
//{
//	//��1������ͼ��
//	Mat srcImage = imread("dota_pa.jpg");
//	Mat logoImage = imread("dota_logo.jpg");
//	if (!srcImage.data)
//	{
//		printf("��ȡsrcImage����");
//		return false;
//	}
//	if (!logoImage.data)
//	{
//		printf("��ȡsrcImage����");
//		return false;
//	}
//	//��2������һ��Mat���Ͳ������趨ROI����
//	Mat imageROI = srcImage(Rect(200, 250, logoImage.cols, logoImage.rows));
//	//��3��������Ĥ
//	Mat mask = imread("dota_logo.jpg", 0);
//	//��4������Ĥ���Ƶ�ROI
//	logoImage.copyTo(imageROI, mask);
//	//��5����ʾ���
//	namedWindow("����ROIʵ��ͼ�����ʾ������");
//	imshow("����ROIʵ��ͼ�����ʾ������", srcImage);
//	return true;
//}
//
//
////------------------------����--------------------------
////			������
////------------------------------------------------------
//bool LinearBlending()
//{
//	//��0������һЩ�ֲ�����
//	double alphaValue = 0.5;
//	double betaValue;
//	Mat srcImage2, srcImage3, dstImage;
//	//��1����ȡͼ��(����ͼ��ĳߴ���Ҫ��ͬ)
//	srcImage2 = imread("mogu.jpg");
//	srcImage3 = imread("rain.jpg");
//	if (!srcImage2.data)
//	{
//		printf("��ȡsrcImage����");
//		return false;
//	}
//	if (!srcImage3.data)
//	{
//		printf("��ȡsrcImage����");
//		return false;
//	}
//	//��2����ͼ���ϼ�Ȩ����
//	betaValue = 1.0 - alphaValue;
//	addWeighted(srcImage2, alphaValue, srcImage3, betaValue, 0.0, dstImage);
//	//��3���������ڲ���ʾ
//	namedWindow("���Ի�ϡ�ԭͼ��");
//	imshow("���Ի�ϡ�ԭͼ��", srcImage2);
//	namedWindow("���Ի�ϡ�Ч��ͼ��");
//	imshow("���Ի�ϡ�Ч��ͼ��", dstImage);
//	return true;
//}
//
//int main()
//{
//	/*Mat srcImage = imread("cat.jpg");
//	imshow("ԭʼͼ��", srcImage);
//	Mat dstImage;
//	dstImage.create(srcImage.rows, srcImage.cols, srcImage.type());
//	double time0 = static_cast<double>(getTickCount());
//	colorReducePointer(srcImage, dstImage, 32);
//	time0 = (static_cast<double>(getTickCount()) - time0) / getTickFrequency();
//	std::cout << "����ʱ��Ϊ��" << time0;
//	imshow("Ч��ͼ", dstImage);*/
//	LinearBlending();
//	waitKey(0);
//	return 0;
//}
//
//void colorReducePointer(Mat& inputImage, Mat &outputImage, int div)
//{
//	//����׼��
//	outputImage = inputImage.clone();
//	int rowNumber = outputImage.rows;
//	int colNumber = outputImage.cols*outputImage.channels();
//	//˫��ѭ����������
//	for (int i = 0; i < rowNumber; ++i)
//	{
//		uchar *data = outputImage.ptr<uchar>(i);//��ȡ��i���׵�ַ
//		for (int j = 0; j < colNumber; ++j)
//		{
//			data[j] = data[j] / div * div + div / 2;
//		}
//	}
//}
//
//void colorReduceIterator(Mat& inputImage, Mat &outputImage, int div)
//{
//	//����׼��
//	outputImage = inputImage.clone();
//	//��ȡ������
//	Mat_<Vec3b>::iterator it = outputImage.begin<Vec3b>();//��ʼλ��
//	Mat_<Vec3b>::iterator itend = outputImage.end<Vec3b>();//��ֹλ��
//	
//	//�洢��ɫͼ��
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
//	//����׼��
//	outputImage = inputImage.clone();
//	int rowNumber = outputImage.rows;
//	int colNumber = outputImage.cols;
//	//��ȡ��ɫͼ�������
//	for (int i = 0; i < rowNumber; ++i)
//	{
//		for (int j = 0; j < colNumber; ++j)
//		{
//			outputImage.at<Vec3b>(i, j)[0] = outputImage.at<Vec3b>(i, j)[0] / div * div + div / 2;//��ɫͨ��
//			outputImage.at<Vec3b>(i, j)[1] = outputImage.at<Vec3b>(i, j)[1] / div * div + div / 2;//��ɫͨ��
//			outputImage.at<Vec3b>(i, j)[2] = outputImage.at<Vec3b>(i, j)[2] / div * div + div / 2;//��ɫͨ��
//		}
//	}
//}
//
