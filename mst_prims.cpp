#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define pb push_back
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN

ll mst_prims(ll source_node,bool marked[],vector< pair<ll,ll> > edges[]){
  priority_queue< pair<ll,ll>, vector< pair<ll,ll> >, greater< pair<ll,ll> > > pq;
  ll cost=0;
  pq.push(make_pair(0,1));

  pair<ll,ll> p;
  ll x,y;
  while(!pq.empty()){
    p=pq.top();
    pq.pop();
    if(marked[p.second]==false){
      cost+=p.first;
      marked[p.second]=true;
      fr(i,0,edges[p.second].size()){
        if(marked[edges[p.second][i].second]==false) pq.push(edges[p.second][i]);
      }
    }
  }

  return cost;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,m;
  cin>>n>>m;

  vector< pair<ll,ll> > edges[n+1];
  ll weight,node1,node2;
  fr(i,0,m){
    cin>>node1>>node2>>weight;
    edges[node1].pb(make_pair(weight,node2));
    edges[node2].pb(make_pair(weight,node1));
  }

  bool marked[n+1]={false};

  // We are calculating mst from node1 but any node can be used
  cout<<mst_prims(1,marked,edges);

  return 0;
}
