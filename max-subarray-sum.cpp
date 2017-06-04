// Algorithm to find the maximum sum in a continuous subarray
// Atleast one number should be greater than equal to 0 in the array

#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
typedef long long ll;
using namespace std;

int main() {

  ll arr[8]={-1,2,4,-3,5,2,-5,2};
  ll max_sum=0;
  ll sum_k=0;
  rep(k,0,7) {
    sum_k=max(arr[k],arr[k]+sum_k);
    max_sum=max(max_sum,sum_k);
  }
  cout<<"Maximum sum: "<<max_sum<<"\n";

  return 0;
}
