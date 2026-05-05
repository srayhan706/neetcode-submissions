class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res=0;
        vector<int> arr(32,0);

        for(int i=31;i>=0 && n ;i--){
            if(n%2==1){
                arr[i]=1;
            }
            else{
                arr[1];
            }
            res=res+arr[i]*pow(2,i);
            n/=2;
        }

       return res;
        
    }
};
