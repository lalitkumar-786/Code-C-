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
    void dfs(TreeNode* root,string &s,vector<string> &v){
        if(root==NULL)
            return;
        else{
            s.push_back(root->val+'0');
            dfs(root->left,s,v);
            dfs(root->right,s,v);
        }
        if(root->left==NULL and root->right==NULL)
           v.push_back(s);
           s.pop_back();     
    }
    
    int sumNumbers(TreeNode* root) {
        string s;
        long long int sum=0;
        vector<string> v;
        if(root==NULL)
            return 0;
        else{
            dfs(root,s,v);
            
            for(auto it:v)
                sum+=stoi(it);
        }
        return sum;
    }
};
