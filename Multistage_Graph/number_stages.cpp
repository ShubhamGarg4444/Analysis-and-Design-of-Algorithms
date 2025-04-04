#include<bits/stdc++.h>
using namespace std ;

int stages_multistage(vector<vector<pair<int,int> > > &graph, int n, int src, int sink)
// graph - adjacency list where each node stores (neighbor, weight) pairs
// n - number of vertices (start from 0 index)
{
    // use depth first search - stack

    vector<int> stages(n, -1) ; // store the stage of each vertex

    stack<int> st ;
    st.push(src) ;
    stages[src] = 1 ;
    cout<<"vertex is = "<<src<<" and its stage is = "<<stages[src]<<endl ;

    while(!st.empty())
    {
        int node = st.top() ;
        st.pop() ;

        for(auto edge : graph[node])
        {
            int dest = edge.first ;

            if(stages[dest] == -1)
            {
                stages[dest] = stages[node] + 1 ; // Update stage of destination node
                st.push(dest) ;

                cout<<"vertex is = "<<dest<<" and its stage is = "<<stages[dest]<<endl ;
            }
        }
    }


    return stages[sink] ; // The stage number of the sink is the number of stages
}

int main()
{
    int n = 8 ;
    vector<vector<pair<int, int>>> graph(n);

    graph[0] = {{1, 1}, {2, 2}, {3, 5}};
    graph[1] = {{4, 4}, {5, 11}};
    graph[2] = {{4, 9}, {5, 5}, {6, 16}};
    graph[3] = {{6, 2}};
    graph[4] = {{7, 18}};
    graph[5] = {{7, 13}};
    graph[6] = {{7, 2}};

    int stage = stages_multistage(graph, n, 0, n-1) ;

    cout<<"number of stages in multistage graph = "<<stage<<endl ;

    return 0 ;
}