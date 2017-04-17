
/*
https://www.hackerrank.com/contests/w31/challenges/zero-one-game

Working: Yes
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 

int q;
    
cin >> q;
    
for(int j=0;j<q;++j){    
    int pmoves=0;
    
    int n;
    cin >> n;
    
    vector<int> game(n);
    stack<int> check;
    stack<int> checked;
    
    for(int i=0;i<n;++i){
        cin >> game[i];
        check.push(game[i]);
    }
    
    if(n<3)
        cout << "Bob";
    else{
        checked.push(check.top());
        check.pop();
        
        int moves = 0;
        
        while(!check.empty()){
            int test = check.top();
            check.pop();
            if(check.empty()){
                break;
            }
            if(check.top()==0 && checked.top()==0){//backtrack by 1
                ++moves;
                checked.pop();
                if(!checked.empty())
                    check.push(0);
                else
                    checked.push(0);
                //cout << " [" << check.top() << test << checked.top() << "] ";
            }
            else{
                checked.push(test);
                //cout << " [" << check.top() << test << checked.top() << "] ";
            }
        }
        
        if(moves%2==0){
            cout << "Bob";
        }
        else{
            cout << "Alice";
        }
        
    }
    cout << endl;
}
    

    return 0;
}
