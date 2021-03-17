class Solution {
public:
    unsigned modulo(int a,int b){
        int m=a%b;
        if(m<0){
            m+=b;
        }
        return m;
    }
    
    int findMin(vector<int>& nums) {
        int l=nums.size();
        int startIndex=0;
        int endIndex=l-1;
        
        while(startIndex<endIndex){
            int midIndex=(startIndex+(endIndex-startIndex)/2);
           // if(midIndex>0 and nums[midIndex]<=nums[midIndex-1])
             //   return nums[midIndex];
          
          //Below one is taking care of outOfBound using modulo function as -ve numbers have -ve modulo.. Hence its time complexisy is more than above commented one
         if(nums[midIndex]<=nums[modulo(midIndex-1,l)])
                return nums[midIndex];
          
            if(nums[startIndex]<=nums[midIndex] and nums[endIndex]<nums[midIndex])
                startIndex=midIndex+1;
            else
                endIndex=midIndex-1;
        }
        
        return nums[startIndex];
    }
};

//[4,5,6,7,0,1,2]
