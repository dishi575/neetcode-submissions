class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        dfs(0,s,res,curr);
        return res;
    }
    void dfs(int i,string s,vector<vector<string>>& res,vector<string>& curr){
        if(i>=s.length()){
            res.push_back(curr);
            return;
        }
        for(int j=i;j<s.length();j++){
            if(pali(s,i,j)){
                curr.push_back(s.substr(i,j-i+1));
                dfs(j+1,s,res,curr);
                curr.pop_back();
            }
        }
    }
    bool pali(string s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
