/* 
* @Author: skyrim
* @Date:   2014-09-03 23:06:50
* @Last Modified by:   skyrim
* @Last Modified time: 2014-09-12 15:09:52
*/
/*1、    形状（一）
编写C++程序完成以下功能：
（1） 声明一个基类Shape（形状），其中包含一个方法来计算面积；
（2） 从Shape派生两个类：矩形类和圆形类；
（3） 从矩形类派生正方形类；
（4） 分别实现派生类构造函数、析构函数和其他方法；
（5） 创建派生类的对象，观察构造函数、析构函数调用次序；（提示及要求：1，可通过在构造与析构函数中加入输出提示信息的方式观察相关调用；可以使用system("pause")进行程序的暂停；2，能够理解并说明每一次构造与析构函数调用是哪个对象的调用，并观察和解释相关调用顺序及其原因）
（6） 对不同对象计算面积。
*/

#include <iostream>

using namespace std;

//基类
class Shape
{
public:
    Shape(double areas) : area(areas) {}    //构造函数：初始化面积area
    ~Shape() {} //析构函数
    //提供计算面积的方法
    double get_area (){
        return area ;
    }
private:
    double area ;   //储存面积
};

//派生类：矩形
class rectangle : public Shape
{
public:
    rectangle(double l ,double w) : length(l) , width(w) , Shape(l*w) {}    //构造函数：初始化矩形面积
    ~rectangle() {}
private:
    double length , width ; //储存矩形的长宽
};

//派生类：圆形
class round : public Shape
{
public:
    round(double r) : radius(r) , Shape(3.1415936 * r * r) {}    //构造函数：初始化圆形面积
    ~round() { system("pause") ; }
private:
    double radius;  //储存圆的半径
};

//派生类：正方形
class Square : public rectangle
{
public:
    Square(double l) : Slength(l) , rectangle(l,l) {}    //构造函数：初始化正方形面积
    ~Square() {}
private:
    double Slength ;    //储存正方形边长
};

int main(){
    rectangle a (2,3);  //2*3矩形
    round b(2); //r=2圆形
    Square c(2);   //2*2正方形
    cout << a.get_area() << '\n' << b.get_area() << '\n' << c.get_area() <<endl ;
    return 0;
}