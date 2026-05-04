class Solution {
public:
    int n;
    vector<vector<int>> res;
    void solve(int indx,vector<int> &path,vector<int> &nums,int rem){

        if(rem==0){
            res.push_back(path);
            return;
        }

        if(rem<0 || indx>=n){
            return;
        }

        

        path.push_back(nums[indx]);
        solve(indx,path,nums,rem-nums[indx]);
        path.pop_back();
        solve(indx+1,path,nums,rem);

        
        

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n=nums.size();
        vector<int> path;
        solve(0,path,nums,target);
        return res;

        
        
    }
};
