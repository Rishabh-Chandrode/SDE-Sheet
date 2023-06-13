## Kahn's Algorithm
        Topological sorting :- Linear ordering of vertices such that there is an edge between u and v , u appears before v in 
        the ordering


## 1. Clone a Graph
        use map to store copy of nodes
        queue for bfs traversal

        using dfs
                if copy of currnode doesn't exist create new
                itterate on neighbor of curr node
                        if(copy present )
                                push back
                        else
                                recursion in curr

## 2) DFS Graph Traversal
        use recursion to traverse

## 3) BFS Graph Traversal
        use queue to treverse

## 4) BFS detect cycle in undirected graph
        go from different paths if two paths colide with each other then it is a cycle

## 5)DFS detect cycle in undirected graph
        pass parent in parameter
        check for visited node which in not parent

## 6)DFS detect cycle in Directed graph
        use vector to store recursion stack
        remember to remove update recursion array while bracktracking

## 8)Topological sort BFS
        create indegree vector
        push node into queue whose indegree is zero
        remove edges from the queue nodes and push the new nodes whose indegree is zero

## 9)Topological sort DFS
        iterate on vis array
        call dfs if !vis[node]
        mark vis[node] = 1
        call dfs for adj of node
        put node in stack while backtracking
        remove from stack and put into vector 
        




