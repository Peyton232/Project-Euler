#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



long long int fibEven(long long int n)
{
    long long int sum = 0;
    long long int a = 1;
    long long int b = 2;
    long long int temp;
    
    for(; a < n;){
        if((a % 2) == 0)
            sum += a; 
        temp= a +b;
        a = b;
        b = temp;
    }
    
    return sum;
}

int main() {
    
    int numTests;
    vector<long long int> n;
    
    cin >> numTests;
    n.resize(numTests);
    
    for (int i = 0; i < numTests; i++) {
        cin >> n[i]; 
    }
    
    
    for (int i = 0; i < numTests; i++) {
        cout << fibEven(n[i]) << endl;
    }
    
    
    return 0;
}
