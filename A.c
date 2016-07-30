#include<stdio.h>
int main()
{
int n,b,i,j;
scanf("%d",&n);
b=(2*n)+1;
char a[b][b];
for(i=0;i<b;i++)
    for(j=0;j<b;j++)
    {
        if(i==0||i==b-1||j==0||j==b-1)
            a[i][j]='*';
        else
            a[i][j]=' ';
    }
for(i=0;i<b;i++)
    for(j=0;j<b;j++)
    {
        if((i%2==0)&&(i+j<=2*i))
           a[i][j]='*';
        if((j%2==0)&&(i+j<=2*j))
           a[i][j]='*';
    }



for(i=0;i<b;i++)
 {
    for(j=0;j<b;j++)
    printf("%c",a[i][j]);

    printf("\n");
 }

return 0;
}

