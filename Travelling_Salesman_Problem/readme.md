📘 Problem Statement
Given:
•	n cities
•	A complete cost matrix dist[i][j] where dist[i][j] is the cost to travel from city i to city j

Task:
•	Start from city 0
•	Visit each other city exactly once
•	Return to the starting city
•	Minimize the total travel cost


🧠 Approach
•	Uses recursive function g(i, S):
o	i: current city
o	S: set of unvisited cities

•	At each step:
o	Try all possible cities j in S
o	Calculate total cost of visiting j and solving subproblem g(j, S - {j})

•	Uses memoization with map<pair<int, set<int>>, int> to cache already computed states and avoid recomputation.
