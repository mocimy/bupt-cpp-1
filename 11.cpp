/* 
* @Author: skyrim
* @Date:   2014-09-03 23:06:50
* @Last Modified by:   skyrim
* @Last Modified time: 2014-09-04 16:32:18
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

class Shape
{
public:
    Shape(double areas) : area(areas) { system("pause"); }
    ~Shape() { system("pause") ; }
    double get_area (){
        return area ;
    }
private:
    double area ;
};

class rectangle : public Shape
{
public:
    rectangle(double l ,double w) : length(l) , width(w) , Shape(l*w) { system("pause"); }
    ~rectangle() { system("pause") ; }
private:
    double length , width ;
};

class round : public Shape
{
public:
    round(double r) : radius(r) , Shape(3.1415936 * r * r) { system("pause"); }
    ~round() { system("pause") ; }
private:
    double radius;
};

class Square : public rectangle
{
public:
    Square(double l) : Slength(l) , rectangle(l,l) { system("pause"); }
    ~Square() { system("pause") ; }
private:
    double Slength ;
};

int main(){
    rectangle a (2,3);
    round b(2);
    Square c(2);
    cout << a.get_area() << '\n' << b.get_area() << '\n' << c.get_area() <<endl ;
    return 0;
}