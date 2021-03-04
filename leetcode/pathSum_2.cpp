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
    void dfs(TreeNode* root, int targetSum,int curSum,vector<int> &v,vector<vector<int>> &res){
        if(root==NULL)
            return;
        curSum+=root->val;
        v.push_back(root->val);
        if(curSum==targetSum and root->left==NULL and root->right==NULL){
            res.push_back(v);
        }
        else{
            dfs(root->left,targetSum,curSum,v,res);
            dfs(root->right,targetSum,curSum,v,res);
        }
        curSum-=root->val;
        v.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        else{
            int curSum=0;
            vector<int> v;
            dfs(root,targetSum,curSum,v,res);
            return res;
        }
    }
};
