#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
typedef long long int ll;
using namespace std;

int pythagoreanTriplet(int n){     
    
    int a, b, c;
    int result = -1;
    
    for (a = 3; a <= n/3; a++) {
        b = floor((n * n - 2*a*n)/(2*n - 2*a));
        c = n - b - a;
        if (a*a + b*b == c*c){
            if (a*b*c > n)
                result = a*b*c;
        }
            
    }
   
   return result;
}


int main() {
    
    int numTests;
    vector<int> n;
    
    cin >> numTests;
    n.resize(numTests);
    
    for (int i = 0; i < numTests; i++) {
        cin >> n[i]; 
    }
    
    for (int i = 0; i < numTests; i++) {
        cout << pythagoreanTriplet(n[i]) << endl;
    }
    
    return 0;
}
