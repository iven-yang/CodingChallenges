
/*
https://www.hackerrank.com/contests/w30/challenges/melodious-password

Working: Yes
*/

#include <bits/stdc++.h>

using namespace std;

bool isVowel(char x){
    if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u'){
        return true;
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    
    vector<vector<string>> ans(n);
    
    string letters = "abcdefghijklmnopqrstuvwxz";
    string vowels = "aeiou";
    string cons = "bcdfghjklmnpqrstvwxz";
    
    int j=0;
    while(j<n){
        if(j==0){
            for(int i=0;i<letters.size();++i){
                string lettertoadd(1,letters[i]);
                ans[0].push_back(lettertoadd);
            }
        }
        else{
            for(int i=0;i<ans[j-1].size();++i){
                string tmp = ans[j-1][i];
                
                if(isVowel(tmp[tmp.size()-1])){
                    for(int k=0;k<cons.size();++k){
                        string contoadd(1,cons[k]);
                        ans[j].push_back(tmp+contoadd);
                    }
                }
                else{
                    for(int k=0;k<vowels.size();++k){
                        string vowtoadd(1,vowels[k]);
                        ans[j].push_back(tmp+vowtoadd);
                    }
                }
            }
        }
        
        ++j;
    }
    
    for(int i=0;i<ans[n-1].size();++i){
        cout << ans[n-1][i] << endl;
    }
    
    return 0;
}
