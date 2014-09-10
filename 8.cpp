/* 
* @Author: skyrim
* @Date:   2014-09-02 16:15:36
* @Last Modified by:   skyrim
* @Last Modified time: 2014-09-09 11:14:05
*/
/*
3、  矩阵（三）
编写C++程序完成以下功能：
（1） 用类来实现矩阵，定义一个矩阵的类，属性包括：
   矩阵大小，用 lines, rows（行、列来表示）；
   存贮矩阵的数组指针，根据矩阵大小动态申请（new）。
（2） 矩阵类的方法包括：
   构造函数，参数是矩阵大小，需要动态申请存贮矩阵的数组；
   析构函数，需要释放矩阵的数组指针；
   拷贝构造函数，需要申请和复制数组；
   输入，可以从cin中输入矩阵元素；
   输出，将矩阵格式化输出到cout；
   矩阵相加的函数，实现两个矩阵相加的功能,结果保存在另一个矩阵类，但必须矩阵大小相同；
   矩阵相减的函数，实现两个矩阵相减的功能,结果保存在另一个矩阵类，但必须矩阵大小相同。
（3） 定义三个矩阵：A1、A2、A3；
（4） 初始化A1、A2；
（5） 计算并输出A3 = A1加A2，A3=A1减A2；（要求及提示：最好能实现对赋值操作符“=”的重载；注意检查“自赋值”、释放“旧元素”）
（6） 用new动态创建三个矩阵类的对象：pA1、pA1、pA3；
（7） 初始化pA1、pA2；
（8） 计算并输出pA3=pA1加pA2，pA3=pA1减pA2；
（9） 释放pA1、pA1、pA3。
 */

#include <iostream>

using namespace std;

class matrix
{
public:
    //构造函数1：从用户输入读入行类
    matrix(int line = 0 , int row = 0) : lines(line) , rows(row) {} ;
    //拷贝构造函数：将传入的对象拷贝构造给此对象
    matrix(const matrix& copy_matrix){
        //拷贝行数，列数
        lines = copy_matrix.lines ;
        rows = copy_matrix.rows ;
        //new创建二维数组
        array = new int *[lines];
        for(int j=0 ; j < lines ; j++)
            array[j] = new int [rows]; 
        //给二维数组赋值
        for(int i=0 ; i < lines ; i++)
            for(int j=0 ; j < rows ; j++)
                array[i][j] = copy_matrix.array[i][j] ;
    }
    //析构函数，删除new建立的二维数组
    ~matrix() {
        delete_matrix();
        system("pause") ;
    }
    //这个成员函数用于删除已经建立的动态数组
    void delete_matrix() {
        if (array){
            //删除动态数组
            for(int j=0 ; j < lines ; j++)
                delete array[j] ; 
            delete array ;
            array = 0 ; //数组指针置零
            lines = 0 ; //行置零
            rows = 0 ;  //列置零
        }
    }
    //这个成员函数用于将用户输入的数据存入动态数组
    void input_matrix() {
        //开辟动态数组
        array = new int *[lines];
        for(int j=0 ; j < lines ; j++)
            array[j] = new int [rows];  
        //循环赋值
        for(int i=0 ; i < lines ; i++)
            for(int j=0 ; j < rows ; j++){
                cin >> array[i][j];
            }
    }
    //这个成员函数用于输出动态数组的所有数据
    void output_matrix(){
        for(int i=0 ; i < lines ; i++){
            for(int j=0 ; j < rows ; j++)
                cout << array[i][j];
            cout << endl ;
        }
    }   
    //这个版本的矩阵通过重载=，+，-运算符实现加减操作
    //重载赋值运算符
    matrix & operator=(const matrix &A){
        delete_matrix();    //删除旧数组
        lines = A.lines , rows = A.rows ;
        matrix A3(lines,rows) ;
        //开辟新数组
        array = new int *[lines];
        for(int j=0 ; j < lines ; j++)
            array[j] = new int [rows]; 
        //循环赋值
        for(int i=0 ; i < lines ; i++)
            for(int j=0 ; j < rows ; j++)
                array[i][j]=A.array[i][j];
    }
    friend matrix operator+ (const matrix &A1 ,const matrix &A2);   //重载求和运算符
    friend matrix operator- (const matrix &A1 ,const matrix &A2);   //重载求差运算符
private:
    int **array = 0;    //用于储存动态数组的指针，默认为0（c++11语法）
    int lines ,rows ;   //储存行列
};


