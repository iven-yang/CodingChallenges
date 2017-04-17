
/*
https://www.hackerrank.com/contests/w31/challenges/accurate-sorting

Working: Yes
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <limits.h>
using namespace std;

void numswap(vector<int>& nums, int i, int j){
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

bool sortable(const vector<int>& snums, vector<int>& nums){
    int n = nums.size();
    
    for(int i=0;i<n;++i){
        if(nums[i]!=snums[i]){
            if(i+1<n){
                if(nums[i+1]==snums[i] && snums[i+1]==nums[i]){
                    numswap(nums,i,i+1);
                    ++i;
                }
                else
                    return false;
            }
        }
    }
    
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,q;
    
    cin >> q;
    
    for(int i=0;i<q;++i){
        cin >> n;
        vector<int> nums(n);
        vector<int> snums(n);
        for(int j=0;j<n;++j){
            cin >> nums[j];
            snums[j] = nums[j];
        }
        
        sort(snums.begin(), snums.end());
        
        bool sorted = sortable(snums, nums);        
        
        if (sorted)
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    
    
    
    return 0;
}
