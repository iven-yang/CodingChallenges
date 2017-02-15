
/*
https://www.hackerrank.com/challenges/largest-rectangle

Screenshot:
http://puu.sh/tYxlP.png

Working: Yes
http://puu.sh/tYxQE.png
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,j,tmp,length,max=0;
    vector<int> heights;
    cin >> n;
    heights.resize(n,0);
    for(int i=0;i<n;++i){
        cin >> tmp;
        heights[i]=tmp;
    }

    for(int i=0;i<n;++i){
        j=i;
        length=0;
        while(heights[i]<=heights[j] && j<n){
            ++length;
            ++j;
        }
        j=i;
        --length;
        while(heights[i]<=heights[j] && j>=0){
            ++length;
            --j;
        }
        if(length*heights[i]>max)
            max = length*heights[i];
    }
    cout << max;    
    return 0;
}
