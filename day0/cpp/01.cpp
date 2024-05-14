#include <iostream>
#include <vector>
using namespace std;
//序列找数
int main() {
    int max, num;
    cin >> max;
    int *hash = new int[max];
    while (cin >> num) { // 注意 while 处理多个 case
        hash[num]++;
        if(cin.get() == '\n') break;
    }
    for(int i = 0; i < max; i++)
        if(hash[i] == 0) 
            cout << i << ' ' ;
    cout << endl;
    delete hash;
    return 0;
}
// 64 位输出请用 printf("%lld")
//检测一下内存泄漏？