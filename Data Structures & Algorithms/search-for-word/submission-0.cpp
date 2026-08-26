class Solution {
public:
    int row,col;
    bool exist(vector<vector<char>>& board, string word) {
        row=board.size();
        col=board[0].size();
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(dfs(r,c,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(int r,int c,vector<vector<char>>& board,string& word,int i){
        if(i==word.size()) return true;
        if(r<0||c<0||r>=row||c>=col||board[r][c]!=word[i]||board[r][c]=='#') return false;
        board[r][c]='#';
        bool res=dfs(r+1,c,board,word,i+1)||dfs(r-1,c,board,word,i+1)||dfs(r,c+1,board,word,i+1)||dfs(r,c-1,board,word,i+1);
        board[r][c]=word[i];
        return res;
    }
};
