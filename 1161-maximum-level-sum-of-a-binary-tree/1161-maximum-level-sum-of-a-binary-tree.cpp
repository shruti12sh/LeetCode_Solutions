/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxsum = INT_MIN;
        int ans = 0;
        int level = 0;
        queue<TreeNode *>qt;
        qt.push(root);
        while(!qt.empty()){
            level++;
            int sumAtlevel = 0;
         for(int sz = qt.size();sz > 0;sz--){
             TreeNode *node = qt.front();
             qt.pop();
             sumAtlevel += node->val;
             if(node->left != NULL)
                 qt.push(node->left);
               if(node->right != NULL)
                 qt.push(node->right);
             
         }
            if(maxsum < sumAtlevel){
                maxsum = sumAtlevel;
                ans = level;
            }
        }
        return ans;
    }
};