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

ll n,m;
ll a[N];
ll block_size;

struct Query{
  ll l; // left
  ll r; // right
  ll ind; // original index
  ll res; // result of query
};

struct Query q[N];

bool cmp1(struct Query q1,struct Query q2){
  if(q1.l/block_size==q2.l/block_size) return (q1.r < q2.r);
  else return (q1.l/block_size < q2.l/block_size);
}

bool cmp2(struct Query q1,struct Query q2){
  return (q1.ind < q2.ind);
}

void process(){
  ll cl,cr,sum;
  cl=cr=sum=0;

  ll l,r;
  fr(i,0,m){
    l=q[i].l;
    r=q[i].r;

    while(cl<l) sum-=a[cl++];

    while(cl>l){
      sum+=a[cl-1];
      cl--;
    }

    while(cr<=r) sum+=a[cr++];

    while(cr>r+1){
      sum-=a[cr-1];
      cr--;
    }

    q[i].res=sum;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  fr(i,0,n) cin>>a[i];

  block_size=sqrt(n);

  cin>>m;
  fr(i,0,m){
    cin>>q[i].l>>q[i].r;
    q[i].ind=i;
  }

  sort(q,q+m,cmp1);

  process();

  sort(q,q+m,cmp2);

  fr(i,0,m){
    cout<<"ind:"<<q[i].ind<<" l:"<<q[i].l<<" r:"<<q[i].r<<" res:";
    cout<<q[i].res<<"\n";
  }

  return 0;
}
