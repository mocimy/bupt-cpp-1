/* 
* @Author: skyrim
* @Date:   2014-09-02 12:28:10
* @Last Modified by:   skyrim
* @Last Modified time: 2014-09-12 14:09:12
*/
/*1、    矩形
编写C++程序完成以下功能：
（1） 定义一个Point类，其属性包括点的坐标，提供计算两点之间距离的方法；（要求当用户不输入坐标数据时，能够默认为坐标原点（0，0））
（2） 定义一个矩形类，其属性包括左上角和右下角两个点，提供计算面积的方法；
（3） 创建一个矩形对象，提示用户输入矩形左上角和右下角的坐标；
（4） 计算其面积，并输出；
（5） 观察矩形对象以及Point类成员的构造函数与析构函数的调用。
（提示及要求：1，可通过在构造与析构函数中加入输出提示信息的方式观察相关调用；可以使用system("pause")进行程序的暂停；2，能够理解并说明每一次构造与析构函数调用是哪个对象的调用，并观察和解释相关调用顺序及其原因） 
*/

#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

//Point类，用于储存点
class Point
{
public:
    //构造函数1：当用户不输入坐标数据时，默认为坐标原点（0，0）
    Point(): x(0) ,y(0) {}
    //构造函数2：当用户输入坐标数据时，使用用户坐标
    Point (double x_coordinate , double y_coordinate) : x(x_coordinate) , y(y_coordinate) {} 
    ~Point () {}  //析构函数
    double x,y;     //坐标储存的成员变量
    //提供计算两点之间距离的方法
    double count_distance (const Point &A ,const Point &B){
        return sqrt( (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y) );
    }
};

//Rectangular类，储存矩形信息
class Rectangular
{
public:
    Rectangular() = default ;   //c++11标准的默认构造
    Rectangular(Point A ,Point B) : ul (A) ,lr (B) {}     //根据点坐标初始化类
    ~Rectangular () {}    //析构函数
    //提供计算矩形面积的方法
    double count_S (){
       return fabs((ul.x-lr.x) * (ul.y-lr.y)) ;
    }
private:
    Point ul,lr;
};

int main(){
    double x = 0 ,y = 0;
    string line ;
    cout << "Please input the upper left coordinate:(Press Enter without anyother key to skip)" ;
    //先读取一整行，如果用户没有输入任何数据，则执行默认坐标(0,0)
    getline (cin , line) ;
    if(!line.empty()) {
        //从字符串回读坐标
        istringstream record1 (line) ;
        record1 >> x >> y ;
    }
    Point ul(x,y);  //创建左下角点
    x = 0 ; y = 0 ;
    cout << "Please input the The lower right coordinate:(Press Enter without anyother key to skip)" ;
    //同上
    getline (cin , line) ;
    if(!line.empty()) {
        istringstream record2 (line) ;
        record2 >> x >> y ;
    }
    Point lr(x,y);  //创建右上角点
    Rectangular rect (ul,lr);   //创建Rectangular对象
    cout << rect.count_S() ;    //调用Rectangular中的count_S方法输出面积
    return 0;
}