#include<stdio.h>
#include<stdlib.h>
// we have defined the necessary header files here FOR this problem.
// IF additional header files are needed IN your program, please IMPORT here.

int main()
{
    int n = 0, a[34] = {0}, b;
    // please define the C input here. FOR EXAMPLE: int n; scanf("%d",&n);

//二分插入排序
    while( scanf("%d", &a[n]) != EOF){//大有讲究
        //最后一个数字输入的时候需要多打一个空格！怎么解决？
        //输入方式的问题 修改while( (scanf("%d", &a[n])) && getchar() != '\n')
        n++;//注意位置
        int left = 0, right = n - 2;//每次插入一个新数时，新数为a[n-1]，
        while(left < right)
        {
            int mid = left + (right - left)/2;
            if(a[n - 1] < a[mid])  right = mid;
            else left = mid + 1;
        }
        
        a[n] = a[n - 1];
        if(a[n] < a[left]) 
        {
            for(int i = n - 1; i > left; i--) a[i] = a[i - 1];
            a[left] = a[n];
        }
        else if(a[n] > a[left])
        {
            for(int i = n - 1; i > left + 1; i--) a[i] = a[i - 1];
            a[left + 1] = a[n];
        }
        else;
        if(getchar() == '\n') break;//这种方式就要求，最后输入决定不能打空格！
    };
//二分查找——AVL树的搜索路径就是二分查找的搜索路径

    while( (scanf("%d", &b)) && getchar() != '\n');
    int left = 0, right = n - 1;
    while(left < right)
    {
        int mid = left + ((right - left) >> 1);
        if(mid == n/2) printf("S");
        if (b > a[mid]) 
        {
            printf("R");
            left = mid + 1;
        }
        else if(b < a[mid])
        {
            printf("L");
            right = mid;  
        }
        else
        {
            printf("Y");
            break;
        }
    }
    if(left == right) 
        if(a[left] != b) printf("N");
        else printf("Y");
    printf("\n");
    printf("ok\n");
    // please finish the FUNCTION body here.
    // please define the C output here. FOR EXAMPLE: printf("%d",a);
    return 0;
}

