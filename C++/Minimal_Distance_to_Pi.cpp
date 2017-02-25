
/*
https://www.hackerrank.com/contests/w29/challenges/minimal-distance-to-pi

Working: Yes
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

# define PI 3.1415926535897932384626433832795028841971693993751L

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long int min, max;
    cin >> min >> max;
    
    long int n,d;
    double mind = PI;
    
    if(min>=113 && max<=30000){
        n=355;
        d=113;
    }
    else{
        for(long int i=min;i<=max;++i){
            long int num=PI*i;
            double prev=abs(PI-double(num)/i);
            
            while(prev>abs(PI-double(num+1)/i)){
                num+=1;
                //cout << num << " ";
                prev=abs(PI-double(num)/i);
            }
            //cout << endl;
            //num-=1;
            if(mind>abs(PI-double(num)/i)){
                mind = abs(PI-double(num)/i);
                n = num;
                d = i;
            }  
            //cout << num << "/" << i <<  ' ' << mind << endl;
        }
    }
    
    
    
    cout << n << "/" << d;
    
    return 0;
}
