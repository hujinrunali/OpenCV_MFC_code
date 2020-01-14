#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <direct.h>
using namespace std;
using namespace  cv;

//获取路径
string getPath()
{
    char buf[256];
    _getcwd(buf,sizeof(buf));
    string rawpath(buf);
    string path;
    int pos = rawpath.find_last_of('\\');
    path.append(rawpath.begin(),rawpath.begin()+pos);
    std::cout << path << endl;
    string replace = "/";
    while(pos != -1)
    {
        path.replace(pos,1,replace);
        std::cout << path << endl;
        pos = path.find('\\');
    }
    path += "PureTest/";
    return path;
}

<<<<<<< HEAD
Mat removeLight(Mat img,Mat pattern,int method);
Mat calculateLightPattern(Mat img);

int main()
{
    string path = getPath();
    path += "classify.png";
    Mat img = imread(path,0);
    if(img.data == NULL)
    {
        cout << "Error loading image" << path << endl;
        return 0;
    }

    Mat img_nosie;
    medianBlur(img,img_nosie,3);


    return 0;
}

Mat removeLight(Mat img,Mat pattern,int method)
{
    Mat aux;
    //如果是除法
}
Mat calculateLightPattern(Mat img)
{
    Mat pattern;
    //用基本和有效的方法来计算图像光纹
    blur(img,pattern,Size(img.cols/3,img.cols/3));
    return pattern;
}
=======
int main()
{
    return 0;
}
>>>>>>> b8585bc8cd0cdd5457ece1d002538e087b8daf24
