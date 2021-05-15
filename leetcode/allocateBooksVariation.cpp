class Solution {
public:
    bool isValid(vector<int>& weights, int days, int maxW){
        int day=1;
        int totalW=0;
        for(auto item:weights){
            totalW+=item;
            if(totalW>maxW){
                day++;
                totalW=item;
            }
            if(day>days)
                return false;
        }
        return true;
    }
        
    int shipWithinDays(vector<int>& weights, int days) {
        int l=weights.size();
        
        //total sum
        long sum=0;
        int maxW=INT_MIN;
        for(auto item:weights){
            sum+=item;
            maxW=(maxW>item)?maxW:item;
        }
            
        int start=maxW;
        int end=sum;
        int res=0;
        while(start<=end) {
            int mid=start+(end-start)/2;
            if(isValid(weights,days,mid)){
                end=mid-1;
                res=mid;
            }
            else
                start=mid+1;
        }
        return res;
    }
};
