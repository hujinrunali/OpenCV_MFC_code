//#include <iostream>
//#include <opencv2/opencv.hpp>
//#include <opencv2/imgproc.hpp>
//#include <opencv2/highgui.hpp>
//#include <direct.h>
//using namespace std;
//using namespace  cv;
//Mat img;
//bool applyGray = false;
//bool applyBlur = false;
//bool applySobel = false;

//const char* keys = {
//    "{help h usage? || print this message}"
//    "{@image || Image to Process}"
//};


//void blurCallback(int state, void* userdata);
//void grayCallback(int state, void* userdata);
//void bgrCallback(int state,void* userdata);
//void sobelCallback(int state,void* userdata);
//void applyFilters();
//void showHistoCallback(int state,void* userData);
//void equalizeCallback(int state,void* userData);
//void lomoCallback(int state,void* userData);
//void cartoonCallback(int state,void* userData);
//string getPath();
//int main(int argc,char** argv)
//{
////    CommandLineParser parser(argc,argv,keys);
////    parser.about("Chapter 4. PhotoTool V1.0.0");
////    //是否需要帮助信息
////    if(parser.has("help"))
////    {
////        parser.printMessage();
////        return 0;
////    }

////    String imgFile = parser.get<string>(0);
////    //检查参数是否被正确解析
////    if(!parser.check())
////    {
////        parser.printErrors();
////        return 0;
////    }

//    string path = getPath();
//    path += "back.jpg";
//    //读取图像
//    img = imread(path);
//    //创建窗口
//    namedWindow("back",WINDOW_FREERATIO);
//    //创建按钮
//    createButton("Blur",blurCallback,NULL,QT_CHECKBOX,0);

//    createButton("Gray",grayCallback,NULL,QT_RADIOBOX,0);
//    createButton("RGB",bgrCallback,NULL,QT_RADIOBOX,1);

//    createButton("Sobel",sobelCallback,NULL,QT_PUSH_BUTTON,0);

//    createButton("Histogram",showHistoCallback,NULL,QT_PUSH_BUTTON,0);

//    createButton("Equalize",equalizeCallback,NULL,QT_PUSH_BUTTON,0);

//    createButton("Lomo",lomoCallback,NULL,QT_PUSH_BUTTON,0);
//    createButton("Cartoon",cartoonCallback,NULL,QT_PUSH_BUTTON,0);
//    //等待按键按下退出
//    waitKey(0);
//    //销毁窗口
//    destroyWindow("back");
//    return 0;
//}

//void blurCallback(int state, void* userdata)
//{
//    applyBlur = static_cast<bool>(state);
//    applyFilters();
//}
//void grayCallback(int state, void* userdata)
//{
//    applyGray = true;
//    applyFilters();
//}
//void bgrCallback(int state,void* userdata)
//{
//    applyGray = false;
//    applyFilters();
//}
//void sobelCallback(int state,void* userdata)
//{
//    applySobel = !applySobel;
//    applyFilters();
//}

//void applyFilters()
//{
//    Mat result;
//    img.copyTo(result);
//    if(applyGray)
//    {
//        cvtColor(result,result,COLOR_BGR2GRAY);
//    }
//    if(applyBlur)
//        blur(result,result,Size(5,5));
//    if(applySobel)
//    {
//        //cvtColor(result,result,COLOR_BGR2GRAY);
//        Sobel(result,result,CV_8U,1,1);
//    }

//    imshow("back",result);
//}

//void showHistoCallback(int state,void* userData)
//{
//    //将彩色图像分成多个通道
//    vector<Mat> bgr;
//    split(img,bgr);
//    //创建有256个子区间的直方图
//    int numbines = 256;
//    //设置(B，G,R)的范围，最后一个值不包含
//    float range[] = {0,256};
//    const float * histRange = {range};

//    Mat b_hist,g_hist,r_hist;
//    calcHist(&bgr[0],1,0,Mat(),b_hist,1,&numbines,&histRange);
//    calcHist(&bgr[1],1,0,Mat(),g_hist,1,&numbines,&histRange);
//    calcHist(&bgr[2],1,0,Mat(),r_hist,1,&numbines,&histRange);

//    //绘制直方图每个通道分别绘制
//    int width = 512;
//    int height = 300;
//    //以灰色为基底创建图像
//    Mat histImage(height,width,CV_8UC3,Scalar(20,20,20));
//    //从0到图像的高度归一化图像
//    normalize(b_hist,b_hist,0,height,NORM_MINMAX);
//    normalize(g_hist,g_hist,0,height,NORM_MINMAX);
//    normalize(r_hist,r_hist,0,height,NORM_MINMAX);
//    int binStep = cvRound(static_cast<float>(width)/static_cast<float>(numbines));
//    for(int i= 1;i<numbines;++i)
//    {
//     line(histImage,Point(binStep*(i-1),height-cvRound(b_hist.at<float>(i-1))),Point(binStep*(i),height-cvRound(b_hist.at<float>(i))),Scalar(255,0,0));
//     line(histImage,Point(binStep*(i-1),height-cvRound(g_hist.at<float>(i-1))),Point(binStep*(i),height-cvRound(g_hist.at<float>(i))),Scalar(0,255,0));
//     line(histImage,Point(binStep*(i-1),height-cvRound(r_hist.at<float>(i-1))),Point(binStep*(i),height-cvRound(r_hist.at<float>(i))),Scalar(0,0,255));
//    }
//    imshow("Histogram",histImage);
//}

