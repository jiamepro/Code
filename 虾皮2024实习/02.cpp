#include <iostream>
#include <vector>
#include <string>

using namespace std;
string reverse(string str)
{
    int n = str.size();
    for(int i = 0; i < n/2; i++)
    {
        char temp;
        temp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = temp;
    }
    return str;
}
int main(){
    string str;
    vector<string> strs;
    while(cin >> str)
    {
        strs.push_back(str);
        if(cin.get() == '\n') break;
    }
    int n = strs.size();
    for(int i = 0; i < n; i++)
    {
        cout <<  reverse(strs[i]);
        if(i != n - 1) cout << ' ';
    }
    cout << endl;
    return 0;
}

