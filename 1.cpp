/* 
* @Author: skyrim
* @Date:   2014-09-02 12:15:36
* @Last Modified by:   skyrim
* @Last Modified time: 2014-09-10 15:16:10
*/
/*1、    猜价格游戏
编写C++程序完成以下功能：
（1） 假定有一件商品，程序用随机数指定该商品的价格（1-1000的整数）；
（2） 提示用户猜价格，并输入：若用户猜的价格比商品价格高或低，对用户作出相应的提示；
（3） 直到猜对为止，并给出提示。
（提示及要求：1，要求使用C++的输入输出方式（cin, cout），不能使用C语言的printf等；2，注意检查输入的合法性）
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    //1.根据时间生成随机数
    srand (time(NULL));
    int price = rand()%1000 ;   
    int price_guess ;
    cout << "Please input price:" <<price;
    //2.循环判断用户输入数据与生成随机数之间的关系
    cin >> price_guess ;
    while(price_guess!=price) {
        //读到的不是一个数：提示失败
        if (cin.fail()) {
            cout << "It's wrong." ;
            cin.clear();
            cin.sync();
        }
        //用户输入数据高了
        else if (price_guess > price) cout << "It's high.";
        //用户输入数据低了
        else cout << "It's low.";
        cin >> price_guess ;
    }
    cout << "You're right." ;
    return 0;
}