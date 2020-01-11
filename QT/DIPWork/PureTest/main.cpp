#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace  cv;
Mat img;
bool applyGray = false;
bool applyBlur = false;
bool applySobel = false;

void blurCallback(int state, void* userdata);
void grayCallback(int state, void* userdata);
void bgrCallback(int state,void* userdata);
void sobelCallback(int state,void* userdata);
void applyFilters();
void showHistoCallback(int state,void* userData);
void equalizeCallback(int state,void* userData);
void lomoCallback(int state,void* userData);
int main()
{
    //读取图像
    img = imread("D:/SelfCode/QTCode/DIPWork/PureTest/back.jpg");
    //创建窗口
    namedWindow("back",WINDOW_FREERATIO);
    //创建按钮
    createButton("Blur",blurCallback,NULL,QT_CHECKBOX,0);

    createButton("Gray",grayCallback,NULL,QT_RADIOBOX,0);
    createButton("RGB",bgrCallback,NULL,QT_RADIOBOX,1);

    createButton("Sobel",sobelCallback,NULL,QT_PUSH_BUTTON,0);

    createButton("Histogram",showHistoCallback,NULL,QT_PUSH_BUTTON,0);

    createButton("Equalize",equalizeCallback,NULL,QT_PUSH_BUTTON,0);
    //等待按键按下退出
    waitKey(0);
    //销毁窗口
    destroyWindow("back");
    return 0;
}

void blurCallback(int state, void* userdata)
{
    applyBlur = static_cast<bool>(state);
    applyFilters();
}
void grayCallback(int state, void* userdata)
{
    applyGray = true;
    applyFilters();
}
void bgrCallback(int state,void* userdata)
{
    applyGray = false;
    applyFilters();
}
void sobelCallback(int state,void* userdata)
{
    applySobel = !applySobel;
    applyFilters();
}

void applyFilters()
{
    Mat result;
    img.copyTo(result);
    if(applyGray)
    {
        cvtColor(result,result,COLOR_BGR2GRAY);
    }
    if(applyBlur)
        blur(result,result,Size(5,5));
    if(applySobel)
    {
        //cvtColor(result,result,COLOR_BGR2GRAY);
        Sobel(result,result,CV_8U,1,1);
    }

    imshow("back",result);
}

void showHistoCallback(int state,void* userData)
{
    //将彩色图像分成多个通道
    vector<Mat> bgr;
    split(img,bgr);
    //创建有256个子区间的直方图
    int numbines = 256;
    //设置(B，G,R)的范围，最后一个值不包含
    float range[] = {0,256};
    const float * histRange = {range};

    Mat b_hist,g_hist,r_hist;
    calcHist(&bgr[0],1,0,Mat(),b_hist,1,&numbines,&histRange);
    calcHist(&bgr[1],1,0,Mat(),g_hist,1,&numbines,&histRange);
    calcHist(&bgr[2],1,0,Mat(),r_hist,1,&numbines,&histRange);

    //绘制直方图每个通道分别绘制
    int width = 512;
    int height = 300;
    //以灰色为基底创建图像
    Mat histImage(height,width,CV_8UC3,Scalar(20,20,20));
    //从0到图像的高度归一化图像
    normalize(b_hist,b_hist,0,height,NORM_MINMAX);
    normalize(g_hist,g_hist,0,height,NORM_MINMAX);
    normalize(r_hist,r_hist,0,height,NORM_MINMAX);
    int binStep = cvRound(static_cast<float>(width)/static_cast<float>(numbines));
    for(int i= 1;i<numbines;++i)
    {
     line(histImage,Point(binStep*(i-1),height-cvRound(b_hist.at<float>(i-1))),Point(binStep*(i),height-cvRound(b_hist.at<float>(i))),Scalar(255,0,0));
     line(histImage,Point(binStep*(i-1),height-cvRound(g_hist.at<float>(i-1))),Point(binStep*(i),height-cvRound(g_hist.at<float>(i))),Scalar(0,255,0));
     line(histImage,Point(binStep*(i-1),height-cvRound(r_hist.at<float>(i-1))),Point(binStep*(i),height-cvRound(r_hist.at<float>(i))),Scalar(0,0,255));
    }
    imshow("Histogram",histImage);
}

void equalizeCallback(int state,void* userData)
{
    Mat result;
    //BGR图像转化为YCbCr图像
    Mat ycrcb;
    cvtColor(img,ycrcb,COLOR_BGR2YCrCb);
    //图像通道分离
    vector<Mat> channels;
    split(ycrcb,channels);
    //只均衡Y通道
    equalizeHist(channels[0],channels[0]);

    //合并结果通道
    merge(channels,ycrcb);
    //将YCrCb转换为BGR格式
    cvtColor(ycrcb,result,COLOR_YCrCb2BGR);
    //显示图像
    namedWindow("Equalized",WINDOW_FREERATIO);
    imshow("Equalized",result);
}


