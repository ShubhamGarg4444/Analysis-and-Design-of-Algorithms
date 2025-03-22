#include <bits/stdc++.h>
using namespace std;

void printMST(vector<int> &parent, vector<vector<int>> &graph) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < graph.size(); i++)
        cout << parent[i] << " - " << i << " \t" << graph[parent[i]][i] << " \n";
}

void primMST(vector<vector<int>> &graph) 
{
    
    int V = graph.size();
  
    // Key values used to pick minimum weight edge 
    vector<int> key(V);

    // To represent set of vertices included in MST
    vector<bool> mstSet(V);

    // Array to store constructed MST
    vector<int> parent(V);

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first
    // vertex.
    key[0] = 0;
  
    // First node is always root of MST
    parent[0] = -1 ;

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u ;
        int mini = INT_MAX ;

        for(int i=0;i<V;i++)
        {
            if(!mstSet[i] && key[i] < mini)
            {
                mini = key[i] ;
                u = i ;
            }
        }

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not yet included in MST
        for (int v = 0; v < V; v++)
            {
                if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u ;
                key[v] = graph[u][v] ;
            }
    }

    printMST(parent, graph);
}

// Driver's code
int main() {
      vector<vector<int>> graph = { { 0, 2, 0, 6, 0 },
                                { 2, 0, 3, 8, 5 },
                                { 0, 3, 0, 0, 7 },
                                { 6, 8, 0, 0, 9 },
                                { 0, 5, 7, 9, 0 } };

    primMST(graph);

    return 0;
}
