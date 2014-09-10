/* 
* @Author: skyrim
* @Date:   2014-09-03 15:43:33
* @Last Modified by:   skyrim
* @Last Modified time: 2014-09-03 17:24:20
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
#include <vector>
#include <fstream>

using namespace std;

class telephone_book
{
public:
    string name;
    string telephone;
};

int main(){
    vector<telephone_book> book;
    telephone_book one ;
    ifstream file("data.txt") ;
    while(file >> one.name >> one.telephone) {
        book.push_back(one) ;
    }
    file.close();
    cout << "1.show all \n2.search \n3.add \n4.delete \n5.save and quit" <<endl ;
    int mode ;
    while(cin >> mode ){
        switch(mode){
            case 1:{
                for( auto &i : book){
                    cout << i.name << '\t' << i.telephone << endl ;
                }
                break ;
            }
            case 2: {
                string search_name;
                cout << "name:" ;
                cin >> search_name ;
                for( auto &i : book){
                    if(search_name == i.name) {
                        cout << i.name << '\t' << i.telephone << endl ;
                        break ;
                    }
                }
                break ;
            }
            case 3: {
                cout << "name:" ;
                cin >> one.name ;
                cout << "telephone:" ;
                cin >> one.telephone ;
                book.push_back(one) ;
                break ;
            }
            case 4: {
                string delete_name ;
                cout << "name:" ;
                cin >> delete_name ;
                auto it = book.begin();
                for( auto &i : book){
                    if(delete_name == i.name) {
                        book.erase(it) ;
                        break ;
                    }
                    else ++it ;
                }
                break ;
            }
            case 5: {
                ofstream save_file ("data.txt") ;
                for( auto &i : book){
                    save_file << i.name << ' ' << i.telephone << endl ;
                }
                save_file.close();
                break ;
            }
            default: cout << "error" ;
        }
        if (mode == 5) break ;
    }
    return 0;
}
