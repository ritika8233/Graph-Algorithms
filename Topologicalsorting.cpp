#include<bits/stdc++.h>
using namespace std;
void topo(vector<bool> &vis, vector<vector<int>> &adj,int node,stack<int> &s){
  if(vis[node]){
    return;
  }
  vis[node] = true;
  for(auto it: adj[node]){
    if(!vis[it]){
      topo(vis,adj,it,s);
    }
  }
  s.push(node);
}
int main(){
  int v;
  cout<<"Enter No of Vertices: ";
  cin>>v;
  vector<vector<int>> adj(v);
  while(1){
    int a,b;
    cin>>a>>b;
    if(a==-1 || b==-1)break;
    adj[a].push_back(b);
  }
  vector<bool> vis(v,false);
  stack<int> s;
  for(int i=0 ; i<v ;i++){
  topo(vis,adj,i,s);
}
while(!s.empty()){
  cout<<s.top()<<" ";
  s.pop();
}
  return 0;
}
