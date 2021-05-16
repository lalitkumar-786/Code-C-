class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minEle=prices[0];
        int diff=0;
        
        if(prices.size()==1)
            return 0;
        
        auto it=prices.begin();
        it++;
        
        for(;it!=prices.end();it++){
            if(*it<minEle)
                minEle=*it;
            if(*it-minEle>=diff)
                diff=*it-minEle;
        }
        return diff;
        
    }
};
