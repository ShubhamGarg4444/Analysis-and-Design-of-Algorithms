/*
Algorithm ShortestPaths(v, dist, cost, n)
{
    // v is source vertes
    // cost determines the weight between edges
    // n = total number of vertices

    // dist[j], 1<=j<=n, is set to the length of the shortest paths from vertex v to vertex j in a digraph G. dist[v] is
    // set to zero. G is represented by its cost adjacency matrix [1:n,1:n]

    for(i=1 to n)
    {
        S[i] = false ; // S is array of selected vertices - initially no vertex is reached
        dist[i] = cost[v,i] ; // dist array is modified acc to cost of edges between two vertices
    }

    S[v] = true ; // source edge
    dist[v] = 0.0 ;

    for(i=2 to n-1)
    {
        // determine n-1 paths from v
        // choose u among those vertices not in S such that dist[u] is minimum
        S[u] = true ;
        for(each w adjacent to u with S[w] = false)
        {
            // Relaxation
            if(dist[u] + cost[u,w] < dist[w])
            {
                dist[w] = dist[u] + cost[u,w] ;
            }
        }
    }
}
*/
























#include<bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 9

int minDistance(int dist[], bool S[])
{
    // its work is to find the index which is at shortest distance from source vertex
    int min = INT_MAX ;
    int min_index ;

    for(int i=0;i<V;i++)
    {
        if(S[i] == false && dist[i] < min)
        {
            min = dist[i], min_index = i ;
        }
    }
    return min_index ;
}

void printSolution(int dist[], int v)
{
    cout << "Vertex \t Distance from Source\n";
    for(int i=0;i<v;i++)
    {
        cout << i << " \t\t " << dist[i] << endl;
    }
}

void dijkstra(int graph[V][V], int src)
{
    // spt = shortest path tree
    // graph[V][V] is adjacency matrix
    // src is source vertex
    // V is number of vertices in graph

    // S[] is a vector which stores whether a vertex is included in the shortest path tree or shortest distance from source to i is finalized
    bool S[V] ;

    // dist[i] is the minimum distance of vertex i from source vertex
    int dist[V] ;

    // Initialize all distances as INFINITE and S[i] as false
    for(int i=0;i<V;i++)
    {
        dist[i] = INT_MAX, S[i] = false ;
    }

    // now include source vertex in spt and initialize its distance as 0
    dist[src] = 0 ;

    // Find shortest path for all vertices except source
    for(int i=1; i<V;i++)
    {
        // choose a vertex u such that S[u] is false and dist[u] is minimum
        int u = minDistance(dist, S);

        // mark the picked vertex
        S[u] = true ;

        // update dist values of the adjacent vertices of the picked vertex
        for(int j=0;j<V;j++)
        {
            // update dist[j] only if is not in spt (shortest path tree), there is an edge from
            // u to j, and total weight of path from src to j through u is smaller than current value of dist[j]
            if(!S[j] && graph[u][j] && dist[u]!= INT_MAX
                && dist[u]+graph[u][j] < dist[j])
            {
                dist[j] = dist[u]+graph[u][j] ; // Relaxation
            }
        }
    }
    printSolution(dist, V);
}

int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    
    dijkstra(graph, 0);

    return 0 ;
}