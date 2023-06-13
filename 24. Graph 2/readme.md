## 1)Strongly Connected Components (Kosaraju's Algo)
        three step method for finding no of strongly connected components
        1- find topological order of nodes
        2- reverse all the edges
        3- apply dfs on the nodes in the topological order

## 2)Implementing Dijkstra Algorithm
        use set or priority queues to implement Dijkstra algorithm
        queue are not efficient because of more iterations

## 3)Distance from the Source (Bellman-Ford Algorithm)
        do n-1 relaxations 
        if nth itteration is hapening the the graph contain a negative cycle 