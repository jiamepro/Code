#include <stdio.h>

int main()
{
    unsigned char a;
    unsigned char b;
    b = 200;
    a = 50;
    unsigned char c = a - b;
    printf("%b\n", a);
    printf("%b\n", b);
    printf("%b\n", c);
    return 0;
}