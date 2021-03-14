class Solution {
public:
  // TLE solution as its time complexity is exponential)
    int minCoinChange(vector<int>& coins, int amount,int n){
        
        if(amount==0 and n!=0)
            return 0;
        if(n==0 || amount==0)
            return INT_MAX-1;
        else{

            if(coins[n-1]<=amount)
                return min(1+minCoinChange(coins,amount-coins[n-1],n),minCoinChange(coins,amount,n-1));
            else
                return minCoinChange(coins,amount,n-1);
        }
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(minCoinChange(coins,amount,n)==INT_MAX-1)
            return -1;
        else
            return minCoinChange(coins,amount,n);
    }
};
