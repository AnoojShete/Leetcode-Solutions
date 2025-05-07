class Solution {
public:
int solve(vector<vector<int>>&board,map<string,int>&mp,int x,int y){
    if(board[0][0]==1&&board[0][1]==2&&board[0][2]==3&&board[1][0]==4&&board[1][1]==5&&board[1][2]==0)return 0;
    string temp="";
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            temp+=to_string(board[i][j]);
        }
    }
    if(mp.find(temp)!=mp.end())return 1e6;
    mp[temp]++;
     
    int dx[]={1,-1,0,0};
    int dy[]={0,0,-1,1};
    int ans=INT_MAX;
    for(int i=0;i<4;i++){
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(newx>=0&&newx<=1&&newy>=0&&newy<=2){
            swap(board[x][y], board[newx][newy]);
            ans=min(ans,1+solve(board,mp,newx,newy));  
            swap(board[x][y], board[newx][newy]);          
        }
    }
    return ans;
}
    int slidingPuzzle(vector<vector<int>>& board) {
        map<string,int>mp; 
        int x;int y;
        string temp="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==0){x=i;y=j;}
                temp+=to_string(board[i][j]);
            }
        }                
        int ans= solve(board,mp,x,y);   
        return ans>=1e6?-1:ans;     
    }
};