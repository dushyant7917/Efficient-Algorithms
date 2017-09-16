// Algorithm to find all the prime factors of a number

#include<iostream>
#include<math.h>

using namespace std;

// A function to print all prime factors of a given number n
void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        cout<<2<<endl;
        n = n/2;
    }

    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            cout<<i<<endl;
            n = n/i;
        }
    }

    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2)
        cout<<n<<endl;
}

void prime_factors(int n){
  int p=1;
  for(int i=2;i*i<=n;i++){
    while(n%i==0){
      p=i;
      n/=i;
    }
    cout<<p<<"\n";
  }
  if(n>1){
    cout<<n<<"\n";
  }
}

int main()
{
    int n;
    cout<<"Enter the number:";
    cin>>n;
    primeFactors(n);
    return 0;
}
