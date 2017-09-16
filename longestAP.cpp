// Finds length of longest AP possible in an array
// Input = {1, 7, 10, 15, 27, 29}
// Output = 3
// The longest arithmetic progression is {1, 15, 29}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dbl;
#define fr(a,b) for(ll i=a;i<b;i++)

int main(){
  ll n;
  cin>>n;
  ll a[n];
  fr(0,n) cin>>a[i];
  sort(a,a+n);

  ll dp[n][n];
  ll i,j,k;

  fr(0,n) for(j=0;j<n;j++) dp[i][j]=2;

  if(n<=2){
    cout<<n;
    return 0;
  }

  ll len=2;

  for(j=n-1;j>=1;j--){
    i=j-1;
    k=j+1;
    while(i>=0 && k<=n-1){
      if(a[i]+a[k]>(2*a[j])){
        dp[i][j]=2;
        i--;
      }
      else if(a[i]+a[k]<(2*a[j])){
        k++;
      }
      else{
        dp[i][j]=dp[j][k]+1;
        len=max(len,dp[i][j]);
        i--;
        k++;
      }
    }
  }

  cout<<len;

  return 0;
}
