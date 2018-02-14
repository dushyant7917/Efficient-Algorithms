#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll a[N];
ll block[101];
ll block_size;

void update(ll ind,ll val){
  block[ind/block_size]+=(val-a[ind]);
  a[ind]=val;
}

ll query(ll l,ll r){
  ll sum=0;

  // calculating for first block in range
  while(l<r && l%block_size!=0 && l!=0) sum+=a[l++];

  // calculating for completely overlapped blocks in range
  while(l+block_size<=r){
    sum+=block[l/block_size];
    l+=block_size;
  }

  // calculating for last block in range
  while(l<=r) sum+=a[l++];

  return sum;
}

void build(ll n){
  ll ind=-1;
  block_size=sqrt(n);

  fr(i,0,n){
    if(i%block_size==0) ind++;
    block[ind]+=a[i];
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  fr(i,0,n) cin>>a[i];

  build(n);

  // a[3]+a[4]...a[8]
  cout<<query(3,8)<<"\n";

  // a[1]+a[2]...a[6]
  cout<<query(1,6)<<"\n";

  // a[8]...a[8]
  cout<<query(8,8)<<"\n";

  // a[3]=4;
  update(3,4);

  // a[2]+a[3]...a[4]
  cout<<query(2,4)<<"\n";

  return 0;
}
