class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        
        int l=nums.size();
        
        if(l==0)
            return res;
        
        sort(nums.begin(),nums.end());
        
        int left,right;
        long sum1,sum2;
        for(int i=0;i<l;i++){
            for(int j=i+1;j<l;j++){
                left=j+1;
                right=l-1;
                
                sum1=nums[i]+nums[j];
                
                while(left<right) {
                    sum2=nums[left]+nums[right];
                    
                    if(sum1+sum2==target){
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                    }
                    else if(sum1+sum2<target)
                        left++;
                    else
                        right--;
                    
                    while(left-1>j and left<right and nums[left-1]==nums[left]) left++;
                    
                    while(right+1<l and right-1>left and nums[right]==nums[right+1]) right--;
                    
                }
                
                while(j+1<l and nums[j+1]==nums[j]) j++;   
            }
            while(i+1<l and nums[i+1]==nums[i])  i++;
        }
        return res;
    }
};
