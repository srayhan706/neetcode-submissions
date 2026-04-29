class Solution {
public:
    int cal(int st,int en,vector<int>& nums){
        vector<int> dp(en+1,0);
        dp[st]=nums[st];
        dp[st+1]=max(nums[st],nums[st+1]);

        for(int i=st+2;i<=en;i++){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }

        return dp[en];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1){
            return nums[0];
        }

        return max(cal(0,n-2,nums),cal(1,n-1,nums));
        
    }
};
