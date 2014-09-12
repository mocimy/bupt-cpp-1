/* 
* @Author: skyrim
* @Date:   2014-09-02 14:46:21
* @Last Modified by:   skyrim
* @Last Modified time: 2014-09-12 14:36:23
*/
/*1、    矩阵（一）
编写C++程序完成以下功能：
（1） 假定矩阵大小为4×5（整型数组表示）；
（2） 定义矩阵初始化函数，可以从cin中输入矩阵元素；
（3） 定义矩阵输出函数，将矩阵格式化输出到cout；
（4） 定义矩阵相加的函数，实现两个矩阵相加的功能,结果保存在另一个矩阵中；
（5） 定义矩阵相减的函数，实现两个矩阵相减的功能,结果保存在另一个矩阵中；
（6） 定义三个矩阵：A1、A2、A3；
（7） 初始化A1、A2；
（8） 计算并输出：A3 = A1加A2，A3 = A1减A2。
*/

#include <iostream>

using namespace std;

//matrix(矩阵)类
class matrix
{
public:
    matrix() = default ;    //构造函数1：用于处理无参数情况
    matrix(int input_matrix[4][5]) {    //构造函数2：用传入的二维数组进行初始化
        for(int i=0 ; i < 4 ; i++)
            for(int j=0 ; j < 5 ; j++)
                array[i][j]=input_matrix[i][j];
    }
    //output_matrix成员函数，把矩阵输出到屏幕
    void output_matrix(){
        for(int i=0 ; i < 4 ; i++){
            for(int j=0 ; j < 5 ; j++)
                cout << array[i][j];
            cout << endl ;
        }
    }   
    //这个版本的矩阵通过声明友元来进行加减操作。注意：这里不推荐这样做，参看矩阵2。
    friend void add (const matrix &A1 ,const matrix &A2 ,matrix &A3);
    friend void subtract (const matrix &A1 ,const matrix &A2 ,matrix &A3);
private:
    //储存4*5矩阵
    int array[4][5];
};

//add，subtract函数原型
void add (const matrix &A1 ,const matrix &A2 ,matrix &A3);
void subtract (const matrix &A1 ,const matrix &A2 ,matrix &A3);

int main(){
    int array[4][5];
    cout << "Please input the 4*5 matrix A1:" ;
    //读入第一个4*5矩阵
    for(int i=0 ; i < 4 ; i++)
        for(int j=0 ; j < 5 ; j++)
            cin >> array[i][j];
    matrix A1(array);   //初始化A1
    cout << "Please input the 4*5 matrix A2:" ;
    //读入第二个4*5矩阵
    for(int i=0 ; i < 4 ; i++)
        for(int j=0 ; j < 5 ; j++)
            cin >> array[i][j];
    matrix A2(array);   //初始化A2
    matrix A3;
    add (A1,A2,A3) ;    //A2，A2求和赋给A3
    A3.output_matrix();     //输出A3
    subtract (A1,A2,A3) ;   //A2，A2求差赋给A3
    A3.output_matrix();     //输出A3
    return 0;
}

//求和函数：将A1，A2中的二维数组元素逐个求和赋给A3
void add (const matrix &A1 ,const matrix &A2 ,matrix &A3){
    for(int i=0 ; i < 4 ; i++)
        for(int j=0 ; j < 5 ; j++)
            A3.array[i][j]=A1.array[i][j]+A2.array[i][j];
}

//求和函数：将A1，A2中的二维数组元素逐个求差赋给A3
void subtract (const matrix &A1 ,const matrix &A2 ,matrix &A3){
    for(int i=0 ; i < 4 ; i++)
        for(int j=0 ; j < 5 ; j++)
            A3.array[i][j]=A1.array[i][j]-A2.array[i][j];
}