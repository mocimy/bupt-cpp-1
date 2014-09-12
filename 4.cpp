/* 
* @Author: skyrim
* @Date:   2014-09-02 13:53:35
* @Last Modified by:   skyrim
* @Last Modified time: 2014-09-12 14:15:22
*/
/*3、    流式IO（三）
编写C++程序完成以下功能：
（1） 输入一个文本文件名；
（2） 打开文件名，在该文件的每一行前面加上一个行号，保存在另外一个文本文件中。
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    //filename1：原文件 filename2：有行号的新文件
    string str,filename1,filename2;
    cout << "Please input the old file name:";
    cin >> filename1 ;
    cout << "Please input the new file name:";
    cin >> filename2 ;
    ifstream file1 (filename1.c_str()); //创建输入流
    ofstream file2 (filename2.c_str()); //创建输出流
    int i=0 ;
    //读取一整行，加入行号后写入新文件
    while (getline(file1,str)){
        file2 << ++i << '\t' <<str << endl ;
    }
    //关闭文件
    file1.close();
    file2.close();
    return 0;
}