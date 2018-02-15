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
#define N 200001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
ll a[N];
ll ans;
ll block_size;

struct Query{
  ll l; // left
  ll r; // right
  ll ind; // original index
  ll res; // result of query
};

struct Query q[N];

bool cmp1(struct Query q1,struct Query q2){
  if(q1.l/block_size==q2.l/block_size){
    if(q1.l==q2.l) return (q1.r < q2.r);
    else return (q1.l < q2.l);
  }
  else return (q1.l/block_size < q2.l/block_size);
}

bool cmp2(struct Query q1,struct Query q2){
  return (q1.ind < q2.ind);
}

void add(ll ind){
  ans+=a[ind];
}

void remove(ll ind){
  ans-=a[ind];
}

void process(){
  ll cl,cr;

  cl=1;
  cr=0;
  ans=0;

  ll l,r;
  fr(i,0,m){
    l=q[i].l;
    r=q[i].r;

    while(cr<r){
      cr++;
      add(cr);
    }

    while(cr>r){
      remove(cr);
      cr--;
    }

    while(cl<l){
      remove(cl);
      cl++;
    }

    while(cl>l){
      cl--;
      add(cl);
    }

    q[i].res=ans;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  fr(i,1,n+1) cin>>a[i];

  block_size=sqrt(n);

  // assuming 1 based indexing

  ll a,b;
  fr(i,0,m){
    cin>>a>>b;
    q[i].l=a;
    q[i].r=b;
    q[i].ind=i;
  }

  sort(q,q+m,cmp1);

  process();

  sort(q,q+m,cmp2);

  fr(i,0,m){
    cout<<"Sum in range ["<<q[i].l<<","<<q[i].r<<"]"<<" : ";
    cout<<q[i].res<<"\n";
  }

  return 0;
}
