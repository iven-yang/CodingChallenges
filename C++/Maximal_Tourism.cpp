
/*
https://www.hackerrank.com/contests/rookierank-3/challenges/maximal-tourism

Working: Yes
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

struct Node{
    Node(bool v, int i){
        visited = v;
        index = i;
    }
    
    int index;
    bool visited;
    Node* next;
    Node* prev;
    vector<Node*> routes;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,m;
    cin >> n >> m;
    
    vector<Node*> nodes(n);

    for(int i=0;i<n;++i){
        Node* tmp = new Node(false, i+1);
        nodes[i] = tmp;
        if(i>0){
            nodes[i-1]->next = nodes[i];
            nodes[i]->prev = nodes[i-1];
        }
    }
    nodes[n-1]->next = nullptr;
    
    for(int i=0;i<m;++i){
        int a,b;
        cin >> a >> b;
        --a;
        --b;
        if(a!=b){
            nodes[a]->routes.push_back(nodes[b]);
            nodes[b]->routes.push_back(nodes[a]);
        }
    }
    
    Node* headv = new Node(false, 0);
    headv->next = nodes[0];
    nodes[0]->prev = headv;
    
    int maxcount=0,numv=0;
    
    while(numv<n){
        queue<Node*> qq;
        /*for(int i=0;i<n;++i){
            if(nodes[i]->visited==false){
                qq.push(nodes[i]);
                //cout << "head:" << i << endl;
                break;
            }
        }*/
        qq.push(headv->next);
        
        int moves=0;
        while(!qq.empty()){
            Node* cur = qq.front();
            qq.pop();
            //cout << cur->index << endl;
            
            if(cur->visited==false){
                ++moves;
                ++numv;
                
                cur->visited = true;
                Node* pre = cur->prev;
                Node* nxt = cur->next;
                
                pre->next = cur->next;
                if(nxt!=nullptr)
                    nxt->prev = cur->prev;
                
                for(int j=0;j < (cur->routes.size());++j){
                    if(cur->routes[j]->visited==false){
                        qq.push(cur->routes[j]);
                    }
                }
            }
        }
        if(moves>maxcount)
            maxcount = moves;
    }
    
    cout << maxcount;
    
    return 0;
}
