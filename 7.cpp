/* 
* @Author: skyrim
* @Date:   2014-09-02 15:15:44
* @Last Modified by:   skyrim
* @Last Modified time: 2014-09-12 14:39:34
*/
/*2、    矩阵（二）
编写C++程序完成以下功能：
（1） 假定矩阵大小为4×5（整型）；
（2） 矩阵空间采用new动态申请，保存在指针中；
（3） 定义矩阵初始化函数，可以从cin中输入矩阵元素；
（4） 定义矩阵输出函数，将矩阵格式化输出到cout；
（5） 定义矩阵相加的函数，实现两个矩阵相加的功能,结果保存在另一个矩阵中；
（6） 定义矩阵相减的函数，实现两个矩阵相减的功能,结果保存在另一个矩阵中；
（7） 动态申请三个矩阵：A1、A2、A3；
（8） 初始化A1、A2；
（9） 计算并输出A3 = A1加A2，A3 = A1减A2；
（10）    释放矩阵空间。
*/

#include <iostream>

using namespace std;

class matrix
{
public:
    ~matrix() {
        delete_matrix();
    }
    
    //delete_matrix成员函数：删除用new建立的二维数组
    void delete_matrix() {
        if (array){
            for(int j=0 ; j < 4 ; j++)
                delete array[j] ; 
            delete array ;
            array = 0 ;
        }
    }

    //初始化函数：用于初始化动态数组
    void initialise (){
        /*      峰神提供的方法，想常人之所不能想
                int (*A1)[5];
                A1 = new int [4][5];
        */
        array = new int *[4];
        for(int j=0 ; j < 4 ; j++)
            array[j] = new int [5]; 
    }

    //input_matrix成员函数：用new建立二维数组并逐个赋值
    void input_matrix() {
        initialise () ;  //初始化
        //逐个赋值
        for(int i=0 ; i < 4 ; i++)
            for(int j=0 ; j < 5 ; j++)
                cin >> array[i][j];
    }

    //output_matrix成员函数：把矩阵输出到屏幕
    void output_matrix(){
        for(int i=0 ; i < 4 ; i++){
            for(int j=0 ; j < 5 ; j++)
                cout << array[i][j];
            cout << endl ;
        }
    }   

    //这个版本的矩阵通过声明成员函数来进行加减操作。
    void add (const matrix &A1 ,const matrix &A2 );
    void subtract (const matrix &A1 ,const matrix &A2 );

private:
    //用应该默认为空的指向指针的指针作二维数组的初始化工作
    int **array = 0;
};

int main(){
    matrix A1,A2,A3;
    cout << "Please input the 4*5 matrix A1:" ;
    A1.input_matrix();  //把读到的二维数组推送到A1
    cout << "Please input the 4*5 matrix A2:" ;
    A2.input_matrix();  //把读到的二维数组推送到A2
    A3.add (A1,A2) ;    //A3=A1+A2
    A3.output_matrix(); //A3输出到屏幕
    A3.subtract (A1,A2) ;   //A3=A1-A2
    A3.output_matrix(); //A3输出到屏幕
    //删除建立的动态二维数组
    A1.delete_matrix(); 
    A2.delete_matrix();
    A3.delete_matrix();
    return 0;
}

//求和函数：重新初始化A3，并将A1，A2中的二维数组元素逐个求和赋给A3
void matrix::add (const matrix &A1 ,const matrix &A2 ){
    delete_matrix();    //清空旧元素
    initialise () ;  //初始化
    //逐个赋值
    for(int i=0 ; i < 4 ; i++)
        for(int j=0 ; j < 5 ; j++)
            array[i][j]=A1.array[i][j]+A2.array[i][j];
}

//求和函数：重新初始化A3，并将A1，A2中的二维数组元素逐个求差赋给A3
void matrix::subtract (const matrix &A1 ,const matrix &A2 ){
    delete_matrix();    //清空旧元素
    initialise () ; //初始化
    //逐个赋值
    for(int i=0 ; i < 4 ; i++)
        for(int j=0 ; j < 5 ; j++)
            array[i][j]=A1.array[i][j]-A2.array[i][j];
}
