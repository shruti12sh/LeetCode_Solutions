#define ll long long int
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long ans =0;
         int level = 0;
        queue<TreeNode *>qt;
        vector<ll>sum;
        qt.push(root);
        while(!qt.empty()){
            level++;
            queue<TreeNode*>qt2;
          ll sumAtlevel = 0;
         for(int sz = qt.size();sz > 0;sz--){
             TreeNode *node = qt.front();
             qt.pop();
             sumAtlevel += node->val;
               if(node->left != NULL)
                 qt2.push(node->left);
               if(node->right != NULL)
                 qt2.push(node->right);
          
             
         }
            sum.push_back(sumAtlevel);
            qt = qt2;
        }
            sort(sum.begin(),sum.end(),greater<ll>());
            if(sum.size()<k)
                return -1;
           
        
        return sum[k-1];
        
    }
};