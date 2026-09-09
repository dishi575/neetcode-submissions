class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visit(n,false);
        for(auto& edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int comp=0;
        for(int node=0;node<n;node++){
            if(!visit[node]){
                dfs(node,adj,visit);
                comp++;
            }
        }
        return comp;
    }
    void dfs(int node,vector<vector<int>>& adj,vector<bool>& visit){
        visit[node]=true;
        for(auto nei:adj[node]){
            if(!visit[nei]){
                dfs(nei,adj,visit);
            }
        }
    }
};
