
/*
https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights

Working: Yes
*/

import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {      
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        int m=in.nextInt();
      
        long w[][]=new long [n+1][n+1];
        
        for(long[] row: w)
            Arrays.fill(row, 100000000l);
        for(int i=0;i<m;i++){
        	w[in.nextInt()][in.nextInt()]=in.nextLong();
        }
        for(int k=1;k<=n;k++){
        	for(int i=1;i<=n;i++){
        		for(int j=1;j<=n;j++)
        			w[i][j]=Math.min(w[i][j],w[i][k]+w[k][j]);
        	}
        }
        
        int q=in.nextInt();
        for(int i=1;i<=q;i++){
        	int x=in.nextInt(),y=in.nextInt();
        	if(x==y && w[x][y]==100000000l){
        		System.out.println("0");
        	}
        	else if(w[x][y]==100000000l){
        		System.out.println("-1");
        	}
        	else{
                System.out.println(w[x][y]);
            }
        }
      
  }
}
