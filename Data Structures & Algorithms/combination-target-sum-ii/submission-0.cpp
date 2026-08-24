class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        sort(candidates.begin(),candidates.end());
        dfs(0,{},0,candidates,target);
        return res;
    }
    void dfs(int idx,vector<int> curr,int total,vector<int>& candidates,int target){
        if(total==target){
            res.push_back(curr);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(total+candidates[i]>target) break;
            curr.push_back(candidates[i]);
            dfs(i+1,curr,total+candidates[i],candidates,target);
            curr.pop_back();
        }
    }
};
