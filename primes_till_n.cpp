#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fr(a,b) for(ll i=a;i<b;i++)

void prime_nums(ll n){
  bool primes[n+1];
  memset(primes, true, sizeof(primes)); // primes[0 to n] = true

  ll i,j;
  for(i=2;i*i<=n;i++){
    // i is still unmarked
    if(primes[i]){
      // Mark numbers which are mutiples of i excluding i itself
      for(j=i*2;j<=n;j=j+i){
        primes[j]=false;
      }
    }
  }

  // Printing all primes
  for(i=2;i<=n;i++){
    if(primes[i]){
      cout<<i<<"\n";
    }
  }

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cout<<"Enter the number:";
  ll n;
  cin>>n;
  cout<<"Prime numbers upto n(inclusive) are...";
  prime_nums(n);

  return 0;
}
