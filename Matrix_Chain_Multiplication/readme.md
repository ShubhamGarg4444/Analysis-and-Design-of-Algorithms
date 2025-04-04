🧮 Problem Statement
Given a chain of matrices A1, A2, ..., An, the goal is to fully parenthesize the product such that the total number of scalar multiplications is minimized.

For example, given matrices of dimensions:
A1: 10x15,  A2: 15x20,  A3: 20x5,  A4: 5x10
Input to the algorithm is a vector of dimensions:
vector<int> p = {10, 15, 20, 5, 10};
Where matrix Ai has dimensions p[i-1] x p[i].


🚀 Approach
•	Uses Dynamic Programming (DP) to build two matrices:

o	m[i][j]: Minimum number of scalar multiplications needed to compute the matrix Ai...Aj
o	s[i][j]: Index k at which to split the product for the optimal result

•	Builds up the solution bottom-up, solving all subproblems of length l from 2 to n.
•	Also prints the optimal parenthesization using a recursive printOrder function.
