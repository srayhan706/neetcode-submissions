class Solution {
public:
    
    int maxCoins(vector<int>& nums) {
        int n=nums.size();

        vector<int> newnums(n+2,1);

        for(int i=0;i<n;i++){
            newnums[i+1]=nums[i];
        }

        vector<vector<int>> dp(n+2,vector<int> (n+2,0));

        for(int l=n;l>=1;l--){
            for(int r=l;r<=n;r++){
                for(int i=l;i<=r;i++){
                    int coins=newnums[l-1]*newnums[i]*newnums[r+1];
                    coins+=dp[l][i-1]+dp[i+1][r];
                    dp[l][r]=max(dp[l][r],coins);
                }
            }
        }
        return dp[1][n];
        
    }


};
