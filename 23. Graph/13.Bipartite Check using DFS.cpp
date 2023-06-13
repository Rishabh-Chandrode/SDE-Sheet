class Solution {
private:
    bool dfs(int node,int& parentcol,int V,vector<int>& col,vector<vector<int>>& graph){
        int curcol = -parentcol;
        col[node] = curcol;
        for(auto it:graph[node]){
            if(!col[it]){
                if(!dfs(it,curcol,V,col,graph)) return false;
            }else if(col[it] == curcol){
                return false;
            }
        }
        return true;
    }
public:

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> col(V,0);
        int parentcol=-1;
        for(int i=0;i<V;i++){
            if(!col[i]){
                if(!dfs(i,parentcol,V,col,graph)) return false;
            }
        }
        return true;
    }
};