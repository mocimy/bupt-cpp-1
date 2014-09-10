/* 
* @Author: skyrim
* @Date:   2014-09-03 14:18:15
* @Last Modified by:   skyrim
* @Last Modified time: 2014-09-10 15:10:21
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

    //
    Point & operator++ (){
        ++x;
        ++y;
        return *this;
    }
    //
    Point & operator-- (){
        --x;
        --y;
        return *this;
    }
    //
    Point operator++ (int){
        Point ret = *this ;
        ++ *this ;
        return ret;
    }
    //重载后置--运算符
    Point operator-- (int){
        Point ret = *this ;
        -- *this ;
        return ret;
    }
    void print_point (){
        cout << "(" << x << "," << y << ")" ;
    }
private:
    double x,y;
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
            case 1 : (mypoint++).print_point(); break;
            case 2 : (mypoint--).print_point(); break;
            case 3 : (++mypoint).print_point(); break;
            case 4 : (--mypoint).print_point(); break;
            default : cout << "error!" ;
        }
    }
    return 0;
}