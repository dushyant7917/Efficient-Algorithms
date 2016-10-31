#include<iostream>
#include<math.h>
using namespace std;

int main()
{
  int n,i,cnt=0;
  cin>>n;
  cout<<endl;
  int l=sqrt(n);
  for(i=1;i<=l;i++)
    if(n%i==0)
      {
        cnt++;
        if(i!=(n/i))
        {
          cnt++;
        }
      }
  cout<<endl<<cnt;
  return 0;
}
