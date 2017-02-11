
/*
https://www.hackerrank.com/contests/rookierank-2/challenges/knightl-on-chessboard

Screenshots:
http://puu.sh/tXFbo.png
http://puu.sh/tXFc9.png

Working: Yes
http://puu.sh/tYxIr.png
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int dist(int n, int x, int y){
    return (n-x-1)+(n-y-1);
}

/*int ezaf(int n, int x, int y, int a, int b, int moves, vector<vector<bool>> &visited){ // Recursion was not the answer LOL
    //if(x<n && y<n && x>=0 && y>=0){
        visited[x][y]=true;
    //}
    
    
    //int urg = 0;
    
    if((n-1)%(a+b)==0){
        return 2*(n-1)/(a+b);
    }
    if(a==b && (n-1)%(a+b)!=0){
        return INT_MAX;
    }
    if(x==n-1 && y==n-1){
        return moves;
    }
    else if((n-a-1==x && n-b-1==y) || (n-b-1==x && n-a-1==y)){
        return moves+1;
    }
    else if(moves>2*(n)){
        return INT_MAX;
    }
    
    vector<int> movez(8, INT_MAX);
    
    int c = max(a,b);
    if(x>=n-2*c && y>=n-2*c){
        if((x+a)<n && (y+b)<n){
            if(!visited[x+a][y+b])
                movez[0]=(ezaf(n, x+a, y+b, a, b, moves+1, visited));
        }
        if((x+b)<n && (y+a)<n){
            if(!visited[x+b][y+a])
                movez[3]=(ezaf(n, x+b, y+a, a, b, moves+1, visited));
        }
        
        if((x+a)<n && (y-b)>=0){
            if(!visited[x+a][y-b])
                movez[1]=(ezaf(n, x+a, y-b, a, b, moves+1, visited));
        }
        if((x-a)>=0 && (y+b)<n){
            if(!visited[x-a][y+b])
               movez[2]=(ezaf(n, x-a, y+b, a, b, moves+1, visited));
        }
        
        if((x+b)<n && (y-a)>=0){
            if(!visited[x+b][y-a])
                movez[4]=(ezaf(n, x+b, y-a, a, b, moves+1, visited));
        }
        if((x-b)>=0 && (y+a)<n){
            if(!visited[x-b][y+a])
                movez[5]=(ezaf(n, x-b, y+a, a, b, moves+1, visited));
        }
        sort(movez.begin(),movez.end());
        return movez[0];
    }
    else{
    if((x+a)<n && (y+b)<n){
        if(!visited[x+a][y+b])
            movez[0]=dist(n,x+a,y+b);
    }
    if((x+b)<n && (y+a)<n){
        if(!visited[x+b][y+a])
           movez[3]=dist(n,x+b,y+a);
    }
    if((x+a)<n && (y-b)>=0){
        if(!visited[x+a][y-b])
            movez[1]=dist(n,x+a,y-b);
    }
    if((x+b)<n && (y-a)>=0){
        if(!visited[x+b][y-a])
            movez[4]=dist(n,x+b,y-a);
    }
    if((x-a)>=0 && (y+b)<n){
        if(!visited[x-a][y+b])
            movez[2]=dist(n,x-a,y+b);
    }
    if((x-b)>=0 && (y+a)<n){
        if(!visited[x-b][y+a])
            movez[5]=dist(n,x-b,y+a);
    }
    if((x-a)>=0 && (y-b)>=0){
        if(!visited[x-a][y-b])
            movez[6]=dist(n,x-a,y-b);
    }
    if((x-b)>=0 && (y-a)>=0){
        if(!visited[x-b][y-a])
            movez[7]=dist(n,x-b,y-a);
    }
    
    int min=INT_MAX, index;
    for(int i=0;i<8;++i){
        if(movez[i]<min){
            min = movez[i];
            index = i;
        }
    }
    if(min==INT_MAX)
        return min;
    if(index==0)
        return ezaf(n, x+a, y+b, a, b, moves+1, visited);
    else if(index==1)
        return ezaf(n, x+a, y-b, a, b, moves+1, visited);
    else if(index==2)
        return ezaf(n, x-a, y+b, a, b, moves+1, visited);
    else if(index==3)
        return ezaf(n, x+b, y+a, a, b, moves+1, visited);
    else if(index==4)
        return ezaf(n, x+b, y-a, a, b, moves+1, visited);
    else if(index==5)
        return ezaf(n, x-b, y+a, a, b, moves+1, visited);
    else if(index==6)
        return ezaf(n, x-a, y-b, a, b, moves+1, visited);
    else if(index==7)
        return ezaf(n, x-b, y-a, a, b, moves+1, visited);
    }
    return INT_MAX;
}*/

int minmoves(int n, int a, int b){ //BFS > Recursion for this
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    visited[0][0] = true;
    
    vector<array<int,2>> dir;
    dir.push_back({a,b});
    dir.push_back({b,a});
    dir.push_back({a,-b});
    dir.push_back({b,-a});
    dir.push_back({-a,b});
    dir.push_back({-b,a});
    dir.push_back({ -a,-b});
    dir.push_back({-b,-a});
    
    queue<array<int,3>> qq;
    qq.push({0,0,0});
    
    while(!qq.empty()){
        int x = qq.front()[0];
        int y = qq.front()[1];
        int moves = qq.front()[2];
        qq.pop();
        
        if(x==n-1 && y==n-1){
            return moves;
        }
        
        for(int i=0;i<8;++i){
            int xx = x+dir[i][0];
            int yy = y+dir[i][1];
            
            if((xx >= 0) && (xx < n) && (yy >= 0) && (yy < n) && !visited[xx][yy]){
                visited[xx][yy] = true;
                qq.push({xx,yy,moves+1});
            }
        }
    }
    
    if(!visited[n-1][n-1])
        return -1;
    
    return 0;    
    //return ezaf(n, 0, 0, a, b, 0, visited);
}

int main(){
    int n;
    cin >> n;
    // your code goes here
    vector<vector<vector<int>>> k;
    k.resize(n-1);
    for(int i=0;i<n-1;++i){
        k[i].resize(n-1);
        for(int j=0;j<n-1;++j){
            k[i][j] = {i+1,j+1};
        }
    }
    /*for(int i=0;i<k.size();++i){
        for(int j=0;j<k[i].size();++j){
            cout << '(' << k[i][j][0] << ',' << k[i][j][1] << ") ";
        }
        cout << endl;
    }
    cout << endl;*/
    int tmp;
    vector<vector<int>> ans(n-1,vector<int>(n-1,-1));
    
    for(int i=0;i<k.size();++i){
        for(int j=0;j<k[i].size();++j){
            if(i==0 && j==0){
                tmp = n-1;
            }
            else if(i+1==n-1 && j+1==n-1){
                tmp = 1;
            }
            else if(i+1>n/2 && j+1>n/2)
                tmp = -1;
            else{
                tmp = minmoves(n, k[i][j][0], k[i][j][1]);
                if(tmp==INT_MAX)
                    tmp = -1;
            }
            ans[i][j]=tmp;
        }
    }
    
    /*for(int i=0;i<ans.size();++i){
        for(int j=i;j<ans[i].size();++j){
            if(ans[i][j] != ans[j][i]){
                tmp = min(ans[i][j], ans[j][i]);
                ans[i][j] = tmp;
                ans[j][i] = tmp;
            }
        }
    }*/
    
    for(int i=0;i<ans.size();++i){
        for(int j=0;j<ans[i].size();++j)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
