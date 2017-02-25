
/*
https://www.hackerrank.com/contests/w29/challenges/a-circle-and-a-square

Working: 4/10
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double dist(double x1, double y1, double x2, double y2){
    double xdist = x1-x2;
    double ydist = y1-y2;
    return sqrt(pow(xdist, 2)+pow(ydist, 2));
}

double triArea(double x1, double y1, double x2, double y2, double x3, double y3){
    double a = dist(x1,y1,x2,y2);
    double b = dist(x2,y2,x3,y3);
    double c = dist(x3,y3,x1,y1);
    double s = (a+b+c)/2;
    return sqrt(abs(s*(s-a)*(s-b)*(s-c)));
}
bool inSquare(double x, double y, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
    double a1 = triArea(x1,y1,x,y,x4,y4);
    double a2 = triArea(x4,y4,x,y,x3,y3);
    double a3 = triArea(x3,y3,x,y,x2,y2);
    double a4 = triArea(x,y,x2,y2,x1,y1);   
    
    double sum = a1+a2+a3+a4;
    
    double sums = dist(x1,y1,x2,y2)*dist(x2,y2,x3,y3);
    
    if(abs(sum-sums)<0.001){
        return true;
    }
    else if(sum>sums){
        return false;
    }
    
    return true;
}

void fillCircle(vector<vector<char>> &canvas, double xc, double yc, double r, double w, double h){
    if(r==0){
        if(xc>=0 && yc>=0 && xc<w && yc<h)
            canvas[xc][yc] = '#';
        return;
    }
    for(int i=xc-r-1; i<=xc+r+1; ++i){
        for(int j=yc-r-1; j<=yc+r+1; ++j){
            if(i>=0 && j>=0 && i<w && j<h){
                double d = dist(i,j,xc,yc);
                if(abs(d-r)<0.001)
                    canvas[j][i] = '#';
                else if(d<r){
                    canvas[j][i] = '#';
                }
            }
        }
    }
}
void fillSquare(vector<vector<char>> &canvas, double x1, double y1, double x3, double y3, double w, double h){
    if(x1==x3 && y1==y3){
        if(x1>=0 && y1>=0 && x1<w && y1<h)
            canvas[x1][y1] = '#';
        return;
    }
    double x2, y2, x4, y4;
    double xcenter = (x1+x3)/2;
    double ycenter = (y1+y3)/2;
    double xdist = abs(x1-xcenter);
    double ydist = abs(y1-ycenter);
    
    x2 = xcenter-ydist;
    x4 = xcenter+ydist;
    y2 = ycenter-xdist;
    y4 = ycenter+xdist;
    if(x1>=0 && y1>=0 && x1<w && y1<h)
        canvas[y1][x1] = '#';
    if(x2>=0 && y2>=0 && x2<w && y2<h)
        canvas[y2][x2] = '#';
    if(x3>=0 && y3>=0 && x3<w && y3<h)
        canvas[y3][x3] = '#';
    if(x4>=0 && y4>=0 && x4<w && y4<h)
        canvas[y4][x4] = '#';
    //cout << x1 << " " << x2 << " " << x3 << " " << x4 << " " << y1 << " " << y2 << " " << y3 << " " << y4;
    
    for(int i=min(x1,min(x2,min(x3,x4)))-1; i<=max(x1,max(x2,max(x3,x4)))+1; ++i){
        for(int j=min(y1,min(y2,min(y3,y4)))-1; j<=max(y1,max(y2,max(y3,y4)))+1; ++j){
            if(i>=0 && j>=0 && i<w && j<h){
                if(inSquare(i,j,x1,y1,x2,y2,x3,y3,x4,y4))
                    canvas[j][i] = '#';
            }
        }
    }
}
    

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int w, h, xc, yc, r, x1, y1, x3, y3;
    
    cin >> w >> h;
    cin >> xc >> yc >> r;
    cin >> x1 >> y1 >> x3 >> y3;
    
    vector<vector<char>> canvas(h,vector<char>(w,'.'));
    
    fillCircle(canvas, xc, yc, r, w, h);
    fillSquare(canvas, x1, y1, x3, y3, w, h);
    
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            cout << canvas[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
