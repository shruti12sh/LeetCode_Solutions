class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size(), maxi = 0;
        if(n == 2)
            return stones[1] - stones[0];
        for(int i = 0 ; i < n - 2 ; i++)
            maxi = max(maxi,stones[i + 2] - stones[i]);
        return maxi;
    }
};