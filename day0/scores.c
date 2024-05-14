#include <stdio.h>
#define N 1005
#define M 1005
int main()
{
    int n = 0, m =0, i = 0, j = 0;
    char scores[N][M] = {0};
    scanf("%d %d",&n,&m);

    while(scanf("%s", scores[i]))
    {
        char c = getchar();
        if( c == ' ') i++;
        else if (c == '\n') break;
    }
//比较一下复杂程度：scanf合适的格式多重要，记住特性，scanf连续读取缓冲器，读取到不符合格式的被舍弃掉
/*

    while(scanf("%s", scores[i]))
    {
        char c = getchar();
        if( c == ' ') i++;
        else if (c == '\n') break;
    }

*/

/*
    while(getchar() != '\n');
    char ch;
    while(scanf("%c", &ch))
    {
        if(ch != ' ') scores[i][j++] = ch;
        if(i == n - 1 && j == m) break;
        if(j == m) 
        {
            i++;
            j = 0;
        }
    }
*/


    return 0;
}