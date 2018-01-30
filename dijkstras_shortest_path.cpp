#include<bits/stdc++.h>

using namespace std;

typedef int ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 0x7fffffff
#define N 100009
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n,m;
vector<pii> adj[N];
bool visited[N];
ll prv[N];
ll dist[N];

void init(){
  fr(i,0,n+1){
    visited[i]=false;
    dist[i]=INF;
    prv[i]=-1;
  }
}

void print_path(ll node){
  if(prv[node]!=-1) print_path(prv[node]);
  cout<<node<<" ";
}

void dijkstra(ll src){
  priority_queue<pii,vector<pii>,greater<pii> > pq;

  init();

  prv[src]=-1;
  dist[src]=0;
  pq.push(MP(0,src));

  ll u,v,w;
  while(!pq.empty()){
    u=pq.top().second; // current node
    pq.pop();

    fr(i,0,SZ(adj[u])){
      v=adj[u][i].second; // neighbour node
      w=adj[u][i].first; // edge weight

      if(!visited[v] && dist[u]+w<dist[v]){
        dist[v]=dist[u]+w;
        pq.push(MP(dist[v],v));
        prv[v]=u;
      }
    }

    visited[u]=true;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  ll a,b,w;
  fr(i,0,m){
    cin>>a>>b>>w;
    adj[a].PB(MP(w,b));
    adj[b].PB(MP(w,a));
  }

  dijkstra(1);

  if(dist[n]==INF) cout<<-1;
  else{
    print_path(n);
    cout<<"\nShortest Distance:"<<dist[n];
  }
  cout<<"\n";

  return 0;
}
