#include<iostream>
using namespace std ;

int power(int n, int k)
{
    if(k==0)
    return 1 ;

    return n*power(n,k-1) ;
}

int main()
{
    int n = 2 ;
    int k = 3 ;
    int res = power(n,k) ;

    cout<<res<<endl ;

    return 0 ;
}