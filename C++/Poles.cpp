
/*
https://www.hackerrank.com/contests/w30/challenges/poles

Working: 8/11
*/

#include <bits/stdc++.h>

using namespace std;

/*
    Cost from moving pole with weight w from x1 to x2
*/
int charge(int x1, int x2, int w){
    return w*abs(x1-x2);
}

/*
    Cost of moving poles from positions in polesi to positions in polesf
    Weight is contained for each pole i in get<1>(polesi[i])
*/
int totalcost(const vector<pair<int, int>> &polesi, const vector<int> &polesf){
    int totcost = 0;
    for(int i=0; i<polesi.size(); ++i){
        int start = get<0>(polesi[i]);
        int dest = polesf[0];
        
        for(int j=0; j<polesf.size() && start>=polesf[j]; ++j){
            dest = polesf[j];
        }
            
        polesf[i];
        totcost+=charge(start, dest, get<1>(polesi[i]));
    }
    return totcost;
}


/*
    Finds all subsets of length 'k' from 'poles'.
    Inserts these into 'positions'.
*/
void allSubsets(const vector<pair<int, int>> &poles, int k, int start, int len, vector<bool> &used, vector<vector<int>> &positions, int lowestx){
    if(len==k){
        vector<int> tpos;
        for(int i=0; i<poles.size(); ++i){
            if(used[i])
                tpos.push_back(get<0>(poles[i]));
        }
        sort(tpos.begin(), tpos.end());
        
        if(tpos[0]==lowestx){
            positions.push_back(tpos);
        }
        
        //positions.push_back(tpos);
        return;
    }
    if(start==poles.size()){
        return;
    }
    
    used[start] = true;
    allSubsets(poles, k, start + 1, len + 1, used, positions, lowestx);
    
    used[start] = false;
	allSubsets(poles, k, start + 1, len, used, positions, lowestx);
    
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    
    vector<pair<int, int>> poles(n);
    
    int lowestx;
    
    for(int a0 = 0; a0 < n; a0++){
        int x_i;
        int w_i;
        cin >> x_i >> w_i;
        poles[a0] = pair<int,int>(x_i,w_i);
        if(a0 == 0)
            lowestx = x_i;
    }
    
    vector<vector<int>> positions;
    vector<bool> used(n, false);
    
    allSubsets(poles, k, 0, 0, used, positions, lowestx);
    
    /*for(int i=0;i<positions.size();++i){
        for(int j=0;j<k;++j){
            cout << positions[i][j] << " ";
        }
        cout << endl;
    }*/
    
    int mincost = INT_MAX;
    
    for(int i=0;i<positions.size();++i){
        int curcost = totalcost(poles, positions[i]);
        //cout << curcost << endl;
        if(curcost < mincost){
            mincost = curcost;
        }
    }
  
    if(mincost == INT_MAX){
        mincost = 0;
    }
    cout << mincost;
    
    return 0;
}
