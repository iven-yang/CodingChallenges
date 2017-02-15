
/*
https://www.hackerrank.com/challenges/kruskalmstrsub

Working: Yes
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;


public class Solution {
	int V, E;
	Edge[] edge;
	public Solution(int v,int e){
		V=v;
		E=e;
		edge=new Edge[e];
		for(int i=0;i<e;i++)
			edge[i]=new Edge();
	}
	public void insert(int i,int s,int d,int l){
		edge[i].source=s;
		edge[i].destination=d;
		edge[i].length=l;
	}
	
public static void main(String[] args){
	Scanner sc=new Scanner(System.in);
	int num_vertices=sc.nextInt();
	int num_edges=sc.nextInt();
	Solution g1=new Solution(num_vertices,num_edges);
	for(int i=0;i<num_edges;i++){
		int a=sc.nextInt();
		int b=sc.nextInt();
		int l=sc.nextInt();
		g1.insert(i,a, b, l);
	}
	Arrays.sort(g1.edge,new Comparator<Edge>(){
		public int compare(Edge a,Edge b){
			if(a.length!=b.length){
			return a.length-b.length;
			}
			else return a.source+a.destination-(b.source+b.destination);
		}
	});
	int j=0;
	Solution g2=new Solution(num_vertices,num_vertices-1);
	int[] parent=new int[g2.V+1];
	Arrays.fill(parent, -1);
	for(int i=0;i<g2.E;i++){
		while(g2.findCycle(parent,g1.edge[j])){
			j++;
		}
		
		g2.edge[i]=g1.edge[j];
		j++;
	}
	int ans=0;
	for(Edge e:g2.edge){
		ans=ans+e.length;
	}
	System.out.println(ans);
}
public boolean findCycle(int[] parent,Edge e){
	int a=find(parent,e.source);
	int b=find(parent,e.destination);
	if(a==b){
		return true;
	}
	else{
		union(parent,a,b);
	}
	return false;
}
public int find(int[] parent,int a){
	if(parent[a]==-1){
		return a;
	}
	return find(parent,parent[a]);
}
public void union(int[] parent,int a,int b){
	parent[a]=b;
}

}
class Edge {
    int source;
    int destination;
    int length;
}
