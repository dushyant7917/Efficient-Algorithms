// Algorithm to find number of common elements in two lists
// Time Complexity = O(nlogn)

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {

  ll a[]={5,2,8,9,4,7}; // 2,4,5,8,9
  ll b[]={3,2,9,5};   // 2,3,5,9

  ll n1=6;
  ll n2=4;

  sort(a,a+n1);
  sort(b,b+n2);

  ll num_common = 0;

  // Assuming n2 < n1
  ll i,j;
  for(i=0;i<n2;i++) {
    if(a[i]==b[i]) {
      num_common++;
    }
  }
  for(j=i;j<n1;j++) {
    if(b[i-1]==a[j]) {
      num_common++;
    }
  }

  cout<<num_common;

  return 0;
}
