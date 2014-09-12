/* 
* @Author: skyrim
* @Date:   2014-09-04 16:35:34
* @Last Modified by:   skyrim
* @Last Modified time: 2014-09-12 15:12:39
*/
/*2、  形状（二）——虚函数
（1） 将【形状（一）】 中的基类计算面积的方法定义为虚函数，比较与【形状（一）】程序的差异；
*/

#include <iostream>

using namespace std;

//基类
class Shape
{
public:
    Shape(double areas) : area(areas) {}    //构造函数：初始化面积area
    ~Shape() {} //析构函数
    //提供计算面积的方法。注意：get_area是一个虚函数，但是我们并没有在派生类中提供get_area方法，所以基类中的get_area仍旧有效。
    virtual double get_area (){
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