
/*
https://www.hackerrank.com/contests/world-codesprint-10/challenges/maximal-and-subsequences

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void subset(const vector<long int>& A, int k, int start, int currLen, vector<bool>& used, vector<vector<long int>>& subnums) {

		if (currLen == k) {
            vector<long int> tmp;
			for (int i = 0; i < A.size(); i++) {
				if (used[i] == true) {
					tmp.push_back(A[i]);
				}
			}
			subnums.push_back(tmp);
			return;
		}
		if (start == A.size()) {
			return;
		}
		
		used[start] = true;
		subset(A, k, start + 1, currLen + 1, used, subnums);
		
		used[start] = false;
		subset(A, k, start + 1, currLen, used, subnums);
	}

long int bite(const vector<long int>& nums){
    long int sum = nums[0];
    for(int i=1;i<nums.size();++i){
        sum = sum & nums[i];
    }
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,k;
    cin >> n >> k;
    
    vector<long int> nums(n);
    vector<vector<long int>> subnums;
    vector<bool> used(n, false);
    
    for(int i=0;i<n;++i){
        cin >> nums[i];
    }
    
    long int max=0;
    int num=0;
    
    subset(nums, k, 0, 0, used, subnums);
    
    
    for(int i=0;i<subnums.size();++i){
        long int tmp = bite(subnums[i]);
        if(tmp>max){
                num = 1;
                max = tmp;
            }
        else if(tmp==max)
            ++num;
    }
    
    cout << max << "\n" << num;
    
    return 0;
}
