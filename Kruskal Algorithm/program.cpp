#include<bits/stdc++.h>
using namespace std ;

struct Edge{
    int src ;
    int dest ;
    int weight ;
};

bool compare(Edge &a, Edge &b)
{
    return a.weight < b.weight ; 
}

vector<int> parent ;

int find(int i)
{
    while(parent[i] != i)
    {
        i = parent[i] ;
    }
    return i ;
}

void unionSet(int i, int j)
{
    int a = find(i) ;
    int b = find(j) ;
    parent[a] = b ;
}

int kruskal(int n, vector<Edge>& edges)
{
    // sort the edges in increasing order of their cost or weight
    sort(edges.begin(), edges.end(), compare) ;

    // initialize parent array to keep track of the parent of each node
    parent.resize(n) ;
    for(int i=0; i<n; i++)
        parent[i] = i ;

    int minCost = 0 ; // to store the total cost of the MST
    int edgeCount = 0 ; // Count of edges added to MST

    for(int i=0; i<n && edgeCount < n-1; i++)
    {
        int src = edges[i].src ;
        int dest = edges[i].dest ;
        int weight = edges[i].weight ;

        // if the selected edge does not form a cycle
        if(find(src) != find(dest))
        {
            minCost += weight ;
            unionSet(src, dest) ;
            edgeCount++ ;

        // print the selected edge
        cout<<src<<" -- "<<dest<<" = "<<weight<<endl;
        }
    }
    if(edgeCount != n-1)
    {
        cout<<"Graph is not connected, so MST is not possible."<<endl;
        return -1 ;
    }
    else{
        return minCost ;
    }
}

int main()
{
    int n = 5 ;

    vector<Edge> edges = {
        {0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}
    };

    cout << endl << "Minimum Spanning Tree cost: " << kruskal(n, edges) << endl ;
    return 0 ;
}
