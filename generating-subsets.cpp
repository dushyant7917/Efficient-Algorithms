// Generating all subsets

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll nss = 0;

void generate_method1(vector<ll> ss, ll k, ll n) {
  if(n==k) {
    nss++;
    cout<<"\n";
    for(ll i=0;i<ss.size();i++) {
      cout<<ss[i]<<" ";
    }
  }
  else {
    generate_method1(ss,k+1,n);
    ss.push_back(k);
    generate_method1(ss,k+1,n);
    ss.pop_back();
  }
}

void generate_method2(ll n) {
  for(ll i=0;i<(1<<n);i++) {
    vector<ll> ss;
    for(ll j=0;j<n;j++) {
      if(i&(1<<j))
        ss.push_back(j);
    }
  }
}

int main() {

  vector<ll> ss;
  ll n=4;
  //generate_method1(ss,0,n);
  generate_method2(n);
  cout<<"\nNumber of subsets: "<<nss;

  return 0;
}
