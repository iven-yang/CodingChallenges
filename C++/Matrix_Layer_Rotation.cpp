
/*
https://www.hackerrank.com/challenges/matrix-rotation-algo

Working: Yes
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m, n, r;
    int temp;
    
    cin >> m >> n >> r;
    
    vector<vector<int>> matrix(m, vector<int>(n));
    
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
        
    for(int i = 0; i < (m<n ? m:n)/2; ++i){
        for(int j = 0; j < r%((m-i*2)*2+(n-i*2)*2-4); ++j) {
            temp = matrix[i][i];
            for(int k = 0; k < n-1-(2*i); ++k)
                    matrix[i][i+k]=matrix[i][i+k+1];
            for(int k = 0; k < m-1-(2*i); ++k)      
                    matrix[i+k][n-i-1]=matrix[i+k+1][n-1-i];
            for(int k = 0; k < n-1-(2*i); ++k)
                    matrix[m-i-1][n-1-i-k]=matrix[m-1-i][n-1-i-k-1];
            for(int k = 0; k < m-1-(2*i); ++k)      
                    matrix[m-1-i-k][i]=matrix[m-1-i-k-1][i];
            matrix[i+1][i] = temp;
            }
    }
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
    	cout << "\n";
    }
    
    return 0;
}
