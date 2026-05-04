class Solution {
public:
    vector<vector<int>> res;
    int n;
    void solve(int indx,vector<int> &nums,vector<int> &path){
        if(indx>=n){
            res.push_back(path);
            return;
        }

        // add element
        path.push_back(nums[indx]);
        solve(indx+1,nums,path);

        //don't add element
        path.pop_back();
        solve(indx+1,nums,path);

        

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        vector<int> path;
        solve(0,nums,path);
        return res;
        
    }
};
