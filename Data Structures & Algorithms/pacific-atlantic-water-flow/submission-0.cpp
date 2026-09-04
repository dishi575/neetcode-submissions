class Solution {
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows=heights.size();
        int cols=heights[0].size();
        vector<vector<bool>> pac(rows,vector<bool>(cols,false));
        vector<vector<bool>> atl(rows,vector<bool>(cols,false));
        queue<pair<int,int>> pacific,atlantic;
        for(int r=0;r<rows;r++){
            pacific.push({r,0});
            atlantic.push({r,cols-1});
        }
        for(int c=0;c<cols;c++){
            pacific.push({0,c});
            atlantic.push({rows-1,c});
        }
        bfs(pacific,pac,heights);
        bfs(atlantic,atl,heights);
        vector<vector<int>> res;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(pac[r][c] && atl[r][c]){
                    res.push_back({r,c});
                }
            }
        }
        return res;
    }
    void bfs(queue<pair<int,int>>& q,vector<vector<bool>>& grid,vector<vector<int>>& heights){
        while(!q.empty()){
            auto [r,c]=q.front();q.pop();
            grid[r][c]=true;
            for(auto [dr,dc]:dir){
                int nr=r+dr,nc=c+dc;
                if(nr>=0 && nc>=0 && nr<heights.size() && nc<heights[0].size() && !grid[nr][nc] && heights[nr][nc]>=heights[r][c]){
                    q.push({nr,nc});
                }
            }
        }
    }
};
