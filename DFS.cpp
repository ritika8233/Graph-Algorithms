#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cout<<"Enter No of Vertices: ";
  cin>>n;
  int e;
  cout<<"Enter the No of Edges: ";
  cin>>e;
  vector<vector<int>> adj(n);
  for(int i=0 ; i<e ; i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
  }
  stack<int> st;
  vector<bool> vis(n,false);
  int start;
  cin>>start;
  st.push(start);
  while(!st.empty()){
    int temp = st.top();
    vis[temp] = true;
    cout<<temp<<" ";
    st.pop();
    for(auto it: adj[temp]){
      if(!vis[it]){
        st.push(it);
      }
    }
  }
  return 0;
}
