#include<bits/stdc++.h>
using namespace std ;

// check if it's safe to place a queen at position (x,y)
bool isSafe(int** arr, int x, int y, int n)
{
    // check same column
    for(int row=0; row<x; row++)
    {
        if(arr[row][y] == 1)
        {
            return false ;
        }
    }

    // check upper-left diagonal
    int row=x, col=y ;
    while(row >= 0 && col >= 0)
    {
        if(arr[row][col] == 1)
        {
            return false ;
        }
        row-- ;
        col-- ;
    }

    // check upper-right diagonal
    row=x, col=y ;
    while(row >=0 && col < n)
    {
        if(arr[row][col] == 1)
        {
            return false ;
        }
        row-- ;
        col++ ;
    }

    return true ;
}


bool nqueen(int** arr, int x, int n)
{
    if(x >= n)   // all queens are placed
    return true ;

    // try placing queen in each column of the current row
    for(int col=0; col<n; col++)
    {
        if(isSafe(arr,x,col,n))
        {
            arr[x][col] = 1 ; // place queen

            if(nqueen(arr,x+1,n)) 
            {
                return true ;
            }
        }

        arr[x][col] = 0 ; // backtrack
    }

    return false ;
}

int main()
{
    int n ;
    cout<<"Enter the number of queens to be placed: "<<endl ;
    cin>>n ;

    // create a 2D array (n*n) filled with 0
    int** arr = new int*[n] ;
    for(int i=0; i<n; i++)
    {
        arr[i] = new int[n] ;
        for(int j=0; j<n; j++)
        {
            arr[i][j] = 0 ;
        }
    }

    // call the function
    if(nqueen(arr,0,n))
    {
        // print the board
        cout<<"one valid solution: "<<endl ;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(arr[i][j] == 1)
                {
                    cout<<"Q " ;
                }
                else{
                    cout<<". " ;
                }
            }
            cout<<endl ;
        }
    }

    else{
        cout<<"No solution found" ;
    }

    return 0 ;
}
