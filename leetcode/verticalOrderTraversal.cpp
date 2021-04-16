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
    
    map<int, map<int,vector<int>>> mymap;

    void dfs(TreeNode* root,int x,int y) {
        if(root==NULL)
            return;
        mymap[x][y].push_back(root->val);
        dfs(root->left,x-1,y+1);
        dfs(root->right,x+1,y+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        //multimap<int,map<int,int>> mymap;
        int x=0,y=0;
        dfs(root,x,y);
        vector<int> v,temp;
        for(auto xCor:mymap){
            for(auto yCor:xCor.second){
                for(auto el:yCor.second){
                    temp.push_back(el);   
                }
                sort(temp.begin(),temp.end());
                v.insert(v.end(),temp.begin(),temp.end());
                temp.clear();
            }
            res.push_back(v);
            v.clear();
        }
        return res;
    }
};
