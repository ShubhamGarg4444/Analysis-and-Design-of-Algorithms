#include<bits/stdc++.h>
using namespace std ;

bool isSafe(vector<vector<int>> &graph, int ci, int n, int i, vector<int> &ans)
{
    // there is an edge between previous node and current node
    // every node must be visited only once ---- current node is not already in ans
    // if it's the last node, it connects to the starting node


    // (graph[ci][i] == 0) is wrong because ci is just a counter, not the actual index number
    // we have to check whether we go from the current node to the next one(i)
    if(graph[ans.back()][i] == 0)     
    return false ;

    for (int node : ans)  // Already visited
        {
            if (node == i)
            return false ;
        }

    // If this is the last node, check if there's an edge to starting node
    if (ci == n && graph[i][ans[0]] == 0)
        return false ;

    return true ;
}

bool hamiltonian(vector<vector<int>> &graph, int ci, int n, vector<int> &ans)
{
    // n is total number of vertices in graph
    // graph is adjacency matrix
    // ci is just 

    if(ci > n) // 1-based indexing (base case)
    {
        return true ;
    }

    for(int i=1; i<=n; i++)
    {
        if(isSafe(graph,ci,n,i,ans))
        {
            ans.push_back(i) ;

            if(hamiltonian(graph,ci+1,n,ans))
            {
                return true ;
            }

            ans.pop_back() ;  // backtrack
        }
    }
    return false ;
}

int main()
{
    int n=6 ;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    
    graph[1][2] = graph[2][1] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[1][4] = graph[4][1] = 1;
    graph[2][3] = graph[3][2] = 1;
    graph[2][5] = graph[5][2] = 1;
    graph[3][6] = graph[6][3] = 1;
    graph[4][5] = graph[5][4] = 1;
    graph[4][6] = graph[6][4] = 1;
    graph[5][6] = graph[6][5] = 1;


    vector<int> ans ;
    ans.push_back(1) ;

    if(hamiltonian(graph,2,n,ans))
    {
        cout<<"One valid solution: "<<endl ;
        for(int i=0; i<ans.size(); i++)
        {
            cout<<ans[i]<<" " ;
        }
        cout<<ans[0] ;
        cout<<endl ;
    }
    else{
        cout<<"No valid solution exist"<<endl ;
    }

    return 0 ;
}
