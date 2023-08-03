
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(auto x:graph[i]){
                adj[i].push_back(x);
            }
        }
        // For loop used to cover all components of the graph.
        vector<int>colored(n,-1);
        for(int i=0;i<n;i++){
            if(colored[i]==-1){
                //Checking bipartite using BFS traversal

                queue<pair<int,int>>q; // represents {node,color}

                q.push({i,0}); // node 0 colored with color 0
                colored[0]=0;

                while(!q.empty()){
                    int node=q.front().first;
                    int color=q.front().second;
                    q.pop();
                    for(auto x:adj[node]){
                    // neighbour not colored
                        if(colored[x]==-1){
                            colored[x]=!color;
                            q.push({x,colored[x]});
                        }
                    //neighbour colored with same color that of the current node -> not bipartite
                        else if(colored[x]==color)return false;
                    }
                }
            }
        }
       
        return true;
    }
};