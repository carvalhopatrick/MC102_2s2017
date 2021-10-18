#include <stdio.h>
int main()
{
    int a=0, b=0;

    printf("enter a and b \n");
    scanf("%d%d",&a,&b);
    printf("printing logical condition a<20 xor b<20\n\n");

    if((a < 20) ^ (b < 20))
    {
        printf("true \n\n");
    }
    else
    {
        printf("false \n\n");
    }

    return 0;
}
