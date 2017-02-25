
/*
https://www.hackerrank.com/contests/w29/challenges/megaprime-numbers

Working: 10/20 (Big O Runtime needs to be better)
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool isPrime(int x, unordered_map<int, bool> &primes, vector<int> &allprimes){
    if(primes.find(x)!=primes.end()){
        return true;
    }
    /*if(x < 2){
        //primes[x] = false;
        return false;
    }
    
    if(x==2){
        if(primes.find(x)==primes.end()){
            primes[x] = true;
            allprimes.push_back(x);
        }
        return true;
    }*/

    for(int i = 0; i<allprimes.size() && allprimes[i]<=sqrt(x); ++i){        
        if(x % allprimes[i] == 0){
            //primes[x] = false;
            return false;
        }
    }
    //primes[x] = true;
    if(primes.find(x)==primes.end()){
        primes[x]=true;
        allprimes.push_back(x);
    }
    return true;
}
bool isMega(int x){
    vector<int> digits(10,0);
    while(x){
        digits[x%10]=1;
        x/=10;
    }
    for(int i=0;i<digits.size();++i){
        if(digits[0]==1 || digits[1]==1 || digits[4]==1 || digits[6]==1 || digits[8]==1 || digits[9]==1){
            return false;
        }
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int first, last;
    cin >> first >> last;
    unordered_map<int, bool> primes;
    vector<int> allprimes;
    
    for(int i = 2; i < first; i++) {
        isPrime(i,primes,allprimes);
    }
    
    int ans=0;
    for(int i=first; i<=last; ++i){
        if(isMega(i)){
            if(isPrime(i, primes, allprimes)){
                ++ans;
                //cout << i << " ";
            }
        }
    }
    //cout << endl;
    cout << ans;
    return 0;
}
