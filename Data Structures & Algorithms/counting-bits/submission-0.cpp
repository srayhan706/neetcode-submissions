class Solution {
public:
    int pop_cnt(int x){
        int ans=0;
        while(x){
            if(x&1){
                ans++;
            }
            x=x>>1;
        }

        return ans;
    }

    vector<int> countBits(int n) {

        vector<int> res;
        for(int i=0;i<=n;i++){
            res.push_back(pop_cnt(i));
        }
        return res;
        
    }
};
