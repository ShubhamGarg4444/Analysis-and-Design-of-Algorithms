#include<bits/stdc++.h>
using namespace std ;

bool isSafe(vector<vector<int>> &graph, int ci, int n, vector<char> &color, vector<char> &ans)
{
    for(int v=1; v<=n; v++)
    {
        // Check if 'v' is adjacent to 'ci'
        if(find(graph[ci].begin(), graph[ci].end(), v) != graph[ci].end()) 
        {
            if(ans[v] == ans[ci]) 
            return false ;
        }
    }
    return true ;
}

bool graph_color(vector<vector<int>> &graph, int ci, int n, vector<char> &color, vector<char> &ans)
// ci is current index
// n is the total number of vertices
// color vector contains the name of colors available
{
    // base case
    if(ci > n)  // starting from index 1
    return true ;

    int cl = color.size() ;

    for(int col=0; col<cl; col++)
    {
        ans[ci] = color[col] ;

        if(isSafe(graph,ci,n,color,ans))
        {
            if(graph_color(graph,ci+1,n,color,ans))
            {
                return true ;
            }
        }
        ans[ci] = ' ';  // backtrack
    }
    return false ;
}

int main()
{
    vector<vector<int>> graph(6);  // initialize graph (i am using 1-based indexing)
    graph[1] = {2,5} ;
    graph[2] = {1,3,5} ;
    graph[3] = {2,4,5} ;
    graph[4] = {3,5} ;
    graph[5] = {1,2,3,4} ;

    cout<<"no of vertices (n) = "<<graph.size()-1<<endl ;

    vector<char> color = {'r','g','b'} ;

    vector<char> ans(6, ' '); // index 1 to 5

    if (graph_color(graph, 1, 5, color, ans))
    {
        cout << "Color assignment:" << endl;
        for (int i = 1; i <= 5; i++)
        {
            cout << "Vertex " << i << " -> " << ans[i] << endl;
        }
    }

    else
    {
        cout<<"No solution found"<<endl ;
    }

    return 0 ;
}