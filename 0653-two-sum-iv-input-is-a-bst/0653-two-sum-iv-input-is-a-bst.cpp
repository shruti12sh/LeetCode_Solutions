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
class BSTiterator{
   private : 
    stack<TreeNode*> st;
    bool reverse = true;
    public:
     BSTiterator(TreeNode* root,bool isreverse){
         reverse = isreverse;
         pushall(root);
     }
    
    int next(){
        TreeNode* tmp = st.top();
        st.pop();
        if(!reverse) pushall(tmp->right);
        else pushall(tmp->left);
        return tmp->val;
        
    }
    bool hasnext(){
        return !st.empty();
    }
    private:
    void pushall(TreeNode* root){
        while(root!=NULL){
            st.push(root);
            if(reverse==true)
                root= root->right;
            else root = root->left;
        }
    }
        
        
        
};
class Solution {
   
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        BSTiterator l(root,false);
        BSTiterator r(root,true);
        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j>k) j = r.next();
            else i= l.next();
        }
        return false;
    }
}; 