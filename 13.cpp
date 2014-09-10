/* 
* @Author: skyrim
* @Date:   2014-09-04 16:35:34
* @Last Modified by:   skyrim
* @Last Modified time: 2014-09-04 17:01:36
*/
/*2、  形状（二）——虚函数
（1） 将【形状（一）】 中的基类计算面积的方法定义为虚函数，比较与【形状（一）】程序的差异；
*/

#include <iostream>

using namespace std;

class Shape
{
public:
    Shape(double areas) : area(areas) { system("pause"); }
    ~Shape() { system("pause") ; }
    virtual double get_area (){
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