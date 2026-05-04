class Solution {
public:
    vector<string> res;
    void solve(int open,int close,string &path,int n){

        if(path.size()==2*n){
            res.push_back(path);
            return;
        }

        if(open<n){
            path+='(';
            solve(open+1,close,path,n);
            path.pop_back();
        }

        if(close<open){
            path+=')';
            solve(open,close+1,path,n);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string path="";
        solve(0,0,path,n);
        return res;
        
    }
};
