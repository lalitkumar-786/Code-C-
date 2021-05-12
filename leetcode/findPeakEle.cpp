class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start=0;
        int l=nums.size();
        int end =l-1;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            
            int right=(mid+1>end)?INT_MIN:nums[mid+1];
            int left=(mid-1<start)?INT_MIN:nums[mid-1];
            
            if(nums[mid]<right)
                start=mid+1;
            else if(nums[mid]<left)
                end=mid-1;
            else
                return mid;
        }
        return start;
        
    }
};
