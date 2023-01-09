class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col=false;
        int m=matrix.size();
        int n=matrix[0].size();
        //setting 0th row and 0 columns to zero 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0 ){
                    if(matrix[i][j]==0){
                         col=true;
                        
                    }
                    continue;
                }
                if(matrix[i][j]==0){
                    
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }

            }
        }
        //checking for row || column for 0
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>0;j--){
                
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
            if(col){
                matrix[i][0]=0;
            }
        }
        
       
        
    }
};