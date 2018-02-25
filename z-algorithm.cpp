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

string pattern,text,s;
ll z[2*N];

void construct_z_array(){
  s="";
  s+=pattern;
  s+='$';
  s+=text;

  ll n=SZ(s);
  ll l=0,r=0,k;

  z[0]=-1; // useless

  fr(i,1,n){
    if(i>r){
      l=r=i;

      while(r<n && s[r-l]==s[r]) r++;

      z[i]=r-l;
      r--;
    }
    else{
      k=i-l;
      if(z[k]<r-i+1) z[i]=z[k];
      else{
        l=i;
        while(r<n && s[r-l]==s[r]) r++;
        z[i]=r-l;
        r--;
      }
    }
  }
}

ll search(){
  ll cnt=0;

  fr(i,1,SZ(s)) if(z[i]==SZ(pattern)) cnt++;

  return cnt;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>text;
  cin>>pattern;

  construct_z_array();
  cout<<search();

  return 0;
}
