#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

//primes
// 2,3,5,7,11,13,17,19,23,29,31,37
const unordered_map<int, bool> primeDict({{2, true},
                                        {3, true},
                                        {5, true},
                                        {7, true},
                                        {11, true},
                                        {13, true},
                                        {17, true},
                                        {19, true},
                                        {23, true},
                                        {29, true},
                                        {31, true},
                                        {37, true}});

// M is divisible by all numbers from 1 to N iff M is equal to the product 
//of all prime powers p^k where p is prime and divides M, and p < N, 
//and k is the largest integer such that p^k < N. For example, 
//lcm10 = 2520 = 2^3 * 3^2 * 5 * 7.

bool isPrime(int n){
    if (primeDict.find(n) != primeDict.end())
        return true;
    return false;
}

int smallestMultiple(int n)
{
    vector<int> primeList;
    int powerCounter;
    int multiple = 1;
    
    for(int i = 2; i <= n; i++)
    {
        if (isPrime(i))
            primeList.push_back(i);
    }
    
    for (int i = 0; i < primeList.size(); i++) {
        powerCounter = 1;
        while (primeList[i] < n){
            if (pow(primeList[i], powerCounter) > n){
                primeList[i] = pow(primeList[i], powerCounter - 1);
                break;
            } else {
                powerCounter++;
            }
        }
    }
    
    for (int i = 0; i < primeList.size(); i++){
        multiple *= primeList[i];
    }
    
    return multiple;
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
        cout << smallestMultiple(n[i]) << endl;
    }
    return 0;
}
