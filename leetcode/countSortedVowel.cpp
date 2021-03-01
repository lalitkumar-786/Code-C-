class Solution {
public:
    int countVowelStrings(int n) {
           int dp[n+1][6];
            memset(dp,0,sizeof(dp));
            
            for(int i=1;i<=5;i++)
                dp[1][i]=1;
            
            long long int sum=0;
            for(int i=2;i<=n;i++){
                for(int j=1;j<=5;j++){
                    dp[i][j]=dp[i][j-1]+dp[i-1][j];
                }                  
            }
            
            for(int i=1;i<=5;i++)
                sum+=dp[n][i];
            return sum;
    }
};
