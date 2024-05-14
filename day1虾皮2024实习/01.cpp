/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<int> num;
    while (cin >> n)
    {
        num.push_back(n);
        if(cin.get() == '\n') break;
    }
    //每次比较所有数字的最高位，取一个最高的出来
    //定一个排列的规则！
    int size = num.size();
    string *nums = new string[size];
    for(int i = 0; i < size; i++)
        nums[i] = to_string(num[i]);

    //从最高位开始比，最高位大的先输出
    //最高位一样比较次高位，依次类推
    //长数字和短数字先输出短数字

    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            int k = 0, l, s;
            string lstr, sstr;
            if(nums[i].size() > nums[j].size())
            {
                l = nums[i].size();
                s = nums[j].size();
                lstr = nums[i];
                sstr = nums[j];
            }
            else
            {
                l = nums[j].size();
                s = nums[i].size();
                lstr = nums[j];
                sstr = nums[i];
            }
            while(lstr[k] > sstr[k] && k < s)
                k++;
            if(k < s)
            {
                string temp;
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }
            else
            {
                while()
            }
            //但是当有两个数字一长一短，该那个排前面？
            //7891023811111
            //78910238
            //789102381111178910238
            //789102387891023811111
            //长的往下部分继续跟短的比
        }
    }
    return 0;
}
*/
//字典序
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    vector<int> num;
    while (cin >> n)
    {
        num.push_back(n);
        if(cin.get() == '\n') break;
    }
    int size = num.size();
    string *nums = new string[size];
    for(int i = 0; i < size; i++)
        nums[i] = to_string(num[i]);
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(nums[i] + nums[j] < nums[j] + nums[i])
            {
                string temp;
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
    for(int i = 0; i < size; i++)
    cout << nums[i] ;
    cout << endl;
    return 0;
}