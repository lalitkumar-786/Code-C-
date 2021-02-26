class Solution {
public:
    int trap(vector<int>& height) {
        int l=height.size();
        if(l<=2)
            return 0;
        else{
            int *left=new int[l];
            int *right=new int[l];
            left[0]=0;
            
            //fill left array
            for(int i=1;i<l;i++){
                if(height[i-1]>=left[i-1])
                    left[i]=height[i-1];
                else
                    left[i]=left[i-1];
            }
            
            reverse(height.begin(),height.end());
            right[0]=0;
            for(int i=1;i<l;i++){
                if(height[i-1]>=right[i-1])
                    right[i]=height[i-1];
                else
                    right[i]=right[i-1];
            }
            reverse(height.begin(),height.end());
            reverse(right,right+l);
            long long int sum=0;
            for(int i=0;i<l;i++){
                if(min(left[i],right[i])>height[i]){
                    sum+=(min(left[i],right[i])-height[i]);
                }
            }
            return sum;
         }    
    }
};
