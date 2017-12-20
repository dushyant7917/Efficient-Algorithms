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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

string str;
ll LCP[N]={0}; // stores length of longest common prefix between suffix i and i+1

struct Suffix{
  ll index;
  ll rank[2]; // ranks
};

struct Suffix suff[N];

bool cmp(struct Suffix s1,struct Suffix s2){
  if(s1.rank[0]==s2.rank[0]){
    if(s1.rank[1]<s2.rank[1]) return true;
    else return false;
  }
  else{
    if(s1.rank[0]<s2.rank[0]) return true;
    else return false;
  }
}

void build_suffix_array(ll n){
  fr(i,0,n){
    suff[i].index=i;
    suff[i].rank[0]=str[i];
    suff[i].rank[1]=((i+1)<n)?(str[i+1]):(-1);
  }

  sort(suff,suff+n,cmp);

  ll ind[n];
  ll next_index,prv_rank,rank;

  for(ll k=4;k<2*n;k=k*2){
    rank=0;
    prv_rank=suff[0].rank[0];
    suff[0].rank[0]=rank;
    ind[suff[0].index]=0;

    fr(i,1,n){
      if(suff[i].rank[0]==prv_rank && suff[i].rank[1]==suff[i-1].rank[1]){
        prv_rank=suff[i].rank[0];
        suff[i].rank[0]=rank;
      }
      else{
        prv_rank=suff[i].rank[0];
        suff[i].rank[0]=++rank;
      }
      ind[suff[i].index]=i;
    }

    fr(i,0,n){
      next_index=suff[i].index+(k/2);
      suff[i].rank[1]=(next_index<n)?(suff[ind[next_index]].rank[0]):(-1);
    }

    sort(suff,suff+n,cmp);
  }
}

void build_lcp(ll n){
  ll inv_suff[n];
  fr(i,0,n) inv_suff[suff[i].index]=i;

  ll k=0,j;
  fr(i,0,n){
    if(inv_suff[i]==n-1){
      k=0;
      continue;
    }

    j=suff[inv_suff[i]+1].index;
    while(i+k<n && j+k<n && str[i+k]==str[j+k]) k++;

    LCP[inv_suff[i]]=k;

    if(k>0) k--;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  str="banana";

  build_suffix_array(str.size());
  build_lcp(str.size());

  fr(i,0,str.size()){
    cout<<LCP[i]<<"\n";
  }

  return 0;
}
