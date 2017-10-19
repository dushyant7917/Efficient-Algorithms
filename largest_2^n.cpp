#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9

// returns largest (2^n) kind of number <= n
ll largest_2_pow_n(ll n){
  n=n|(n>>1);
  n=n|(n>>2);
  n=n|(n>>4);
  n=n|(n>>8);

  return (n+1)>>1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  cout<<largest_2_pow_n(n);

  return 0;
}
