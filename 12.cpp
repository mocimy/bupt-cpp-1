/* 
* @Author: skyrim
* @Date:   2014-09-04 16:34:55
* @Last Modified by:   skyrim
* @Last Modified time: 2014-09-04 17:01:36
*/
/*2、    形状（二）——虚函数
（2） 将【形状（一）】中的基类定义抽象类，比较与【形状（一）】程序的差异。
*/

#include <iostream>

using namespace std;

class Shape
{
public:
    Shape(double areas) : area(areas) { system("pause"); }
    ~Shape() { system("pause") ; }
    virtual double get_area () = 0 ;
private:
    double area ;
};

class rectangle : public Shape
{
public:
    rectangle(double l ,double w) : length(l) , width(w) , Shape(l*w) { system("pause"); }
    ~rectangle() { system("pause") ; }
    double get_area (){
        return length * width ;
    }
private:
    double length , width ;
};

class round : public Shape
{
public:
    round(double r) : radius(r) , Shape(3.1415936 * r * r) { system("pause"); }
    ~round() { system("pause") ; }
    double get_area (){
        return 3.1415936 * radius * radius ;
    }
private:
    double radius;
};

class Square : public rectangle
{
public:
    Square(double l) : Slength(l) , rectangle(l,l) { system("pause"); }
    ~Square() { system("pause") ; }
    double get_area (){
        return Slength * Slength ;
    }
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