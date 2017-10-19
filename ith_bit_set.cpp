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

// ith bit from RHS
bool ith_bit_set(ll n,ll i){
  if(n&(1<<i)) return true;
  else false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,i;
  cin>>n>>i;

  cout<<ith_bit_set(n,i);

  return 0;
}
