#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int t,i;
    scanf("%d",&t);
    long long a[t][2],p,q,x,y;
    for(i=0;i<t;i++)
    {
        scanf("%lld",&a[i][0]);
        scanf("%lld",&a[i][1]);
    }

    for(i=0;i<t;i++)
    {
        p=a[i][0];
        q=a[i][1];
        if(p<q)
        {
            x=p;
            y=q;
        }
        else
        {
            x=q;
            y=p;
        }

        if(p==q)
            printf("%d\n",1);
        else if(y<=(2*x))
            printf("%d\n",abs(p-q));
        else
            printf("%d\n",-1);

    }
    return 0;
}
