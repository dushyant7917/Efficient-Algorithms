#include<iostream>
#include<math.h>
using namespace std;

int main()
{
  int n,i,cnt=0;
  cin>>n;
  cout<<endl;
  int l=sqrt(n);
  for(i=1;i<=n;i++)
    if(n%i==0)
      {
        cnt++;
      }
  cout<<cnt;
  return 0;
}
