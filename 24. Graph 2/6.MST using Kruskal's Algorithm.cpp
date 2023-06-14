//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class disjoint_set{
    private:
        vector<int> parent,rank,size;
    
    public:
        disjoint_set(int n){
            parent.resize(n+1,0);
            rank.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i] = i;
            }
        }
        int findupar(int node){
            if(parent[node] == node) return node;
            return parent[node] = findupar(parent[node]);
        }

        void unionbyrank(int u,int v){
            int ulp_u = findupar(u);
            int ulp_v = findupar(v);
            if(ulp_u == ulp_v) return ;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }else if(rank[ulp_u] > rank[ulp_v]) {
                parent[ulp_v] = ulp_u;
            }else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionbysize(int u,int v){
            int ulp_u = findupar(u);
            int ulp_v = findupar(v);

            if(ulp_u == ulp_v) return ;

            if(size[ulp_u] < size[ulp_v] ){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] +=size[ulp_v];
            }
        }

};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        disjoint_set ds(V);
        vector<pair<int,pair<int,int>>> e;
        for(int i=0;i<V;i++){
            int node = i;
            for(auto it:adj[i]){
                int adjnode = it[0];
                int wt = it[1];
                e.push_back({wt,{node,adjnode}});
            }
        }
        
        sort(e.begin(),e.end());
        int mst =0;
        for(auto it:e){
            int wt = it.first;
            int node = it.second.first;
            int adjnode = it.second.second;
            
            if(ds.findupar(node) != ds.findupar(adjnode)){
                mst += wt;
                ds.unionbysize(node,adjnode);
            }
        }
        return mst;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends