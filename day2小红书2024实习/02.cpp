#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.second > b.second;
};
class mycmp{
    public:
    bool operator()(pair<int,int>& a, pair<int,int>& b)
    {
        return a.first > b.first;
    }
};
int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> ab;
    vector<int> a,b;
    int ai;
    while (cin >> ai)
    {
        a.push_back(ai);
        if(cin.get() == '\n') break;
    }
    while (cin >> ai)
    {
        b.push_back(ai);
        if(cin.get() == '\n') break;
    }
    for(int i = 0; i < n; i++)
        ab.push_back(pair<int,int>(a[i],b[i]));
    sort(ab.begin(),ab.end(),cmp);

    priority_queue<pair<int, int>, vector<pair<int,int>>, mycmp> heap;
    long long sum = 0;
    long long maxscore = 0;
    for(int i = 0; i < n; i++)
    {
        if(heap.size() < k)
        {
            heap.push(ab[i]);
            sum += ab[i].first;
        }
        else{
            if(ab[i].first > heap.top().first)
            {
                sum += ab[i].first - heap.top().first;
                heap.pop();
                heap.push(ab[i]);
            }
        }
        if(heap.size() == k) maxscore = max(maxscore, ab[i].second * sum);
    }
    cout << maxscore << endl;
    return 0;
}