//void equalizeCallback(int state,void* userData)
//{
//    Mat result;
//    //BGR图像转化为YCbCr图像
//    Mat ycrcb;
//    cvtColor(img,ycrcb,COLOR_BGR2YCrCb);
//    //图像通道分离
//    vector<Mat> channels;
//    split(ycrcb,channels);
//    //只均衡Y通道
//    equalizeHist(channels[0],channels[0]);

//    //合并结果通道
//    merge(channels,ycrcb);
//    //将YCrCb转换为BGR格式
//    cvtColor(ycrcb,result,COLOR_YCrCb2BGR);
//    //显示图像
//    namedWindow("Equalized",WINDOW_FREERATIO);
//    imshow("Equalized",result);
//}

//void lomoCallback(int state,void* userData)
//{
//    Mat result;
//    const double exponential_e = std::exp(1.0);
//    //【1】建立一个包含256个元素的映射表
//    Mat lut(1,256,CV_8UC1);
//    for(int i =0;i<256;++i)
//    {
//        float x = (float)i/256.0;
//        lut.at<uchar>(i) = cvRound(256*(1/(1+pow(exponential_e,-(x-0.5)/0.1))));
//    }
//    //【2】拆分图像通道，只给红色通道应用值变换
//    vector<Mat> bgr;
//    split(img,bgr);
//    LUT(bgr[2],lut,bgr[2]);
//    //合并结果
//    merge(bgr,result);

//    //【3】创建晕暗图像
//    Mat halo(img.rows,img.cols,CV_32FC3,Scalar(0.3,0.3,0.3));
//    //创建圆,列数是行的长度，行数是列的长度
//    circle(halo,Point(img.cols/2,img.rows/2),img.cols/3,Scalar(1,1,1),-1);
//    blur(halo,halo,Size(img.cols/3,img.cols/3));
//    //【4】转换图像
//    Mat resultf;
//    result.convertTo(resultf,CV_32FC3);
//    //将结果相乘
//    multiply(resultf,halo,resultf);
//    //转换为8位图像
//    resultf.convertTo(result,CV_8UC3);

//    //【5】展示结果
//    namedWindow("Lomograpy",WINDOW_FREERATIO);
//    imshow("Lomograpy",result);

//}

//void cartoonCallback(int state,void* userData)
//{
//    //【1】边缘检测
//    Mat imgMedian;
//    medianBlur(img,imgMedian,7);
//    //用Canny检测边缘
//    Mat imgCanny;
//    Canny(imgMedian,imgCanny,50,100);
//    //【2】边缘处理
//    //边缘膨胀
//    Mat kernel = getStructuringElement(MORPH_RECT,Size(2,2));//返回形态学的核
//    dilate(imgCanny,imgCanny,kernel);
//    //边缘值缩放到1,并将值反转
//    imgCanny = imgCanny/255;
//    imgCanny = 1-imgCanny;
//    //使用浮点值以便允许在0和1之间相乘
//    Mat imgCannyf;
//    imgCanny.convertTo(imgCannyf,CV_32FC3);
//    //模糊边缘实现平滑效果
//    blur(imgCannyf,imgCannyf,Size(5,5));

//    //【3】颜色处理
//    //实现双边滤波器，实现色彩均匀化
//    Mat imgBF;
//    bilateralFilter(img,imgBF,9,150.0,150.0);
//    //截断颜色
//    Mat result = imgBF/25;
//    result = result*25;

//    //【4】合并边缘和颜色
//    //为边缘创建3个通道
//    Mat imgCanny3c;
//    Mat cannyChannels[] = {imgCannyf,imgCannyf,imgCannyf};
//    merge(cannyChannels,3,imgCanny3c);

//    //将结果转换成浮点型
//    Mat resultf;
//    result.convertTo(resultf,CV_32FC3);

//    //颜色和边缘矩阵相乘
//    multiply(resultf,imgCanny3c,resultf);

//    //转换成8位图像
//    resultf.convertTo(result,CV_8UC3);

//    //【5】显示图像
//    namedWindow("Cartoon",WINDOW_FREERATIO);
//    imshow("Cartoon",result);
//}

//string getPath()
//{
//    char buf[256];
//    _getcwd(buf,sizeof(buf));
//    string rawpath(buf);
//    string path;
//    int pos = rawpath.find_last_of('\\');
//    path.append(rawpath.begin(),rawpath.begin()+pos);
//    std::cout << path << endl;
//    string replace = "/";
//    while(pos != -1)
//    {
//        path.replace(pos,1,replace);
//        std::cout << path << endl;
//        pos = path.find('\\');
//    }
//    path += "PureTest/";
//    return path;
//}
