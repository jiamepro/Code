/*
#include <iostream>
#include <vector>
#include <string>

using namespace std;
void sort(vector<int> &nums)
{
    int n = nums.size();
    for(int i = 0; i < n; i++)
    {
        int k = i;
        for(int j = i + 1; j < n; j++)
            if(nums[j] < nums[i]) k = j;
        if(k != i)
        {
            int temp = nums[i];
            nums[i] = nums[k];
            nums[k] = temp;
        }
    }
}
int main()
{
    int n = 0, coins;
    vector<int> costs;
    while(cin >> n)
    {
        costs.push_back(n);
        if(cin.get() == '\n') break;
    }
    cin >> coins;
    sort(costs);
    n = costs.size();
    int sum = 0, pre_sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += costs[i];
        if(pre_sum <= coins && sum > coins)
        {
            n = i;
            break;
        }
        pre_sum = sum;
    }
    for(int i = 0; i < n; i++)
        cout << costs[i] << ' ';

    cout << endl;
    return 0;
}
*/
//以costs给出的顺序返回！！！
//方案：保存要购买的英雄下标
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;
bool cmp_f(pair<int,int> a, pair<int,int> b)
{
    return a.first < b.first;
}
bool cmp_s(pair<int,int> a, pair<int,int> b)
{
    return a.second < b.second;
}
int main()
{
    int n = 0, coins;
    vector<pair<int,int>> costs;
    unordered_set<int> heros;
    while(cin >> n)
    {
        int size = costs.size();
        costs.push_back(pair<int,int>(n,size));
        if(cin.get() == '\n') break;
    }
    cin >> coins;
    sort(costs.begin(),costs.end(),cmp_f);
    n = costs.size();
    int sum = 0;
    unordered_set<int> set;
    for(int i = 0; i < n; i++)
    {
        sum += costs[i].first;
        if(sum > coins) break;
        set.insert(costs[i].second);
    }
    sort(costs.begin(),costs.end(),cmp_s);
    for(int i = 0; i < n; i++)
    {
        if(set.find(i) != set.end()) cout << costs[i].first << ' ';
    }
    cout << endl;

    return 0;
}