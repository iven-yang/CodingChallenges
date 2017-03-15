
/*
https://www.hackerrank.com/challenges/board-cutting

Working: Yes
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<long long int, char> a, pair<long long int, char> b){
    return a.first > b.first;
}

int main(){
   long long int j,k,t,n,m;
    
    cin >> t;
    
    for(long long int v=0;v<t;++v){
        cin >> m >> n;
        vector<pair<long long int, char>> vect;
        
        for(long long int i=0;i<m-1;++i){
            cin >> j;
            vect.push_back(make_pair(j,'h'));
        }
        for(long long int i=0;i<n-1;++i){
            cin >> j;
            vect.push_back(make_pair(j,'v'));
        }
        sort(vect.begin(),vect.end(),cmp);
        
        long long int s1=0,s2=0,ans=0;
        
        for(vector<pair<long long int,char>>::iterator i=vect.begin();i!=vect.end();++i){
            if(i->second=='h'){
                if(s1==0)
                    s1+=2;
                else
                    ++s1;
                if(s2>0)
                    ans+=(i->first*s2);
                else
                    ans+=i->first;
                    
            }
            else{
                if(s2==0)
                    s2+=2;
                else
                    ++s2;
                if(s1>0)
                    ans+=(i->first*s1);
                else
                    ans+=i->first;                
            }
        }
        cout << ans%(1000000007) << endl;       
    }
    return 0;
}
