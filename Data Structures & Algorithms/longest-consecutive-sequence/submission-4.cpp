class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int num:nums){
            s.insert(num);
        }

        int ans=INT_MIN;
        for(int n:s){

            if (s.count(n-1)==0){
                int len=1;

                while(s.count(n+len)){
                    len+=1;

                }
                ans=max(ans,len);


            }

        }
        if(ans==INT_MIN){
            return 0;
        }
        return ans;


        
    }
};
