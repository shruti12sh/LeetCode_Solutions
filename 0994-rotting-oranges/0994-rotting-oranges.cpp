class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int vis[m][n];
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                
                if(grid[i][j]==1)cnt++;
                
            }
            
        }
        int tm=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int cntf= 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(t,tm);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r+ drow[i];
                int ncol = c+ dcol[i];
                if(nrow>=0 && nrow<m &&ncol>=0 && ncol<n &&grid[nrow][ncol]==1 &&vis[nrow][ncol]!=2){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                    cntf++;
                }
            }
            
        }
        if(cnt!=cntf) return -1;
        return tm;
        
    }
};