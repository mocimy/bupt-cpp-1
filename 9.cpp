/* 
* @Author: skyrim
* @Date:   2014-09-03 14:18:15
* @Last Modified by:   skyrim
* @Last Modified time: 2014-09-12 15:01:16
*/
/*1、    对Point类重载＋＋和――运算符
    编写C++程序完成以下功能：
（1） Point类的属性包括点的坐标（x，y）；
（2） 实现 Point类重载＋＋和――运算符：
   ++p，--p，p++，p--。
   ＋＋和――分别表示x，y增加或减少1。
*/

#include <iostream>

using namespace std;

class Point
{
public:
    Point(): x(0) ,y(0) {}  //构造函数1：不传入坐标，赋值（0,0）
    Point (double x_coordinate , double y_coordinate) : x(x_coordinate) , y(y_coordinate) {}    //构造函数2：传入坐标，所以用户传入的值

    //++a（返回新值）
    Point & operator++ (){
        ++x;
        ++y;
        return *this;
    }
    //--a（返回新值）
    Point & operator-- (){
        --x;
        --y;
        return *this;
    }
    //a++（返回旧值）
    Point operator++ (int){
        Point ret = *this ;
        ++ *this ;
        return ret;
    }
    //a--（返回旧值）
    Point operator-- (int){
        Point ret = *this ;
        -- *this ;
        return ret;
    }
    //成员函数：输出坐标
    void print_point (){
        cout << "(" << x << "," << y << ")" ;
    }
private:
    double x,y; //储存坐标
};

int main(){
    double x ,y ;
    int mode ;
    cout << "Please input the point :" ;
    cin >> x >> y ;
    Point mypoint(x,y);
    cout << ("1.Point++ \n2.Point-- \n3.++Point \n4.Point-- \n ");
    while(cin >> mode) {
        switch(mode){
            case 1 : (mypoint++).print_point(); break;  //输出a++
            case 2 : (mypoint--).print_point(); break;  //输出a--
            case 3 : (++mypoint).print_point(); break;  //输出++a
            case 4 : (--mypoint).print_point(); break;  //输出--a
            default : cout << "error!" ;
        }
    }
    return 0;
}