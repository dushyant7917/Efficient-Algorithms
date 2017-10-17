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

ll n,m;
bool adj[101][101];

void topological_sort(){
  vector<ll> a;
  bool visited[n+1];
  ll in_degree[n+1];

  fr(i,1,n+1){
    in_degree[i]=0;
    visited[i]=false;
  }

  fr(i,1,n+1){
    fr(j,1,n+1){
      if(adj[i][j]) in_degree[j]++;
    }
  }

  priority_queue<ll,vector<ll>,greater<ll> > pq;

  fr(i,1,n+1){
    if(in_degree[i]==0){
      pq.push(i);
      visited[i]=true;
    }
  }

  while(!pq.empty()){
    ll v=pq.top();
    pq.pop();
    a.PB(v);
    fr(j,1,n+1){
      if(adj[v][j] && !visited[j]){
        in_degree[j]--;
        if(in_degree[j]==0){
          pq.push(j);
          visited[j]=true;
        }
      }
    }
  }

  fr(i,0,a.size()){
    cout<<a[i]<<" ";
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>m;

  ll x,y;
  fr(i,0,m){
    cin>>x>>y;
    adj[x][y]=true;
  }

  topological_sort();

  return 0;
}
