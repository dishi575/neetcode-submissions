class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;
        dfs(0,0,n,res,curr);
        return res;
    }
    void dfs(int open,int closed,int n,vector<string>& res,string& curr){
        if(open==closed && open==n){
            res.push_back(curr);
            return;
        }
        if(open<n){
            curr+='(';
            dfs(open+1,closed,n,res,curr);
            curr.pop_back();
        }
        if(closed<open){
            curr+=')';
            dfs(open,closed+1,n,res,curr);
            curr.pop_back();
        }
    }
};
