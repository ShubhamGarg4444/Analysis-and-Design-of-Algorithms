📌 Problem Statement
Given a graph with n vertices and weighted edges (positive or negative), the goal is to compute the shortest path between every pair of vertices.


🛠️ Approach
•	The algorithm uses a dynamic programming approach and updates the shortest distances between all pairs of nodes.
•	It iteratively checks whether a path from i to j via an intermediate vertex k is shorter than the current known distance.
•	Uses -1 to represent no direct edge (infinity) and updates paths only when a better one is found.


💡 Key Points
•	✅ Supports negative weights
•	❌ Does not support negative weight cycles
•	🧮 Uses an adjacency matrix representation of the graph
