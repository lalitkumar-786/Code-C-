class Solution {
public:
    int getPivot(vector<int>& nums, int start,int end,int l){
        
        int mid=start+(end-start)/2;
        if(nums[mid]<nums[(mid+1)%l] and nums[mid]<nums[(mid-1+l)%l])
            return mid;
        else if(nums[mid]<=nums[end] and nums[mid]<nums[start])
            return getPivot(nums,start,mid-1,l);
        else if(nums[start]<=nums[mid] and nums[mid]>nums[end])
            return getPivot(nums,mid+1,end,l);
        return start;
    }
    
    int binarySearch(vector<int>& nums, int start,int end, int target){
        
            if(start>end)
                return -1;
        
            int mid=start+(end-start)/2;
            
            if(nums[mid]>target)
                return binarySearch(nums,start,mid-1,target);
            else if(nums[mid]<target)
                return binarySearch(nums,mid+1,end,target);
            else if(nums[mid]==target)
                return mid;
        
            return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int l=nums.size();
        int start=0;
        int end=l-1;
        
        if(l==1)
            return (nums[0]==target)?0:-1;
            
        int pivot=getPivot(nums,start,end,l);
        
        return max(binarySearch(nums,start,pivot-1,target), binarySearch(nums,pivot,end,target));
        
        
    }
};
