
/*
https://www.hackerrank.com/challenges/crush

Screenshot:
http://puu.sh/tYxAI.png

Working: Yes
http://puu.sh/tYxDu.png
*/

#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

void justdoit(vector<long long> &kek, int a, int b, int k){
    kek[a]+=k;
    kek[b]-=k;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long size, ops;
    long long a,b,k;
    long long maxi = 0, mini = 0;//numbers will get very very big
    cin >> size >> ops;
    
    vector<long long> kek;
    kek.assign(size+1,0);
    
    for(size_t i=0;i<size_t(ops);++i){
        cin >> a >> b >> k;
        justdoit(kek,a-1,b,k);
    }
    for(size_t i=0;i<size_t(size);++i){
        mini+=kek[i];
        maxi = max(maxi, mini);
    }
    cout << maxi;
    return 0;
}

