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

ll par[N],rank[N];

void createSet(ll n){
  fr(i,0,n+1){
    par[i]=i;
    rank[i]=0;
  }
}

ll findSet(ll x){
  if(par[x]!=x) par[x]=findSet(par[x]);
  return par[x];
}

void mergeSet(ll x,ll y){
  ll xx=findSet(x);
  ll yy=findSet(y);

  if(rank[xx]>rank[yy]) par[yy]=xx;
  else par[xx]=yy;

  if(rank[xx]==rank[yy]) rank[yy]++;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  createSet(5);
  cout<<"Initially\n";
  fr(i,1,5+1) cout<<i<<" belongs to set:"<<findSet(i)<<"\n";

  cout<<"\nAfter merging 1 and 2\n";
  if(findSet(1)!=findSet(2)) mergeSet(1,2);
  fr(i,1,5+1) cout<<i<<" belongs to set:"<<findSet(i)<<"\n";

  cout<<"\nAfter merging 4 and 5\n";
  if(findSet(5)!=findSet(4)) mergeSet(5,4);
  fr(i,1,5+1) cout<<i<<" belongs to set:"<<findSet(i)<<"\n";

  cout<<"\nAfter merging 1 and 4\n";
  if(findSet(1)!=findSet(4)) mergeSet(1,4);
  fr(i,1,5+1) cout<<i<<" belongs to set:"<<findSet(i)<<"\n";

  return 0;
}
