#include<iostream>
using namespace std ;

int Sum(int arr[], int n)
{
    if(n==0)
    return 0 ;

    return arr[n-1] + Sum(arr,n-1) ; 
}

int main()
{
    int arr[] = {1,2,4,5,8} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;
    int res = Sum(arr,n) ;

    cout<< "sum = "<<res<<endl;

    return 0 ;
}

