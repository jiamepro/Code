#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool check(vector<int>& a, int cur_likes, int likes, int Max, long long Sum){

}
int main(){

    int n, temp;
    vector<int> a;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int Max = *max_element(a.begin(), a.end());
    long long Sum = accumulate(a.begin(), a.end(), 0);
    for(auto i : a)
    {
        int left(0), right(1e9);
        int mid = right;
        while(left < right)
        {
            if(check(a, i, mid, Max, Sum))
            {
                mid = (left + right)/2;
                left = 
            }
            else
            {
                cout << -1 << endl;
                break;
            }
        }
    }
    
    return 0;
}