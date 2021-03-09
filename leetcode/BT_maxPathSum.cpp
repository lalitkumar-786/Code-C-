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
private:
    int maxPath(TreeNode* root,int &res){
        if(root==NULL)
            return 0;
        int l=maxPath(root->left,res);
        int r=maxPath(root->right,res);
        int temp=max(max(l,r)+root->val,root->val);
        int ans=max(temp,l+r+root->val);
        res=max(res,ans);
        return temp;    
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        maxPath(root,res);
        return res;
    }
};
