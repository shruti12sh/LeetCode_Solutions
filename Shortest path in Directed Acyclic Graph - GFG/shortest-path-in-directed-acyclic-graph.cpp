//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
    void toposort(int node,int vis[],stack<int>&st,     vector<pair<int,int>>adj[]){
        vis[node]=1;
        for(auto it: adj[node]){
            int u = it.first;
            if(!vis[u]){
                toposort(u,vis,st,adj);
            }
        }
        st.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[N];
        for(int i=0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w});
        }
        int vis[N]= {0};
        stack<int>st;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                toposort(i,vis,st,adj);
            }
        }
        
        vector<int>distance(N);
        for(int i=0;i<N;i++) distance[i]=1e9;
        distance[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto it:adj[node]){
                int v = it.first;
                int wt = it.second;
                if(distance[node]+wt < distance[v]){
                    distance[v] = distance[node]+wt;
                }
              
            }
        }
         for (int i = 0; i < N; i++) {
        if (distance[i] == 1e9) distance[i] = -1;
      }
        return distance;
        
        
        
        }
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends