#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

//helper function
bool isPalindrome(int givenNumber){
    int currentDigit, reversedNumber = 0;
    int copyNumber = givenNumber;
    do
    {
        currentDigit = copyNumber % 10; //takes the remainder
        reversedNumber = (reversedNumber * 10) + currentDigit; //creating the reversed number
        copyNumber= copyNumber / 10; //creating new number
    } while (copyNumber != 0);
    
    if (givenNumber == reversedNumber)
        return true;
    else
        return false;
}

int palindrome(int n, unordered_map<int, bool> palindromelist)
{
    n--;
    
    while (n > 0) {
        if (palindromelist[n]){
            return n;
        } else {
            n--;
        }
    }
    
    // num does not exist 
    return -1;
}

int main() {
    
    int numTests;
    vector<int> n;
    
    cin >> numTests;
    n.resize(numTests);
    
    for (int i = 0; i < numTests; i++) {
        cin >> n[i]; 
    }
    
    //generate the list
    unordered_map<int, bool> palindromelist;
    int temp;
    
    for (int i = 100; i < 1000; i++)
    {
        for (int j = 100; j < 1000; j++)
        {
            temp = i * j;
            if (isPalindrome(temp))
                palindromelist[temp] = true;
        }
    }
    
    for (int i = 0; i < numTests; i++) {
        cout << palindrome(n[i], palindromelist) << endl;
    }
    return 0;
}
