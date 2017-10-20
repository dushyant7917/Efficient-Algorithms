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

ll gcd_or_hcf(ll a,ll b){
  if(a==0 || b==0) return 0;

  if(a==b) return a;

  if(a<b) return gcd_or_hcf(a,b-a);
  else return gcd_or_hcf(a-b,b);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll a,b;
  cin>>a>>b;

  cout<<gcd_or_hcf(a,b);

  return 0;
}
