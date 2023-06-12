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


