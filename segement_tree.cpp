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

ll n,len;
ll tree[N];

void build(ll a[]){
  len=2*n;
  fr(i,n,len) tree[i]=a[i-n];

  for(ll i=n-1;i>=1;i--){
    tree[i]=min(tree[i*2],tree[(i*2)+1]);
  }
}

void update(ll pos,ll val){
  pos+=n;
  tree[pos]=val;

  while(pos>1){
    pos=pos/2;
    tree[pos]=min(tree[pos*2],tree[(pos*2)+1]);
  }
}

ll query(ll left,ll right){
  ll min_val=INF;
  left+=n;
  right+=n;

  while(left<right){
    if(left%2==1){
      min_val=min(min_val,tree[left]);
      left++;
    }
    if(right%2==1){
      right--;
      min_val=min(min_val,tree[right]);
    }
    left=left/2;
    right=right/2;
  }

  return min_val;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  n=8;
  ll a[n];
  fr(i,0,n) cin>>a[i];

  build(a);

  // Segment tree follows 1 based indexing
  // Queries and Updates both in O[log(n)] time

  // min in range [0,1) or [0,0]
  cout<<query(0,1)<<"\n";

  // min in range [0,8) or [0,7]
  cout<<query(0,8)<<"\n";

  // min in range [3,6) or [3,5]
  cout<<query(3,6)<<"\n";

  // value of a[4] updated to -2
  update(4,-2);

  // min in range [3,6) or [3,5]
  cout<<query(3,6)<<"\n";

  return 0;
}
