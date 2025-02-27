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