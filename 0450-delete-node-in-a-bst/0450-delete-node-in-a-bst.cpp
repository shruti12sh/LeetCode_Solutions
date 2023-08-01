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
      TreeNode* delete1(TreeNode* root){
            if(root->left==NULL)
                return root->right;
             else if(root->right==NULL)
                return root->left;
            TreeNode* rightChild = root->right;
            TreeNode* lastright = findlastright(root->left);
            lastright->right = rightChild;
            return root->left;
        }
    
       TreeNode* findlastright(TreeNode* root){
            if(root->right==NULL) return root;
            
           return findlastright(root->right);
        }
    
     
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
     
            if(root->val == key){
                return delete1(root);
            }
        TreeNode* curr = root;
        while(root!=NULL){
        if(root->val > key ){
             if(root->left != NULL && root->left->val == key){
                 root->left = delete1(root->left);
            break;
        }
            else {
                root = root->left;
            }
        }
        else{
         if(root->right != NULL && root->right->val == key){
                 root->right = delete1(root->right);
            break;
        }
            else {
                root = root->right;
            }
        }
        
    }
           return curr;
    }
      
     
};