class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long sum=0;
        int i=0,j=0;
        int l=nums.size();
        int ans=INT_MAX;
        
        while(j<l){
            
            sum+=nums[j];
            
            if(sum<target)
                j++;
            else if(sum>=target){

                while(sum>=target){
                    ans=min(ans,j-i+1);
                    sum-=nums[i];
                    i++;
                }
                j++;
            }            
        }
        return ans==INT_MAX?0:ans;
    }
};
