//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void dfs(int node,int V,vector<int>& vis,stack<int>& s,vector<vector<int>>& adj){
        vis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,V,vis,s,adj);
        }
        s.push(node);
        return ;
    }
    void revdfs(int node,int V,vector<int>& vis,vector<vector<int>>& reverse){
        vis[node] = 1;
        for(auto it:reverse[node]){
            if(!vis[it]) revdfs(it,V,vis,reverse);
        }
        return ;
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack<int> s;
        vector<int> vis(V,0);
        
        //topological sort
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(i,V,vis,s,adj);
        }
        
        
        //reversing edges
        vector<vector<int>> reverse(V,vector<int> ());
        
        for(int i=0;i<V;i++){
            vis[i] = 0;
            for(auto it:adj[i]){
                reverse[it].push_back(i);
            }
        }
        
        int count=0;
        
        while(!s.empty()){
            int node = s.top();
            s.pop();
            if(!vis[node]){
                count++;
                revdfs(node,V,vis,reverse);
            }
        }
        return count;
        
        
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends