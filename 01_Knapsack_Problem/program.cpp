#include<bits/stdc++.h>
using namespace std ;

int knp(int p[], int w[], int W, int n)
{
    // p[] is profit array
    // w[] is weight array
    // W is total weight of knapsack
    // n is number of items

    int K[n+1][W+1]; // final 2D matrix 

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=W; j++)
        {
            if(i == 0 || j == 0)
            {
                K[i][j] = 0 ;
            }

            else if(w[i-1] <= j)
            {
                K[i][j] = max(p[i-1] + K[i-1][j-w[i-1]], K[i-1][j]) ;
            }

            else
            {
                K[i][j] = K[i-1][j] ;
            }
        }
    }
    return K[n][W] ;
}

int main()
{
    int p[] = {2,3,4,1} ;
    int w[] = {3,4,5,6} ; // weights must be in ascending order

    int W = 8 ; 
    int n = 4 ;

    int maxProfit = knp(p,w,W,n) ;

    cout<<"Maximum profit earned = "<<maxProfit<<endl;

    return 0 ;
}