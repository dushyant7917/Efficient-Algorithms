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

ll adj[101][101];

bool hamiltonian_path(ll n){
  bool dp[n+1][1<<(n+1)]={0};

  fr(i,0,n) dp[i][1<<i]=true;

  fr(i,0,1<<n){
    fr(j,0,n){
      if(i&(1<<j)){
        fr(k,0,n){
          if(i&(1<<k) && adj[k][j] && k!=j && dp[k][i^(1<<j)]){
            dp[j][i]=true;
            break;
          }
        }
      }
    }
  }

  fr(i,0,n){
    if(dp[i][(1<<n)-1]) return true;
  }
  return false;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m;
  cin>>n>>m;

  ll x,y;
  fr(i,0,m){
    cin>>x>>y;
    adj[x][y]=true;
    adj[y][x]=true;
  }

  if(hamiltonian_path(n)) cout<<"YES";
  else cout<<"NO";

  return 0;
}
