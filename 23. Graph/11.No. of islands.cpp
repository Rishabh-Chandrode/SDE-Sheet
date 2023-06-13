//BFS approach

class Solution {
public:
    void fill(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        q.push(make_pair(i,j));
        vis[i][j]=1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x>0){
                if(!vis[x-1][y] && grid[x-1][y] == '1') {
                    q.push(make_pair(x-1,y));
                    vis[x-1][y]=1;
                    }
            }
            if(x+1<m){
                if(!vis[x+1][y] && grid[x+1][y] == '1' ) {
                    q.push(make_pair(x+1,y));
                    vis[x+1][y]=1;
                    }
            }
            if(y>0){
                if(!vis[x][y-1] && grid[x][y-1] == '1' ) {
                    q.push(make_pair(x,y-1));
                    vis[x][y-1]=1;
                    }
            }
            if(y+1<n){
                if(!vis[x][y+1] && grid[x][y+1] == '1') {
                    q.push(make_pair(x,y+1));
                    vis[x][y+1]=1;
                    }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count=0;
        vector<vector<int>> vis(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    count++;
                    fill(i,j,vis,grid);
                }
            }
        }
        return count;
    }
};





//DFS approach

class Solution {
private:
    void fill(int x,int y,int m,int n,vector<vector<char>>& grid){
        if(x<0 || x>=m || y<0 || y>=n) return ;

        if(grid[x][y]=='0') return ;

        grid[x][y]='0';
        fill(x+1,y,m,n,grid);
        fill(x-1,y,m,n,grid);
        fill(x,y+1,m,n,grid);
        fill(x,y-1,m,n,grid);
        return; 
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                   // cout<<i<<" "<<j<<" "<<grid[i][j];
                if(grid[i][j] == '1'){
                    count++;
                    fill(i,j,m,n,grid);
                }
            }
        }
        return count;
    }
};