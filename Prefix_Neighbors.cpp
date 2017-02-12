
/*
https://www.hackerrank.com/contests/rookierank-2/challenges/prefix-neighbors

Screenshot:
http://puu.sh/tYyeP.png

Working: No (6/20 TC)
Possible problems: not sure
*/
#include <bits/stdc++.h>

using namespace std;

bool isp(string &a, string &b){//is a a prefix of b
    if(b.size()>=a.size()){
        if(a==b.substr(0,a.size()))
            return true;
    }
    return false;
}

bool ispn(vector<string> &s, string &a, string &b){//are a and b prefix neightbors
    int samecount = 0;
    
    if(!isp(a,b) && !isp(b,a))
        return false;
    
    else{
        for(int i=0;i<s.size();++i){
            if(a.size()<=b.size()){
                if(s[i]==a)
                    ++samecount;
                if(s[i].size()<b.size() && s[i]!=a){
                    if(isp(a,s[i])){
                        return false;
                    }
                }
            }
            else if(a.size()>b.size()){
                if(s[i]==b)
                    ++samecount;
                if(s[i].size()<a.size() && s[i]!=b){
                    if(isp(b,s[i])){
                        return false;
                    }
                }
            }
        }
    }
    if(samecount>1){
        return false;
    }
    return true;
}

bool doespne(vector<string> &s, vector<string> &test){//are there are prefix neighbors in test
    for(int i=0;i<test.size();++i){
        for(int j=0;j<test.size();++j){
            if(i!=j && ispn(s, test[i], test[j])){
                return true;
            }
        }
    }
    return false;
}

bool vispn(vector<string> &s, vector<string> &a, string &b){//would adding b to a make prefix neighbors exist in a
    for(int i=0;i<a.size();++i){
        if(ispn(s,a[i],b)){
            return true;
        }
    }
    return false;
}

int val(string &a){//total ascii value of a string
    int value = 0;
    for(int i=0;i<a.size();++i){
        value+=a[i];
    }
    return value;
}

int vval(vector<string> &a){//total ascii value of vector<string>
    int value = 0;
    for(int i=0;i<a.size();++i){
        value+=val(a[i]);
    }
    return value;
}

vector<string> split(string &str, string sep){//split string based on a seperator
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    std::vector<std::string> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL){
        arr.push_back(current);
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}
vector<vector<string>> powerSet(vector<string> &arr){//find all subsets of s without prefix neighbors
    //vector<string> arr = s;
    int n = arr.size();
    vector<string> list;
    string subset;
    
    for (int i = 0; i < (int) pow(2, n); i++){
        subset = "";
        for (int j = 0; j < n; j++){
            if ((i & (1 << j)) != 0)
                subset += arr[j] + "|";
        }
        
        if (find(list.begin(), list.end(), subset) == list.end())
            list.push_back(subset);
    }
    
    vector<vector<string>> allsubsets;
    
    for (int i=0;i<list.size();++i){
        vector<string> arg = split(list[i], "|");
        
        if(!doespne(arr, arg)){
            allsubsets.push_back(arg);
        }
    }
    
    return allsubsets;
}

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    // your code goes here
    sort(s.begin(),s.end(), std::greater<string>());
    
    vector<vector<string>> sub = powerSet(s);
    
    /*for(int i=0;i<sub.size();++i){
        for(int j=0;j<sub[i].size();++j){
            cout << sub[i][j] << " ";
        }
        cout << endl;
    }*/

    int maxv=0, tmp;
    
    //int index;
    
    for(int i=0;i<sub.size();++i){
        tmp = vval(sub[i]);
        if(tmp>maxv){
            maxv=tmp;
            //index=i;
        }
    }
    
    /*for(int i=0;i<sub[index].size();++i){
        cout << sub[index][i] << ' ';
    }
    cout << ": ";*/
    
    cout << maxv;
    return 0;
}
