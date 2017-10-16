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
stack<ll> a;
bool visited[101];

void topological_sort(ll node){
  visited[node]=true;
  fr(i,1,n+1){
    if(adj[node][i] && !visited[i]){
      topological_sort(i);
    }
  }
  a.push(node);
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

  topological_sort(1);

  while(!a.empty()){
    cout<<a.top()<<" ";
    a.pop();
  }

  return 0;
}
