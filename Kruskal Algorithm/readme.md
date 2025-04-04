📌 Overview
This C++ program implements Kruskal's Algorithm to find the Minimum Spanning Tree (MST) of a connected, undirected, weighted graph. The algorithm is a greedy method that works by selecting edges in increasing order of their weights, and adding them to the MST unless they form a cycle. It uses the Union-Find (Disjoint Set Union - DSU) data structure to efficiently check and manage cycles in the graph.


🧠 Algorithm Description
1.	Sort Edges by Weight: First, sort all the edges in non-decreasing order of their weights.

2.	Union-Find Data Structure: Initialize a parent array where each vertex is initially its own parent. This will help us efficiently check if adding an edge would form a cycle.

3.	Add Edges to MST: Iterate through the sorted edges and add an edge to the MST if it connects two different components (i.e., the find operation of the two vertices returns different values). Perform the union operation to merge the components.

4.	Stop when MST is Complete: The MST will have n−1 edges, where n is the number of vertices. If this condition is met, stop adding edges.

5.	Cycle Detection: If adding an edge would form a cycle (i.e., the two vertices are already in the same component), skip that edge.

6.	Output the Result: The sum of the weights of the selected edges is the cost of the MST. If the number of edges in the MST is less than n−1, the graph is not connected, and no MST is possible.
