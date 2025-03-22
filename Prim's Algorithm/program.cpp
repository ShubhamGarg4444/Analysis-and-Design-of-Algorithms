#include <bits/stdc++.h>
using namespace std;

int prim(int n, vector<pair<pair<int, int>, int>> &g) 
{
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++) 
    {
        int u = g[i].first.first;  // Removed -1 adjustment
        int v = g[i].first.second; // Removed -1 adjustment
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n, INT_MAX);   // Minimum distance between two adjacent nodes
    vector<bool> mst(n, false);    // Track visited nodes
    vector<int> parent(n, -1);     // Parent of each node in MST

    // Start from node 0
    key[0] = 0;
    parent[0] = -1;

    int mincost = 0;
    int edgecount = 0; // Number of edges in MST

    for (int i = 0; i < n - 1; i++) 
    {
        // Find the node with the minimum key value
        int mini = INT_MAX;
        int u = -1;

        for (int v = 0; v < n; v++) {
            if (!mst[v] && key[v] < mini) 
            {
                u = v;
                mini = key[v];
            }
        }

        if (u == -1) {
            cout << "MST not possible (graph is disconnected)\n";
            return -1;
        }

        // Mark the node as visited
        mst[u] = true;
        if (parent[u] != -1) 
        {
            mincost += key[u];
            edgecount++;
        }

        // Update key values of adjacent nodes
        for (auto it : adj[u]) {
            int v = it.first;
            int w = it.second;

            if (!mst[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    // Ensure MST is valid
    if (edgecount != n - 1) {
        cout << "MST not possible (graph is disconnected or has fewer edges)\n";
        return -1;
    }

    // Print the MST edges
    cout << "Edges in MST:\n";
    for (int i = 1; i < n; i++) { 
        cout << parent[i] << " -- " << i << " = " << key[i] << endl;
    }

    return mincost;
}

int main() 
{
    int n = 5;  

    vector<pair<pair<int, int>, int>> edges = 
{
    {{0,1},2}, {{0,3},6}, {{1,2},3}, {{1,3},8}, {{1,4},5}, {{4,2},7}, {{3,4},4}
};

    int cost = prim(n, edges);
    if (cost != -1) {
        cout << "Minimum Spanning Tree cost: " << cost << endl;
    }

    return 0;
}
