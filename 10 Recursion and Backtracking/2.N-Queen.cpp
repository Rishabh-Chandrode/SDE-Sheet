class Solution {
public:
    vector<vector<string>> ans;
    bool canplace(int x,int y,int n,vector<string>& v){
        if(x==0){
            return true;
        }
        int row=x,col=y;
        while(row--){
            if(v[row][col] == 'Q') return false;
        }
        row=x;
        while(row && col){
             row--;
            col--;
            if(v[row][col]=='Q') return false;
           
        }
        row=x;
        col=y;
        while(row && (col<n)){
             row--;
            col++;
            if(v[row][col]=='Q') return false;
           
        }
        return true;
    }
    void util(int i,int n,vector<string>& v){
        if(i==n){
            ans.push_back(v);
            return;
        }

        for(int j=0;j<n;j++){
           
            if(canplace(i,j,n,v)){
                
                v[i][j]='Q';
                
                util(i+1,n,v);
                v[i][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
       
        vector<string> v;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++){
                s+='.';
            }
            v.push_back(s);
            
        }
        
        util(0,n,v);
        return ans;
    
    }
};