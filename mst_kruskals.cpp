#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN

ll component[1000001];

void initialize(ll n){
  fr(i,0,n+1){
    component[i]=i;
  }
}

ll find_component(ll node){
  while(component[node]!=node){
    component[node]=component[component[node]];
    node=component[node];
  }
  return node;
}

void union_components(ll node1,ll node2){
  ll x=find_component(node1);
  ll y=find_component(node2);
  component[x]=component[y];
}

ll kruskals(pair<ll, pair<ll,ll> > edges[],ll m){
  ll node1,node2,weight;
  ll cost=0;
  fr(i,0,m){
    node1=edges[i].second.first;
    node2=edges[i].second.second;
    weight=edges[i].first;
    if(find_component(node1)!=find_component(node2)){
      cost+=weight;
      union_components(node1,node2);
    }
  }
  return cost;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,m;
  cin>>n>>m;

  initialize(n);

  pair<ll, pair<ll,ll> > edges[m];

  ll node1,node2,weight;
  fr(i,0,m){
    cin>>node1>>node2>>weight;
    edges[i]=mp(weight,mp(node1,node2));
  }

  sort(edges,edges+m);

  cout<<kruskals(edges,m);

  return 0;
}
