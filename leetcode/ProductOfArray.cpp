class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int l=nums.size();
        vector<int> left,right;
        
        left.push_back(nums[0]);
        right.push_back(nums[l-1]);
        
        for(int i=1;i<l;i++){
            left.push_back(left[i-1]*nums[i]);
        }
        
        for(int i=1;i<l;i++){
            right.push_back(right[i-1]*nums[l-i-1]);
        }
        
        reverse(right.begin(),right.end());
        
        for(int i=0;i<l;i++){
            if(i==0)
                res.push_back(right[i+1]);
            else if(i==l-1){
                res.push_back(left[i-1]);
            }
            else{
                res.push_back(left[i-1]*right[i+1]);
            }
        }
        return res;
    }
};
