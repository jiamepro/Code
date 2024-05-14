#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
class mycomp{
    public:
        bool operator()(pair<int, int>& lhs, pair<int, int>& rhs)
        {
            return lhs.first > rhs.first;
        }
};
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> likes(n);
    vector<int> comments(n);
    for (int i = 0; i < n; i++) {
        cin >> likes[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> comments[i];
    }

    // 笔记按评论数从小到大排序
    vector<pair<int, int>> notes;
    for (int i = 0; i < n; i++) {
        notes.push_back({comments[i], likes[i]});
    }
    sort(notes.begin(), notes.end());

    long long maxExcellence = 0;
    long long sumLikes = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycomp> minHeap;

    // 遍历每个评论数作为最小值的候选
    
    for (int i = n - 1; i >= 0; i--) {
        if (minHeap.size() < k) {
            minHeap.push(notes[i]);
            sumLikes += notes[i].second;
        } else {
            if (notes[i].first > minHeap.top().second) {
                sumLikes += notes[i].second - minHeap.top().second;
                minHeap.pop();
                minHeap.push(notes[i]);
            }
        }
        if (minHeap.size() == k) {
            maxExcellence = max(maxExcellence, sumLikes * notes[i].first);
        }
    }

    cout << maxExcellence << endl;
    return 0;
}