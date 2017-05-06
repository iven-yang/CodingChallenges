
/*
https://www.hackerrank.com/challenges/queens-attack-2

Working: Yes
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,k;
    cin >> n >> k;
    int row,col;
    cin >> row >> col;
    --row;
    --col;
    
    //vector<vector<bool>> board(n,vector<bool>(n,false));
    //vector<vector<int>> blocked(k,vector<int>(2));
    
    unordered_map<string, bool> board;
    board.reserve(k);
    
    for(int i=0;i<k;++i){
        int x,y;
        cin >> x >> y;
        --x;
        --y;
        string block = to_string(x) + to_string(y);
        board[block] = true;
    }
    
    int num = 0;
    
    int r=row+1,c=col;//straight up
    while(r<n){
        string j = to_string(r)+to_string(c);
        if(board[j]==true){
            break;
        }
        ++r;
        ++num;
    }
    
    r=row-1,c=col;//straight down
    while(r>=0){
        string j = to_string(r)+to_string(c);
        if(board[j]==true){
            break;
        }
        --r;
        ++num;
    }
    
    r=row,c=col+1;//straight left
    while(c<n){
        string j = to_string(r)+to_string(c);
        if(board[j]==true){
            break;
        }
        ++c;
        ++num;
    }
    
    r=row,c=col-1;//straight right
    while(c>=0){
        string j = to_string(r)+to_string(c);
        if(board[j]==true){
            break;
        }
        --c;
        ++num;
    }
    
    /*Diagonals*/
    
    r=row+1,c=col-1;//upper left
    while(r<n && c>=0){
        string j = to_string(r)+to_string(c);
        if(board[j]==true){
            break;
        }
        ++r;
        --c;
        ++num;
    }
    
    r=row+1,c=col+1;//upper right
    while(r<n && c<n){
        string j = to_string(r)+to_string(c);
        if(board[j]==true){
            break;
        }
        ++r;
        ++c;
        ++num;
    }
    
    r=row-1,c=col-1;//lower left
    while(r>=0 && c>=0){
        string j = to_string(r)+to_string(c);
        if(board[j]==true){
            break;
        }
        --r;
        --c;
        ++num;
    }
    
    r=row-1,c=col+1;//lower right
    while(r>=0 && c<n){
        string j = to_string(r)+to_string(c);
        if(board[j]==true){
            break;
        }
        --r;
        ++c;
        ++num;
    }
    
    
    cout << num;
    return 0;
}
