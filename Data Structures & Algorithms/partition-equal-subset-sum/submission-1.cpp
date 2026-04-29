class Solution {
public:
    vector<vector<int>> memo;

    bool dfs(vector<int> &nums,int i,int target){
        if(i==nums.size()){
            return target==0;
        }
        if(target<0){
            return false;
        }
        if(memo[i][target] != -1){
            return memo[i][target];
        }

        return memo[i][target]=dfs(nums,i+1,target)||dfs(nums,i+1,target-nums[i]);
    }
    bool canPartition(vector<int>& nums) {
        int s=0;
        for(int n: nums){
            s+=n;
        }
        if(s%2==1){
            return false;
        }

        memo.resize(nums.size(),vector<int> (s/2+1,-1));

        return dfs(nums,0,s/2);


        
    }
};
