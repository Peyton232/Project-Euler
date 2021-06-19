#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


unsigned long long int squareDiff(unsigned long long int n)
{
    unsigned long long int j = floor((n * (n + 1) * (2 * n + 1))/6); //sum of squares
    unsigned long long int m = floor((n * (n + 1))/2);               //square of sums
    m = m * m;
    return m - j;
}

int main() {
    
    int numTests;
    vector<unsigned long long int> n;
    
    cin >> numTests;
    n.resize(numTests);
    
    for (int i = 0; i < numTests; i++) {
        cin >> n[i]; 
    }
    
    for (int i = 0; i < numTests; i++) {
        cout << squareDiff(n[i]) << endl;
    }
    
    
    return 0;
}
