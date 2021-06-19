#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long newPrime(long long n){     
    
    long long div = 2;
    
    while(div <= floor(sqrt(n))){
        if(n % div == 0){
            n  /= div;
        }else{
            div++;
        }
    }
    
    return n;    
}

int main() {
    
    long long numTests;
    vector<long long> n;
    
    cin >> numTests;
    n.resize(numTests);
    
    for (int i = 0; i < numTests; i++) {
        cin >> n[i]; 
    }
    
    for (int i = 0; i < numTests; i++) {
        cout << newPrime(n[i]) << endl;
    }
    
    return 0;
}
