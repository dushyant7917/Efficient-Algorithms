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
vector<ll> adj1[N];
vector<ll> adj2[N];
bool visited[N];
stack<ll> st;
vector<ll> cmp[N];
ll ind=0;

void dfs(ll v,ll g){
  visited[v]=true;
  if(g==2) cmp[ind].PB(v);

  ll u;
  if(g==1){
    fr(i,0,SZ(adj1[v])){
      u=adj1[v][i];
      if(!visited[u]) dfs(u,1);
    }
  }
  if(g==2){
    fr(i,0,SZ(adj2[v])){
      u=adj2[v][i];
      if(!visited[u]) dfs(u,2);
    }
  }

  st.push(v);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;
  ll a,b;
  fr(i,0,m){
    cin>>a>>b;
    adj1[a].PB(b);
    adj2[b].PB(a);
  }

  MS(visited,false);
  fr(i,1,n+1){
    if(!visited[i]) dfs(i,1);
  }

  MS(visited,false);
  ll v;
  while(st.size()){
    v=st.top();
    st.pop();
    if(!visited[v]){
      dfs(v,2);
      ind++;
    }
  }

  ll c=1;
  fr(i,0,ind){
    cout<<"Nodes in component "<<c++<<" : ";
    fr(j,0,SZ(cmp[i])) cout<<cmp[i][j]<<" ";
    cout<<"\n";
  }

  return 0;
}
