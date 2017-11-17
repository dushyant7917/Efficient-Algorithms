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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

ll n;
ll BIT[N];

void update(ll pos,ll val){
  while(pos<=n){
    BIT[pos]+=val;
    pos+=(pos)&(-pos);
  }
}

ll query(ll pos){
  ll ans=0;
  while(pos>0){
    ans+=BIT[pos];
    pos-=(pos)&(-pos);
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  n=7;

  ll a[n+1];
  fr(i,1,n+1) cin>>a[i];

  fr(i,1,n+1){
    update(i,a[i]);
  }

  // In BIT indexing is 1 based
  // Queries or Updates both in O[log(n)] time

  // sum of a[3]+a[4]+a[5]
  cout<<query(5)-query(2)<<"\n";

  // changing value of a[7] to -2
  update(7,-2-a[7]); a[7]=-2;

  // sum of a[7]
  cout<<query(7)-query(6)<<"\n";

  // adding -2 to the value of a[2]
  update(2,-2); a[2]+=4;

  // sum of a[1]+a[2]+a[3]
  cout<<query(3)-query(0)<<"\n";

  return 0;
}
