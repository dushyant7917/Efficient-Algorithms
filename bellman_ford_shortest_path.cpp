#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define pb push_back
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN

void bellman_ford(vector<ll> edges[],ll n,ll m,ll source_node){
  ll dist[n+1];
  fr(i,1,n+1){
    dist[i]=2e9;
  }
  dist[source_node]=0;

  fr(i,0,n){
    fr(j,0,m){
      if(dist[edges[j][1]]+edges[j][0]<dist[edges[j][2]]){
        dist[edges[j][2]]=dist[edges[j][1]]+edges[j][0];
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

  vector<ll> edges[m+1];

  ll start_edge,end_edge,weight;
  fr(i,0,m){
    cin>>start_edge>>end_edge>>weight;
    edges[i].pb(weight);
    edges[i].pb(start_edge);
    edges[i].pb(end_edge);
  }

  bellman_ford(edges,n,m,1);

  return 0;
}
