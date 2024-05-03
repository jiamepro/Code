#include <stdio.h>
#define N 100

int main()
{
    int nums[N] = {0}, n = 0;
    
// 冒泡排序
/*
    //while(scanf("%d",&nums[n++]));//缺少终止条件!
    while(n < N)
    {
        scanf("%d", &nums[n++]);
        if(getchar() == '\n') break;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
            if(nums[j] < nums[i]) 
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
    }
*/

/*
// 优化:简单选择排序
    while(scanf("%d", &nums[n++]))
        if(getchar() == '\n') break;
    for(int i = 0; i < n; i++)
    {
        int min = i;
        for(int j = i + 1; j < n; j++)
            if(nums[min] > nums[j]) min = j;
        if(min != i)
        {
            int temp = nums[i];
            nums[i] = nums[min];
            nums[min] = temp;
        }
    }
*/

// 直接插入排序：扑克牌
    while(scanf("%d", &nums[n++]))
        if(getchar() == '\n') break;
    for(int i = 1; i < n; i++)
    {
        int ist = i;
        for(int j = i - 1; j >= 0; j--)
            if(nums[i] < nums[j]) ist = j;

        if(ist != i) 
        {
            int temp = nums[i];
            for(int j = i; j > ist; j--) //数组移动从前往后会覆盖
                nums[j] = nums[j - 1];
            nums[ist] = temp;
        }
    }
// 希尔排序
// 堆排序(大顶堆/小顶堆)
// 二分法插入排序

    return 0;
}
