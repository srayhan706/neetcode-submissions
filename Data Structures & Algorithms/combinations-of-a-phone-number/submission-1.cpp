class Solution {
public:
    vector<string> res;
    vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

    void solve(int indx,string &digits,string &path){
        if(indx==digits.size()){
            res.push_back(path);
            return;
        }

        string letter=mapping[digits[indx]-'0'];

        for(char c:letter){
            path.push_back(c);
            solve(indx+1,digits,path);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        string path="";
        solve(0,digits,path);
        return res;
        
    }
};
