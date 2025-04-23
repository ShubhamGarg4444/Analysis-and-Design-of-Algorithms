#include<bits/stdc++.h>
using namespace std ;

// now i have to write the function to print the longest common subsequence
void print(string x, string y, int i, int j, vector<vector<int>>& l)
{
    // (i,j) represents the length of the longest common subsequence

    if(i == 0 || j == 0)
    return ;

    if(x[i-1] == y[j-1])
    {
        print(x, y, i-1, j-1, l);
        cout << x[i - 1];  // print after recursion to get correct order
    }

    else if(l[i-1][j] > l[i][j-1])
    {
        print(x, y, i-1, j, l) ;
    }
    
    else{
        print(x, y, i, j-1, l) ;
    }
}


void lcs(string x, string y)
{
    int m = x.length();
    int n = y.length();

    vector<vector<int>> l(m+1, vector<int>(n+1)) ;

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 || j==0)
                l[i][j] = 0;

            else if(x[i-1] == y[j-1])  // when i = 1, it corresponds to x[0]
                l[i][j] = l[i-1][j-1] + 1;

            else
                l[i][j] = max(l[i-1][j], l[i][j-1]);
        }
    }
    cout << "Length of LCS is: " << l[m][n] << endl ;
    cout << "LCS is: " ;
    print(x, y, m, n, l) ;
    cout << endl ;
}

int main()
{
    string x = "abaaba" ;
    string y = "babbab" ;

    lcs(x, y) ;

    return 0 ;
}