#include<bits/stdc++.h>
using namespace std ;

void printMatrix(vector<vector<int>> &m, int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout << m[i][j] << " \t " ;
        }
        cout << endl ;
    }
}

void printOrder(vector<vector<int>> &s, int i, int j)
{
    if(i==j)
    cout<<"A"<<i<<" " ;

    else {
        cout<<"( " ;
        printOrder(s, i, s[i][j]) ;
        printOrder(s, s[i][j]+1, j) ;
        cout<<" )" ;
    }

    // cout << "Multiply A" << i << " and A" << (s[i][j]+1) << endl ;
}

void mcm(vector<int> p)
{
    int n = p.size() - 1 ; // n defines number of matrices

    vector<vector<int>> m(n+1, vector<int>(n+1,0)) ; // m stores the cost i.e. - minimum number of scalar multiplications required to perform matrix multiplication
    vector<vector<int>> s(n+1, vector<int>(n+1,0)) ; // s stores the split index i.e. - at which matrix we must parenthesize to get the desired order of matrix multiplication

    for(int i=1; i<=n; i++)
    {
        m[i][i] = 0 ; // diagonal elements are all zero  because m[i,i] denotes a single matrix 
        // for e.g. - m[1,1] means A1 matrix which is not multiplying with any other matrix
    }

    for(int l=2; l<=n; l++) // which type of pairs can be made (e.g. - 2 matrix, 3 matrix, 4 matrix pairs to multiply)
    {
        for(int i=1; i<=n-l+1; i++) // define the first index of all pairs
        {
            int j = i + l -1 ; // define the second index of all pairs according to i 

            m[i][j] = INT_MAX ;

            for(int k=i; k<j; k++) // it defines the split index
            {
                int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j] ;

                if(q < m[i][j])
                {
                    m[i][j] = q ;
                    s[i][j] = k ;
                }
            }
        }
    }
    cout << "Cost Matrix (m):\n" ;
    printMatrix(m, n) ;
    cout << "Split Matrix (s):\n" ;
    printMatrix(s, n) ;

    cout<<"order of matrix multiplication: "<<endl ;
    printOrder(s, 1, n) ;
}

int main()
{
    vector<int> p = {10, 15, 20, 5, 10} ;
    mcm(p) ;
    return 0 ;
}
