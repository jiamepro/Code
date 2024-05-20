#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    void toright(vector<int> &res, vector<vector<int>>& matrix, pair<int,int> &axis, int *boundary, int *count)
    {
        while(axis.second < *boundary)
        {
            res.push_back(matrix[axis.first][axis.second++]);
            (*count)++;
        }
        (*boundary)--;
        axis.second--;
        axis.first++;
    };
    void todown(vector<int> &res,vector<vector<int>>& matrix,pair<int,int> &axis, int *boundary, int *count)
    {
        while(axis.first < *boundary)
        {
            res.push_back(matrix[axis.first++][axis.second]);
            (*count)++;
        }
        (*boundary)--;
        axis.first--;
        axis.second--;
    };
    void toleft(vector<int> &res,vector<vector<int>>& matrix,pair<int,int> &axis, int *boundary, int *count)
    {
        while(axis.second > *boundary)
        {
            res.push_back(matrix[axis.first][axis.second--]);
            (*count)++;
        }
        (*boundary)++;
        axis.second++;
        axis.first--;
    };
    void toup(vector<int> &res,vector<vector<int>>& matrix,pair<int,int> &axis, int *boundary, int *count)
    {
        while(axis.first > *boundary)
        {
            res.push_back(matrix[axis.first--][axis.second]);
            (*count)++;
        }
        (*boundary)++;
        axis.first++;
        axis.second++;
    };
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int count = 0;
        pair<int,int> axis;
        vector<int> res;
        int left_b = -1, right_b = m, up_b = 0, down_b = n;
        
        while(count < m * n)
        {
            toright(res, matrix, axis, &right_b, &count);
            if(count == m * n) break;
            todown(res, matrix, axis, &down_b, &count);
            if(count == m * n) break;
            toleft(res, matrix, axis, &left_b, &count);
            if(count == m * n) break;
            toup(res, matrix, axis, &up_b, &count);
        }
        return res;
    };
};
int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution sol;
    vector<int> res;
    res = sol.spiralOrder(matrix);
    return 0;
}
