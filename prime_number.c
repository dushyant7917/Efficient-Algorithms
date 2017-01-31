// Algorithm to find if a given number is prime or not

#include<stdio.h>

int prime_num(int number)
{
    if(number==1)
       return 0;
    if(number==2)
       return 1;
    if(number==3)
       return 1;
    if(number%2==0)
       return 0;
    if(number%3==0)
       return 0;

    int i=5;
    int w=2;

    while(i*i<=number)
     {
        if(number%i==0)
            return 0;

        i+=w;
        w=6-w;
     }

    return 1;
}

int main()
{
    int num;
    printf("Enter a number:");
    scanf("%d",&num);

    if(prime_num(num)==1)
    printf("\n%d is a prime number.",num);
    else
    printf("\n%d is a not a prime number.",num);

    return 0;
}
