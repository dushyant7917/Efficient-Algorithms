// Algorithm to find if a given number is of the form 2^n
#include<iostream>
using namespace std;

bool multipleTwo(int x)
{
    return (!(x & (x-1)));
}

int main()
{
int n;
cin>>n;
if(multipleTwo(n))
cout<<n<<" is of the form 2^n";
else
cout<<n<<" is NOT of the form 2^n";
return 0;
}
