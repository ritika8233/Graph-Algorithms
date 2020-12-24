#include<bits/stdc++.h>
using namespace std;

void printsolution(vector < vector< int > > &adj,vector<int> &parent){
	cout<<"Solution is: "<<endl;
	for(int i=1;i<adj.size();i++){
		cout<<"Edge: "<<parent[i]<<" - "<<i<<" cost: "<<adj[i][parent[i]]<<endl;
	}
}

int minkey(vector<bool> &vis,vector<int> &dis){
	int min_ele=INT_MAX,index=0;
	for(int i=0;i<vis.size();i++){
		if((vis[i]==false)&&(min_ele > dis[i])){
			min_ele=dis[i];
			index=i;
		}
	}
	return index;
}

void prims(vector < vector< int > > &adj){
	int n=adj.size();
	vector<bool> vis;
	vector<int> parent;
	vector<int> dis;
	for(int i=0;i<n;i++){
	   vis.push_back(false);
	   parent.push_back(-1);
	   dis.push_back(INT_MAX);
	}
	parent[0]=-1;
	dis[0]=0;
	for(int i=0;i<n-1;i++){
		int u=minkey(vis,dis);
		vis[u]=true;
		for(int j=0;j<n;j++){
			if(adj[u][j]!=0 && vis[j]==false && adj[u][j]<dis[j]){
				dis[j]=adj[u][j];
				parent[j]=u;
			}
		}
	}
	printsolution(adj,parent);
}

int main(){
	int v;
	cout<<"Enter No of vertices: ";
	cin>>v;
	vector < vector< int > > adj(v,vector<int>(v,0));
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			int cost;
			cin>>cost;
			adj[i][j]=cost;
		}
	}
	prims(adj);
	return 0;
}
