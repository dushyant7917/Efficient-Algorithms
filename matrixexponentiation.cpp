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

const ll MS=3; // Matrix Size

ll a=1,b=1,c=1;

void multiply(ll X[MS][MS],ll Y[MS][MS]){
  ll tmp[MS][MS];

  fr(i,0,MS){
    fr(j,0,MS){
      tmp[i][j]=0;
      fr(k,0,MS) tmp[i][j]+=X[i][k]*Y[k][j];
    }
  }

  fr(i,0,MS) fr(j,0,MS) X[i][j]=tmp[i][j];
}

void power(ll M[MS][MS],ll x){
  if(x==1) return;

  ll F[MS][MS]={{a,b,c},{1,0,0},{0,1,0}};

  power(M,x/2);
  multiply(M,M);

  if(x&1) multiply(M,F);
}

ll F(ll n){
  if(n==0) return 0;
  if(n<=2) return 1;

  ll M[MS][MS]={{a,b,c},{1,0,0},{0,1,0}};
  power(M,n-2);

  return (M[0][0]*1 + M[0][1]*1 + M[0][2]*0);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  /*
   Matrix exponentiation method to solve linear recurrence relation in log(n) time

   F(0) = 0 , F(1) = 1, F(2) = 1
   F(n) = a*F(n-1) + b*F(n-2) + c*F(n-3) , n>=3

   A = M*B = { {F(n)}, {F(n-1)}, {F(n-2)} } = (M^(n-2))*B
   M = { {a,b,c}, {1,0,0}, {0,1,0} }
   B = { {F(2)}, {F(1)}, {F(0)} } = { {1}, {1}, {0} }
  */

  // Each of the below query evaluates in log(n) time


  fr(i,0,11) cout<<"F("<<i<<") = "<<F(i)<<"\n";

  return 0;
}
