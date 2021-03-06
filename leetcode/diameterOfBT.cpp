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
    int dob(TreeNode* root,int &res){
        if(root==NULL)
            return 0;
        int lDiameter=dob(root->left,res);
        int rDiameter=dob(root->right,res);
        
        //if we want to pass as current node is not the longest one
        
        int temp=max(lDiameter,rDiameter)+1;
        int ans=max(temp,lDiameter+rDiameter+1);
        res=max(res,ans);
        return temp;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL || (root->left==NULL and root->right==NULL))
            return 0;
        int res=1;
        dob(root,res);
        return res-1;
    }
};
