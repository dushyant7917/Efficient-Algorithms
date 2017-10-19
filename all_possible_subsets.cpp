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

void all_subsets(char a[],ll n){
  fr(i,0,1<<n){
    fr(j,0,n){
      if(i&(1<<j)) cout<<a[j]<<" ";
    }
    cout<<"\n";
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n=3;
  //cin>>n;

  char a[n]={'a','b','c'};

  all_subsets(a,n);

  return 0;
}