int main(){
    int line,row ;
    cout << "Please input the lines and rows of matrix A1:";
    cin >> line >>row ; //读入行列
    matrix A1(line,row) ;   //根据行列建立A1
    cout << "Please input the matrix A1:" ;
    A1.input_matrix();  //输入A1
    cout << "Please input the lines and rows of matrix A2:";
    cin >> line >>row ; //读入行列
    matrix A2(line,row) ;   //根据行列建立A2
    cout << "Please input the matrix A2:" ;
    A2.input_matrix(); //输入A2
    matrix A3;
    A3 = A1 + A2 ;  //求和，A3为A1，A2的和
    A3.output_matrix(); //输出A3
    A3 = A1 - A2 ;  //求差，A3为A1，A2的差
    A3.output_matrix(); //输出A3


    cout << "Please input the lines and rows of matrix A1:";
    cin >> line >>row ; //读入行列
    matrix *pA1 = new matrix (line,row) ;   //根据行列建立pA1
    cout << "Please input the matrix A1:" ;
    pA1->input_matrix();    //输出pA1指向的矩阵
    cout << "Please input the lines and rows of matrix A2:";
    cin >> line >>row ; //读入行列
    matrix *pA2 = new matrix (line,row) ;   //根据行列建立pA1
    cout << "Please input the matrix A2:" ;
    pA2->input_matrix();   //输出pA2指向的矩阵
    matrix *pA3 = new matrix;   //建立pA3
    *pA3 = *pA1 + *pA2 ;    //求和，pA3指向的矩阵为pA1指向的矩阵，pA2指向的矩阵的和
    pA3->output_matrix();   //输出pA3指向的矩阵
    *pA3 = *pA1 - *pA2 ;    //求差，pA3指向的矩阵为pA1指向的矩阵，pA2指向的矩阵的差
    pA3->output_matrix();   //输出pA3指向的矩阵
    //释放pA1，pA2,pA3所指的内存空间
    delete pA1;
    delete pA2;
    delete pA3;

    return 0;
}

//重载+运算符
matrix operator+ (const matrix &A1 ,const matrix &A2){
    matrix A3;
    //如果A1,A2行，列数相等，则求和
    if(A1.lines == A2.lines && A1.rows == A2.rows){
        A3.lines = A1.lines , A3.rows = A1.rows ;
        //开辟新数组
        A3.array = new int *[A3.lines];
        for(int j=0 ; j < A3.lines ; j++)
            A3.array[j] = new int [A3.rows]; 
        for(int i=0 ; i < A3.lines ; i++)
            for(int j=0 ; j < A3.rows ; j++)
                A3.array[i][j]=A1.array[i][j]+A2.array[i][j];
    }
    return A3 ;
}

matrix operator- (const matrix &A1 ,const matrix &A2){
    matrix A3;
    //如果A1,A2行，列数相等，则求和
    if(A1.lines == A2.lines && A1.rows == A2.rows){
        A3.lines = A1.lines , A3.rows = A1.rows ;
        //开辟新数组
        A3.array = new int *[A3.lines];
        for(int j=0 ; j < A3.lines ; j++)
            A3.array[j] = new int [A3.rows]; 
        for(int i=0 ; i < A3.lines ; i++)
            for(int j=0 ; j < A3.rows ; j++)
                A3.array[i][j]=A1.array[i][j]-A2.array[i][j];
    }
    return A3 ;
}
