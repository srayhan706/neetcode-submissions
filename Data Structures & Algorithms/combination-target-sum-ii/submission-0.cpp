class Solution {
public:
    vector<vector<int>> res;

    void solve(int indx, vector<int> &path, vector<int> &nums, int rem) {
        if (rem == 0) {
            res.push_back(path);
            return;
        }

        for (int i = indx; i < nums.size(); i++) {
            // skip duplicates
            if (i > indx && nums[i] == nums[i - 1]) continue;

            if (nums[i] > rem) break;

            path.push_back(nums[i]);
            solve(i + 1, path, nums, rem - nums[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        solve(0, path, candidates, target);
        return res;
    }
};