#include<stdio.h>
int pn(int z);
int prime(int x);
int special_prime(int y);
int j;
int prime(int x)
{
    if((x!=2)&&(x%2==0))
        return 0;
    else
    {
        int cnt=0;
        for(j=2;j<=x;j++)
           if(x%j==0)
             cnt++;

        if(cnt==1)
            return 1;
        else
           return 0;
    }
}

int special_prime(int y)
{
    if((y!=2)&&(y%2==0))
        return 0;
    else
    {
        int cnt=0;
        for(j=2;j<=y;j++)
           if(y%j==0)
              cnt++;

        if(cnt==1)
           return 1;
        else
           return 0;
    }
}

int pn(int z)
{
    if(z==2)
       return 1;
    if(z==3)
       return 1;
    if(z%2==0)
       return 0;
    if(z%3==0)
       return 0;

    int i=5;
    int w=2;

    while(i*i<=z)
     {
        if(z%i==0)
            return 0;

        i+=w;
        w=6-w;
     }

    return 1;
}

int main()
{
    int n,i,k,k2,p,kk,m,flag,pp;
    scanf("%d",&n);
    scanf("%d",&i);

    for(k=2;k<=n;k+=1)
    {
        p=pn(k);
        if(p==1)
        {
            k2=k;
            pp=0;
            flag=0;
            while(flag<i)
            {
                if(pn(2*k2+1)==1)
                    {
                        pp++;
                        k2=k2*2+1;
                        flag++;
                        if((k2!=2)&&(k2%2==0))
                            break;
                    }
                else
                    break;
            }
            if(pp==i)
            printf("%d ",k);
        }

    }

    return 0;
}

