#include<iostream>
using namespace std ;

int factorial(int n)
{
    if(n==0 || n==1)
    return 1 ;

    return n * factorial(n-1) ;
}

int main()
{
    int n= 5 ;
    int r = 2 ;

    int res = factorial(n)/factorial(n-r) ;

    cout<<"Permutation is = "<<res<<endl;

    return 0 ;
}