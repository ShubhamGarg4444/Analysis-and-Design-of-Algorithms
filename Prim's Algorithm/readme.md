🧠 Algorithm Description
1.	Initialization:
o	Set the key value for all vertices as infinity (INT_MAX), except the first vertex which is set to 0.
o	The parent array is initialized to store the MST structure, and the mstSet array keeps track of vertices included in the MST.

2.	Select the Minimum Key Vertex:
o	Pick the vertex with the minimum key value that hasn't been added to the MST yet.

3.	Update Key and Parent Values:
o	For the selected vertex, update the key values of its adjacent vertices if a smaller weight edge is found, and update their parent to reflect the chosen edge.

4.	Repeat the Process:
o	Repeat the process until all vertices are included in the MST.

5.	Output the Result:
o	The parent array contains the MST edges, which are printed out as the final result.
