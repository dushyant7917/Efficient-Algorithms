#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define pb push_back
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN

ll next_2pow_n(ll n){
  if(n==0) return 0;
  else if(!(n&(n-1))) return n;
  else{
    ll cnt=0;
    while(n!=0){
      n>>=1;
      cnt++;
    }
    return (1<<cnt);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;
  cout<<next_2pow_n(n);

  return 0;
}
