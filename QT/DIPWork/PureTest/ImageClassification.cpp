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

int main()
{
    return 0;
}
