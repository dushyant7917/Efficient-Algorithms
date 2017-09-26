#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define pb push_back
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN

void dijkstras(vector< pair<ll,ll> > edges[],ll n,ll m,ll source_node){
  bool visited[n+1];
  ll dist[n+1];
  fr(i,0,n+1){
    visited[i]=false;
    dist[i]=2e9;
  }
  dist[source_node]=0;

  multiset< pair<ll,ll> > mpq; // min priority queue
  mpq.insert(make_pair(dist[source_node],source_node));

  pair<ll,ll> p;
  ll current_node,edge_weight,neighbour_node;
  while(!mpq.empty()){
    p=*mpq.begin();
    mpq.erase(mpq.begin());
    current_node=p.second;
    if(visited[current_node]==false){ // if node is not visited till now
      visited[current_node]=true;
      fr(i,0,edges[current_node].size()){ // all the neighbour nodes distance is updated
        neighbour_node=edges[current_node][i].second;
        edge_weight=edges[current_node][i].first;
        if(dist[current_node]+edge_weight<dist[neighbour_node]){
          dist[neighbour_node]=dist[current_node]+edge_weight;
          mpq.insert(make_pair(dist[neighbour_node],neighbour_node)); // pushed into min priority queue
        }
      }
    }
  }

  fr(i,2,n+1){
    cout<<dist[i]<<" ";
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,m;
  cin>>n>>m;

  vector< pair<ll,ll> > edges[m+1];
  ll start_node,end_node,weight;
  fr(i,0,m){
    cin>>start_node>>end_node>>weight;
    edges[start_node].pb(make_pair(weight,end_node));
  }

  dijkstras(edges,n,m,1);

  return 0;
}
