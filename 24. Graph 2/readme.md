## 1)Strongly Connected Components (Kosaraju's Algo)
        three step method for finding no of strongly connected components
        1- find topological order of nodes
        2- reverse all the edges
        3- apply dfs on the nodes in the topological order

## 2)Implementing Dijkstra Algorithm

        Does not work for negative cycle

        use set or priority queues to implement Dijkstra algorithm
        queue are not efficient because of more iterations

## 3)Distance from the Source (Bellman-Ford Algorithm)
        do n-1 relaxations 
        if nth itteration is hapening the the graph contain a negative cycle 

## 4)shortest distance between every pair of node (Floyd Warshall)
        distance of i->j = min( dis of i->j, dist i->k + dist k->j )
        simple brute force approach

## 5)Minimum Spanning Tree (Prim's Algo)
        keep a priority queue for the edges in the form of {wt,node}

## 6)MST using Kruskal's Algorithm 
        sort vector according to wt
        use disjoint sets to find if the two nodes are already connected or not