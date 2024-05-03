//二叉树，回溯
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void backtracking(int level, int* sum, int N, vector<int>& path) //扭蛋数sum不能是临时变量，sum == N 时递归返回会改变，不能返回
{
    if(path.size() == level)//重点，两种情况
        return;
        
    for(int i = 2; i <= 3; i++)
    {
        int n = *sum;//这一阶段的扭蛋数

        path.push_back(i);
        if(i == 2) *sum = 2*n + 1;
        else if(i == 3) *sum = 2*n + 2;

        backtracking(level, sum , N, path);

        if(*sum == N) return; //如果扭蛋数 == N，一直返回
        
        path.pop_back();
        *sum = n;//恢复扭蛋数
    }
}

int main()
{
    vector<int> path;
    int N; cin >> N;
    if(N == 0) return 0;

    int sum = 0;
    int level = log((float)N + 1)/log(2);
    int *path_new = new int[level];
    int cur = level - 1;
    for(int i = 2; i <= 3; i++)//横向是必要的，假如N=1
    {
        int n = sum;//这一阶段的扭蛋数

        path.push_back(i);
        if(i == 2) sum = 2*n + 1;
        else if(i == 3) sum = 2*n + 2;

        backtracking(level, &sum , N, path);

        if(sum == N) break; //如果扭蛋数 == N，一直返回
        
        path.pop_back();
        sum = n;//恢复扭蛋数
    }

    for(auto i : path)
        cout << i ;
    cout << endl;
    return 0;
}

//时间复杂度太高？？？O(n)但N很大啊

//有奇偶性啊......