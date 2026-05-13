class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }

        vector<int>  s1map(26,0);
        vector<int> windowmap(26,0);

        for(char c:s1){
            s1map[c-'a']++;
        }

        int left=0;

        for(int right=0;right<s2.size();right++){

            windowmap[s2[right]-'a']++;

            if((right-left+1)>s1.size()){
                windowmap[s2[left]-'a']--;
                left++;
            }

            if(s1map==windowmap){
                return true;
            }
        }

        return false;

       
    }
};