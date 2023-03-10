class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool issafe(int node,int col,bool graph[101][101],int n,int colour[]){
        for(int i=0;i<n;i++){
            
            if(graph[node][i]==1 ){
                if(colour[i] == col) return false;
            }
           
        }
        return true;
    }
    bool solve(bool graph[101][101],int n,int m,int colour[],int node){
        if(node == n) return true;
        
        
            for(int j=1;j<=m;j++){
                if(issafe(node,j,graph,n,colour)){
                    colour[node]=j;
                    if( solve(graph,n,m,colour,node+1) == true) return true;
                    
                    colour[node]=0;
                }
            }
        
        return false;
        
        
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int colour[n+1]={0};
        if(solve(graph,n,m,colour,0) == true){
            return true;
        }
        return false;
        
    }
};