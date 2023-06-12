class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        if(target< matrix[0][0] || target >matrix[row-1][col-1]){
            return false;
        }
        int low=0,high=row-1,mid;
        while(low<=high){
            mid=(high+low)/2;
            //cout<<mid<<"-"<<endl;
            if(target>=matrix[mid][0] && target <= matrix[mid][col-1]){
               // cout<<mid<<"----"<<endl;
                break;
            }
            if(target<matrix[mid][0]){
                // cout<<mid<<"-1---"<<endl;
                high=mid-1;
                
            }
            if(target>matrix[mid][col-1]){
                 //cout<<mid<<"-2---"<<endl;
                low=mid+1;
               
            }
        }
        
        int ind=mid;
        cout<<ind<<endl;
        high=col-1;
        low=0;
        while(low<=high){
            mid=(high+low)/2;
            if(target==matrix[ind][mid]) return true;
            if(target<matrix[ind][mid]) {
                high = mid-1;
                continue;
            }
            if(target > matrix[ind][mid]){
                low=mid+1;
                continue;
            }
        }
        return false;
    }
};