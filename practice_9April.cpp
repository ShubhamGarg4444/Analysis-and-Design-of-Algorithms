/*
#include<bits/stdc++.h>
using namespace std ;

#define INF 100000000

void printMatrix(vector<vector<int>> &a, int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<a[i][j]<<" \t " ;
        }
        cout<<endl ;
    }
}

void printOrder(vector<vector<int>> &s, int i, int j)
{
    if(i == j) cout<<"A"<<i<<" " ;

    else{
        cout<<"(" ;
        printOrder(s,i,s[i][j]) ;
        printOrder(s,s[i][j]+1,j) ;
        cout<<")" ;
    }
}

void MCM(vector<int> p)
{
    int n = p.size() - 1 ;
    vector<vector<int>> m(n+1, vector<int>(n+1, 0)) ;
    vector<vector<int>> s(n+1, vector<int>(n+1, 0)) ;

    for(int i=1; i<=n; i++)
    {
        m[i][i] = 0 ;
    }

    for(int l=2; l<=n; l++)
    {
        for(int i=1; i<=n-l+1; i++)
        {
            int j = i+l-1 ;
            m[i][j] = INF ;

            for(int k=1; k<j; k++)
            {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j] ;

                if(q < m[i][j])
                {
                   m[i][j] = q ;
                   s[i][j] = k ;
                }
            }
        }
    }
    
    cout<<"Cost matrix (m) : "<<endl ;
    printMatrix(m, n) ;
    cout<<"Split matrix (s) : "<<endl ;
    printMatrix(s, n) ;

    cout<<"Print the order in which there is minimum scalar multiplications : "<<endl ;
    printOrder(s, 1, n) ;
}

int main()
{
    vector<int> p = {10,15,20,5,10} ;
    MCM(p) ;

    return 0 ;
}
*/











/*
// no. of stages in multistage graph
#include<bits/stdc++.h>
using namespace std ;

int stages_mg(vector<vector<pair<int,int> > > &graph, int src, int dest, int n)
{
    stack<int> st ;
    vector<int> stages(n, -1) ;

    stages[src] = 1 ;
    st.push(src) ;

    cout<<"vertex is = "<<src<<" and its stage is = "<<stages[src]<<endl ;

    while(!st.empty())
    {
        int u = st.top() ;
        st.pop() ;

        for(auto edge : graph[u])
        {
            int v = edge.first ;  // destination edge

            if(stages[v] == -1)   // there is an edge between u and v and stage of destination vertex is -1
            {
                stages[v] = stages[u] + 1 ;
                st.push(v) ;

                cout<<"vertex is = "<<v<<" and its stage is = "<<stages[v]<<endl ;
            }
        }
    }

    return stages[dest] ;
}

int main()
{
    int n = 8 ;
    vector<vector<pair<int,int>>> graph(n) ;

    graph[1] = {{2,2},{3,5},{4,9}} ;
    graph[2] = {{5,13},{6,16}} ;
    graph[3] = {{5,12}} ;
    graph[4] = {{6,11}} ;
    graph[5] = {{7,4}} ;
    graph[6] = {{7,8}} ;

    int src = 1 ;
    int dest = 7 ;

    int stage = stages_mg(graph, src, dest, n) ;

    cout<<"number of stages in multistage graph = "<<stage<<endl ;

    return 0 ;
}
*/











/*
#include<bits/stdc++.h>
using namespace std ;

int Knapsack(int p[], int w[], int W, int n)
{
    // n = number of items
    // W = total capacity of knapsack
    // p[] = profit array of items
    // w[] = weight array of items

    int K[n+1][W+1] ; // final 2D matrix

    for(int i=0; i<=n; i++) // row is made up of 0 to n number of items
    {
        for(int j=0; j<=W; j++) // column is made up of 0 to W knapsack weight
        {
            if(i==0 || j==0) // if weight or no. of items is zero
            {
                K[i][j] = 0 ;
            }

            else if(w[i-1] <= j)
            {
                K[i][j] = max(p[i-1] + K[i-1][j-w[i-1]], K[i-1][j]) ;   // include and exclude the item respectively
            }

            else{
                K[i][j] = K[i-1][j] ;
            }
        }
    }
    return K[n][W] ;
}

int main()
{
    int p[] = {2,3,4,1} ;
    int w[] = {3,4,5,6} ;  // weights must be in ascending order

    int W = 8 ; 
    int n = 4 ; 

    int maxProfit = Knapsack(p,w,W,n) ;

    cout<<"Maximum profit earned = "<<maxProfit<<endl ;

    return 0 ;
}
*/










/*
#include<bits/stdc++.h>
using namespace std ;

void print(string &x, string &y, int i, int j, vector<vector<int>> &mat)
{
    // (i,j) is the index of matrix in which length of longest common subsequence is stored
    if(i==0 || j==0)
    return ;

    if(x[i-1] == y[j-1])
    {
        print(x,y,i-1,j-1,mat) ;
        cout<<x[i-1] ;
    }

    else if(mat[i-1][j] > mat[i][j-1])
    {
        print(x,y,i-1,j,mat) ;
    }

    else{
        print(x,y,i,j-1,mat) ;
    }
}

void lcs(string &x, string &y)
{
    int len1 = x.length() ;
    int len2 = y.length() ;

    vector<vector<int>> mat(len1+1, vector<int>(len2+1, 0)) ;

    for(int i=0; i<=len1; i++)
    {
        for(int j=0; j<=len2; j++)
        {
            if(i==0 || j==0)
            mat[i][j] = 0 ;

            else if(x[i-1] == y[j-1])
            mat[i][j] = 1 + mat[i-1][j-1] ;

            else
            mat[i][j] = max(mat[i-1][j], mat[i][j-1]) ;
        }
    }
    cout<<"Length of common subsequence = "<<mat[len1][len2]<<endl ; ;

    cout<<"LCS is: " ;
    print(x,y,len1,len2,mat) ;
    cout<<endl ;
}

int main()
{
    string x = "acadb" ;
    string y = "cbda" ;

    lcs(x,y) ;

    return 0 ;
}
*/








