class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p==NULL && q==NULL) 
            return true;
        if((p==NULL && q!=NULL)||(p!=NULL && q==NULL))
            return false;
            
            
        bool left=true;  
        bool right=true; 

            if(p->val!=q->val)    //if both node have different values
                return false;
            else if(p->left==NULL && q->left!=NULL)  
                return false;
            else if(p->left!=NULL && q->left==NULL)   // p Node have left chiled and q node don't have left chiled Node
                return false;  
            else if(p->right==NULL && q->right!=NULL) // p Node don't have right chiled and q node have right chiled Node
                return false; 
            else if(p->right!=NULL && q->right==NULL) // p Node have right chiled and q node don't have 
                return false;           
            
         
            if(p->left!=NULL && q->left!=NULL)
                left=isSameTree(p->left,q->left); //check Recursively left subtree is same or note
            if(p->right!=NULL && q->right!=NULL)  //check Recursively right subtree is same or note
                right=isSameTree(p->right,q->right);
        
            if(left && right) // if both right side and left side are valid than tree are same
                return true;
            else
                return false;          
    }
};