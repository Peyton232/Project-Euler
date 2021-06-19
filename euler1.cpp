#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int multiples(long long int n)
{
    long long int sum = 0;
    long long int three = (n - 1) / 3;
    long long int five = (n - 1) / 5;
    long long int fifteen = (n - 1) / 15;

    sum += 3 * (three * (three + 1) / 2);
    sum += 5 * (five * (five + 1) / 2);
    sum -= 15 * (fifteen * (fifteen + 1) / 2);
    
    return sum;
}

int main() {
    
    long long int numTests;
    vector<int> n;
    
    cin >> numTests;
    n.resize(numTests);
    
    for (int i = 0; i < numTests; i++) {
        cin >> n[i]; 
    }
    
    
    for (int i = 0; i < numTests; i++) {
        cout << multiples(n[i]) << endl;
    }
    
    
    return 0;
}
