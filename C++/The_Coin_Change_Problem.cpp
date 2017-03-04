
/*
https://www.hackerrank.com/challenges/coin-change

Working: Yes
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long count(vector<int> c, int m, int n){
        vector<vector<long>> t(m+1, vector<long>(n+1));
        for (int i = 0; i <= m; i++)
            t[i][0] = 1; 
        for(int i = 1; i<m+1; i++ ){
            for(int j = 1;j<n+1; j++ ){
                if(j < c[i-1])
                    t[i][j] = t[i-1][j];
                else
                    t[i][j] = t[i-1][j] + t[i][j-c[i-1]];            
            }
        }
        return t[m][n]; 
            
    }

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    cin >> n >> m;
    
    vector<int> c(m);
    
    for(int i=0;i<m;++i){
        cin >> c[i];
    }
    
    cout << count(c,m,n);
    return 0;
}
