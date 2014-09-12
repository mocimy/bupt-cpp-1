
/* 
* @Author: skyrim
* @Date:   2014-09-03 15:43:33
* @Last Modified by:   skyrim
* @Last Modified time: 2014-09-12 16:03:56
*/
/*1、    电话本
        编写C++程序完成以下功能：
（1） 实现简单电话本功能，用姓名来搜索电话号码；
（2） 用户输入姓名，程序查找并输出结果；
（3） 用户可以通过输入，添加姓名和电话号码；
（4） 用户可以删除姓名和电话号码；
（5） 电话本可以保存在指定文件中；
（6） 电话可被从指定文件中读入到内存。
*/

#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main(){
    map<string, string> book;   //map容器，储存姓名和电话
    string name , telephone ;
    //从data.txt读取姓名，电话并添加到book中
    ifstream file("data.txt") ;
    while(file >> name >> telephone) book.insert({name,telephone}) ;
    file.close();
    //本程序实现5个小功能
    cout << "1.show all \n2.search \n3.add \n4.delete \n5.save and quit" <<endl ;
    int mode ;
    while(cin >> mode ){
        switch(mode){
            case 1:{
                //遍历book，输出所有key及对应value
                for(const auto &i : book){
                    cout << i.first << '\t' << i.second << endl ;
                }
                break ;
            }
            case 2: {
                //读入search_name，查找并输出对应的key和value
                string search_name;
                cout << "name:" ;
                cin >> search_name ;
                const auto i = book.find(search_name) ; //查找search_name
                if( i != book.end() ) cout << i->first << ' ' << i->second << endl ;    //找到输出
                else cout << "no this name." << endl ;  //未找到提示
                break ;
            }
            case 3: {
                //读入姓名，电话并添加
                cout << "name:" ;
                cin >> name ;
                cout << "telephone:" ;
                cin >> telephone ;
                if(book.insert({name,telephone}).second) cout << "insert success." << endl ;    //插入成功
                else cout << "insert fail." << endl ;   //插入失败
                break ;
            }
            case 4: {
                //读入姓名，并删除该姓名对应的数据
                string delete_name ;
                cout << "name:" ;
                cin >> delete_name ;
                if(book.erase(delete_name)) cout << "delete success." << endl ; //删除成功
                else cout << "delete fail." << endl ;   //该key不存在，删除失败
                break ;
            }
            case 5: {
                //把所有数据写入文件
                ofstream save_file ("data.txt") ;
                for(const auto &i : book){
                    save_file << i.first << ' ' << i.second << endl ;
                }
                save_file.close();
                break ;
            }
            default: cout << "error" ;
        }
        if (mode == 5) break ;  //跳出循环，结束程序
        cout << "1.show all \n2.search \n3.add \n4.delete \n5.save and quit" <<endl ;
    }
    return 0;
}
