#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
typedef long long int ll;
using namespace std;

#define max 1000000

vector<ll> generatePrimes(vector<ll> primes)
{
    primes.emplace_back(2);
    for(ll i = 3;i < max; i++)
    {
        int f = 0;
        for(ll j = 2;j <= sqrt(i); j++)
        {
            if(i % j == 0)
            {   
                f = 1;
                break;
            }
        }
        if(f == 0)
        primes.emplace_back(i);
        i++;
    }
    
    return primes;
}

int main(){
    
    int t;
    int n;
    
    cin >> t;
    vector<ll> primes;
    
    //generate list of prime numbers
    primes = generatePrimes(primes);
    
    for(int i = 0; i < t; i++){
        cin >> n;
        cout<<primes[n-1]<<endl;
    }
    return 0;
}
