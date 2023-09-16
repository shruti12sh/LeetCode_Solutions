class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int dp[n][n];
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int s= matrix[i][j]+ dp[i-1][j];
                int left= matrix[i][j];
            if(j-1>=0) left += dp[i-1][j-1];
            else left += 1e9;
            int right= matrix[i][j];
            if(j+1<n) right += dp[i-1][j+1];
            else right += 1e9;
                        dp[i][j]= min(s,min(left,right));

            }
        }
        int mini =  dp[n-1][n-1];
        for(int j=0;j<n;j++){
            mini = min(mini,dp[n-1][j]);
        }
        return mini;
    }
};