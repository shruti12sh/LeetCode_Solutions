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
    
    TreeNode* create(TreeNode* root,int target, map<TreeNode*,TreeNode*>&mp){
       queue<TreeNode*>q;
        q.push(root);
        mp[root] = NULL;
                    TreeNode* res = NULL;

        
        while(!q.empty()){
            TreeNode * front = q.front();
            q.pop();
            if(front->val == target){
                res = front;
            }
            if(front->left){
                mp[front->left] = front;
                q.push(front->left);
            }
             if(front->right){
                mp[front->right] = front;
                 q.push(front->right);
            }
        }
        return res;
    }
    int infect(TreeNode* tNode, map<TreeNode*,TreeNode*>&mp){
        map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(tNode);
        visited[tNode] = true;
        int ans = 0;
        while(!q.empty()){
            bool flag =0;
            int size = q.size();
            for(int i=0;i<size;i++){
            TreeNode* front = q.front();
            q.pop();
            if(front->left && !visited[front->left]){
                q.push(front->left);
                flag =1;
                visited[front->left]=true;
            }
              if(front->right && !visited[front->right]){
                q.push(front->right);
                  flag=1;
                visited[front->right]=true;
            }
            if(mp[front] && !visited[mp[front]]){
                flag=1;
                q.push(mp[front]);
                visited[mp[front]]=true;
            }}
        
        if(flag ==1){
            ans++;
        }
    }
        return ans;
    }
    

    int amountOfTime(TreeNode* root, int start) {
        
                map<TreeNode*,TreeNode*>mp;
        TreeNode* tNode = create(root,start,mp);
       int ans = infect(tNode, mp);
        
        
        
        return ans;

        
        
        
    }
};