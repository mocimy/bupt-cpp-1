/* 
* @Author: skyrim
* @Date:   2014-09-02 14:26:53
* @Last Modified by:   skyrim
* @Last Modified time: 2014-09-04 19:02:47
*/
/*1、    流式IO（一）
编写C++程序完成以下功能：
（1） 使用ofstream 向一个文本文件中输出各种类型的数据，并打开文件观察结果：
   整数、无符号整型、长整型、浮点型、字符串、……
（2） 用十进制、八进制、十六进制方式向文本文件中输出整数；
（3） 使用控制符和成员函数来控制输出的格式：
   set（） precision() ...
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    ofstream file("data.txt");
    int a = -1 ;    //整数
    unsigned b = 1 ;    //无符号整型
    long int c = 1111111111 ;   //长整型
    double d = 3.1415 ; //浮点型
    string e = "bupt" ; //字符串
    file << a << '\n' << b << '\n' << c << '\n' << d << '\n' << e << endl ;
    file << oct << 123 << endl ;    //八进制输出
    file << dec << 123 << endl ;    //十进制输出
    file << hex << 123 << endl ;    //十六进制输出
    file << setprecision(3) << 3.1415936 ;  //利用setprecision函数控制数字位数
    return 0;
}