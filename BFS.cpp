#include<bits/stdc++.h>
using namespace std;
int main(){
  int v;
  cout<<"Enter no of Vertices: ";
  cin>>v;
  vector<vector<int>> adj(v);
  while(1){
    int a,b;
    cin>>a>>b;
    if(a==-1 || b==-1){
      break;
    }
    adj[a].push_back(b);
  }
  queue<int> q;
  int start;
  cout<<"Enter Starting Point: ";
  cin>>start;
  q.push(start);
  vector<bool> vis(v,false);
  while(!q.empty()){
    int temp=q.front();
    cout<<temp<<" ";
    vis[temp]=true;
    q.pop();
    for(auto it : adj[temp] ){
      if(!vis[it]){
        q.push(it);
      }
    }
  }
  return 0;
}
