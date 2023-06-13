class Solution {
public:
    bool bfs(int node,int V,vector<int>& col,vector<vector<int>>& graph){
        queue<int> q;
        q.push(node);
        col[node]=1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int curcol = col[node];
            for(auto it:graph[node]){
                if(!col[it]){
                    col[it] = -curcol;
                    q.push(it);
                }else if(col[it] == curcol){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        int c=1;
        vector<int> col(V,0);

       for(int i=0;i<V;i++){
           if(!col[i]){
               if(!bfs(i,V,col,graph)) return false;
           }
       }
       return true;
    }
};