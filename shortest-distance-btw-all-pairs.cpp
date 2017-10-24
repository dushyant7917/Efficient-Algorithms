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

ll dist[100][100];

void floyd_warshall(ll n){
  fr(k,0,n){
    fr(i,0,n){
      fr(j,0,n){
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m;
  cin>>n>>m;

  ll x,y,d;

  fr(i,0,n){
    fr(j,0,n){
      dist[i][j]=INF;
    }
  }

  fr(i,0,m){
    cin>>x>>y>>d;
    dist[x][y]=d;
    dist[y][x]=d;
  }

  floyd_warshall(n);

  fr(i,0,n){
    fr(j,i+1,n){
      if(dist[i][j]) cout<<"Min distance btw "<<i<<"---"<<j<<" : "<<dist[i][j]<<"\n";
    }
  }

  return 0;
}
