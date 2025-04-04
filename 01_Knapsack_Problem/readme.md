📘 Problem Statement
Given:
•	An array p[] where p[i] is the profit of the i-th item
•	An array w[] where w[i] is the weight of the i-th item
•	An integer W representing the maximum capacity of the knapsack
Find the maximum profit that can be earned by selecting a subset of items such that:
•	Each item is either taken once or not at all (0/1 Knapsack)
•	The total weight of selected items is ≤ W

📊 Approach
•	Uses Dynamic Programming (Bottom-Up Tabulation).
•	Builds a 2D table K[n+1][W+1], where each entry K[i][j] stores:
Maximum profit achievable using the first i items with capacity j.
