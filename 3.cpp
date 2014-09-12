/* 
* @Author: skyrim
* @Date:   2014-09-02 13:28:50
* @Last Modified by:   skyrim
* @Last Modified time: 2014-09-12 14:09:45
*/
/*3、    友元
编写C++程序完成以下功能：
（1） 定义一个Boat和Car两个类，他们都具有私有属性——重量；
（2） 编写一个函数，计算两者的重量和。
double TotalWeight(Boat& b, Car& c);
*/

#include <iostream>

using namespace std;


class Car;  //声明Car类，便于声明友元函数
class Boat
{
public:
    Boat(double TheWeight) : weight(TheWeight) {}   //Boat构造函数
    friend double TotalWeight(Boat& b, Car& c);     //声明友元

private:
    double weight;  //weight成员变量
};

class Car
{
public:
    Car(double TheWeight) : weight(TheWeight) {};   //Car构造函数
    friend double TotalWeight(Boat& b, Car& c);     //声明友元

private:
    double weight;  //weight成员变量
};

double TotalWeight(Boat& b, Car& c);

int main(){
    double weight;
    cout << "Please input weight of the boat:" ;
    cin >> weight ;
    Boat b(weight) ;    //创建Boat类对象
    cout << "Please input weight of the car:" ;
    cin >> weight ;
    Car c(weight) ;     //创建Car类对象
    cout << "The total weight is:" << TotalWeight (b,c);    //调用友元，输出结果
    return 0;
}

//Boat和Car的友元，功能：求重量和
double TotalWeight(const Boat& b,const Car& c){
    return b.weight + c.weight ;
}