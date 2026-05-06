class Solution {
public:
    unordered_set<int> s;
    int newnum(int n){
        int ans=0;
        while(n){
            int dig=n%10;
            ans+=dig*dig;
            n/=10;
        }

        return ans;
    }
    bool isHappy(int n) {

        
        while(!s.count(n)){
            s.insert(n);
            n=newnum(n);
            if(n==1){
                return true;
            }
        }

        return false;
        
    }
};
