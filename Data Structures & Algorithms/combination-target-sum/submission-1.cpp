class Solution {
public:
    int n;
    vector<vector<int>> res;
    void solve(int indx,vector<int> &path,vector<int> &nums,int rem){

        if(rem==0){
            res.push_back(path);
            return;
        }

        if(rem<0){
            return;
        }

        for(int i=indx;i<n;i++){

            path.push_back(nums[i]);
            solve(i,path,nums,rem-nums[i]);
            path.pop_back();

        }
        

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n=nums.size();
        vector<int> path;
        solve(0,path,nums,target);
        return res;

        
        
    }
};
