class Solution {
public:
    vector<string> res;
    vector<string> chars={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;
        dfs(0,"",digits);
        return res;
    }
    void dfs(int i,string curr,string& digits){
        if(curr.size()==digits.size()){
            res.push_back(curr);
            return;
        }
        string ch=chars[digits[i]-'0'];
        for(char c:ch){
            dfs(i+1,curr+c,digits);
        }
    }
};
