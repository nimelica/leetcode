class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        
        while(root){
            if(p->val > root->val and q->val > root->val){
                root = root->right;
            }
            else if(p->val < root->val and q->val < root->val){
                root = root->left;
            }
            else{
                break;
            }
        }
        //else one is left other is right
        return root;
    }
};
