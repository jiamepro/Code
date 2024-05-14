#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // 包含这个头文件以使用 accumulate

using namespace std;

bool check(const vector<int>& likes, int i, int x, int MX, int SUM) {
    if (x % 2 == 0) x--;
    int diff = x / 2 + 1;
    int cur = SUM - likes[i] + (x - diff);
    if (likes[i] + diff >= MX && (likes[i] + diff) * (likes.size() - 1) >= cur)
        return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> likes(n);
    for (int i = 0; i < n; i++) {
        cin >> likes[i];
    }

    int MX = *max_element(likes.begin(), likes.end());
    int SUM = accumulate(likes.begin(), likes.end(), 0);
    
    vector<int> res(n, 0);

    for (int i = 0; i < n; i++) {
        if (n == 2 && likes[i] < MX - 1) {
            res[i] = -1;
            continue;
        }
        if (likes[i] == MX) {
            res[i] = SUM;
            continue;
        }

        int l = 1, r = 1e9;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(likes, i, mid, MX, SUM)) r = mid;
            else l = mid + 1;
        }
        res[i] = SUM + l;
    }

    for (int result : res) {
        cout << result << endl;
    }
    
    return 0;
}