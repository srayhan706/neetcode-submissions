class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> cs;
        int left=0;
        int ans=0;

        for(int right=0;right<s.size();right++){

            while(cs.find(s[right])!=cs.end()){
                cs.erase(s[left]);
                
                left++;

            }
            cs.insert(s[right]);
            ans=max(ans,right-left+1);

        }

        return ans;
        
    }
};
