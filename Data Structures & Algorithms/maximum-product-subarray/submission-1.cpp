class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxpr=nums[0];
        int minpr=nums[0];
        int cur=nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(maxpr,minpr);
            }
            maxpr=max(nums[i],maxpr*nums[i]);
            minpr=min(nums[i],minpr*nums[i]);
            cur=max(cur,maxpr);
        }

        return cur;
        
    }
};
