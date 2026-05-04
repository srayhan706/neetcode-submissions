class Solution {
public:
    vector<vector<int>> res;
    int n;

    void solve(vector<int> &nums,vector<bool> &pick,vector<int> &perm){
        if(perm.size()==n){
            res.push_back(perm);
            return;
        }

        for(int i=0;i<n;i++){
            if(!pick[i]){
                perm.push_back(nums[i]);
                pick[i]=true;
                solve(nums,pick,perm);
                perm.pop_back();
                pick[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<bool> pick(n,false);
        vector<int> perm;
        solve(nums,pick,perm);

        return res;
        
    }
};
