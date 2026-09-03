class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int fresh=0,time=0;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c]==1){
                    fresh++;
                }
            }
        }
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(fresh>0){
            bool flag=false;
            for(int r=0;r<rows;r++){
                for(int c=0;c<cols;c++){
                    if(grid[r][c]==2){
                        for(auto& d:dir){
                            int row=r+d[0];
                            int col=c+d[1];
                            if(row>=0 && col>=0 && row<rows && col<cols && grid[row][col]==1){
                                grid[row][col]=3;
                                flag=true;
                                fresh--;
                            }
                        }
                    }
                }
            }
            if(!flag) return -1;
            for(int r=0;r<rows;r++){
                for(int c=0;c<cols;c++){
                    if(grid[r][c]==3){
                        grid[r][c]=2;
                    }
                }
            }
            time++;
        }
        return time;
    }
};
