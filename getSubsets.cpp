class Solution {
public:
    void genSubsets(vector<int> nums, vector<int> output,vector<vector<int>> &res){
            if(nums.size()==0){
                res.push_back(output);
                return;
            }
        
            vector<int> v1;
            vector<int> v2;
            v1=v2=output;
            
            v2.push_back(nums[0]);
            nums.erase(nums.begin()+0);
            
            genSubsets(nums,v1,res);
            genSubsets(nums,v2,res);
            return ;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> output;
        genSubsets(nums,output,res);
        return res;
    }
};
