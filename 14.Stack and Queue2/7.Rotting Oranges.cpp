class Solution {
public:
struct Node{
    int row,col,time;
};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<Node> q;
        int row = grid.size();
        int col = grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 2){
                    Node temp;
                    temp.row =i;
                    temp.col = j;
                    temp.time = 0;
                    q.push(temp);
                }
            }
        }
        
        int time = 0;
        while(!q.empty()){
        
            Node pos = q.front();
          
            q.pop();
            time = pos.time;
            if(pos.row-1>=0 && grid[pos.row-1][pos.col] == 1 && pos.time == time){
               
                Node temp ;
                temp.row = pos.row-1;
                temp.col = pos.col;
                temp.time = time+1;
                q.push(temp);
                grid[temp.row][temp.col] = 2;
                
            }
            if(pos.row+1<row && grid[pos.row+1][pos.col] == 1 && pos.time == time){
                 
                Node temp ;
                temp.row = pos.row+1;
                temp.col = pos.col;
                temp.time = time+1;
                q.push(temp);
                grid[temp.row][temp.col] = 2;
               
            }
            if(pos.col-1>=0 && grid[pos.row][pos.col-1] == 1 && pos.time == time){
                
                Node temp ;
                temp.row = pos.row;
                temp.col = pos.col-1;
                temp.time = time+1;
                q.push(temp);
                grid[temp.row][temp.col] = 2;
                 
            }
            if(pos.col+1<col && grid[pos.row][pos.col+1] == 1 && pos.time == time){
                
                Node temp ;
                temp.row = pos.row;
                temp.col = pos.col+1;
                temp.time = time+1;
                q.push(temp);
                grid[temp.row][temp.col] = 2;
                 
            }
            
           
        }
       
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1){
                   return -1;
                }
            }
            
        }
        return time;
    }
};