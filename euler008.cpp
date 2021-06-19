#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int largestSequence(string sequence, int k){
    
    int max = 0;
    int temp = 1;
    
    for (int i = 0; i < sequence.length() - k; i++)
    {
        temp = 1;
        for (int j = 0; j < k; j++)
        {
            temp *= sequence[i+j] - 48;
        }
        
        if (temp > max)
        {
            max = temp;
        }   
    }
    
    return max;
}

int main() {
    int numTests;
    vector<string> n;
    vector<int> k;
    
    cin >> numTests;
    n.resize(numTests);
    k.resize(numTests);
    
    for (int i = 0; i < numTests; i++) {
        cin >> k[i];    //ignores
        cin >> k[i]; 
        cin >> n[i]; 
    }
    
    
    for (int i = 0; i < numTests; i++) {
        cout << largestSequence(n[i], k[i]) << endl;
    } 
    return 0;
}
