#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef unsigned long long int ulli;

//unordered_map<ulli , int> collDict;
ulli *collDict=new ulli[5000001];

int collatz(int n){
    ulli temp;
    
    // base case, return number in array
    if (collDict[n]){
        return collDict[n];
    }
    
    // 2 rules for collatz and recurive calls for them
    if (n % 2 == 0){
        temp = n / 2;
        collDict[n]=1+collatz(temp);
        return collDict[n];
    }
    temp = n * 3 + 1;
    ulli count = 1;
    // iterate while out of bounds of array, till again a safe number
    while(temp > 5000001)
    {
        if(temp % 2 == 0)
        {
            temp /= 2;
        }
        else
        {
            temp = temp * 3 + 1;
        }
        count++;
    }
    
    collDict[n]=count + collatz(temp);
    return collDict[n];
}

int main() {
    
    collDict[1] = 0;
    ulli n, k;
    ulli count=0;
    
    // powers of two always divide down to 1
    for(ulli i = 2; i <= 5000001; i = i * 2)
    {            
        count++;
        collDict[i] = count;            
    }
    
    // Now figure out and store all other chain lengths
    for(ulli i = 1;i <= 5000001; i++)
    {
        collatz(i);
    }
    
    // Now starting at 1 figure out the digit below a number with the largets chain
    ulli *results = new ulli[5000001];
    results[1]=1;
    for(ulli a = 2; a <= 5000001; a++)
    {
        if(collDict[a] >= collDict[results[a-1]])
        {
            results[a] = a;
        }
        else
        {
            results[a] = results[a-1];
        }
    }
    
    // take in user input for resulting longest collatz
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        cout << results[k] << endl;
    }
    
    delete [] results;
    delete [] collDict;
    
    return 0;
}
