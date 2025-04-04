📌 Overview
This C++ program solves the Multistage Graph Problem using Dynamic Programming (DP). The problem involves finding the shortest path from the start vertex to the destination vertex in a directed graph, where the vertices are divided into stages. The objective is to traverse the graph in such a way that the total cost is minimized, with the constraint that the traversal must progress from one stage to the next in sequence.


🧠 Key Concepts
1.	Multistage Graph: A graph with multiple stages where each stage is a set of vertices, and edges connect vertices of one stage to vertices in the next stage.

2.	Dynamic Programming Approach: This approach is used to solve the problem by breaking it down into simpler subproblems. We compute the minimum cost to reach each vertex in the last stage from each vertex in the earlier stages.

3.	Path Reconstruction: After calculating the minimum cost, the program also reconstructs and outputs the shortest path from the start vertex to the destination vertex.
