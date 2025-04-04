// #include<iostream>
// using namespace std ;

// int peek(int arr[], int n)
// {
//     // base case
//     if(n==0)
//     return -1 ;

//     if(n==1)
//     return arr[0] ;

//     if(arr[0] > arr[1])
//     return arr[0] ;

//     if(arr[n-1] > arr[n-2])
//     return arr[n-1] ;

//         for(int i=1;i<n-1;i++)
//         {
//             if(arr[i]> arr[i-1] && arr[i] > arr[i+1])
//             {
//                 return arr[i] ;
//             }
//         }
//     return -1 ; // not found
    
// }

// int main()
// {
//     int arr[] = {1,2,3,4,5,6,10,9};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     int res = peek(arr,n);
//     cout<<"Peek element = "<<res<<endl ;

//     return 0 ;
// }










#include<iostream>
using namespace std ;

int peek(int arr[], int n, int s, int e)
{
    int mid = s + (e-s)/2 ;

     // Check if mid is a peak
    if ((mid == 0 || arr[mid] >= arr[mid - 1]) && 
        (mid == n - 1 || arr[mid] >= arr[mid + 1])) 
    {
        return arr[mid];
    }

    if(arr[mid] < arr[mid-1]) // if left neighbor is greater, search left
    {
        return peek(arr,n,s,mid-1) ;
    }
    if(arr[mid] < arr[mid+1]) // if right neighbor is greater, then search right
    {
        return peek(arr,n,mid+1,e) ; 
    }
}

int main()
{
    int arr[] = {10, 14, 15, 2, 23, 90, 67};
    int n = sizeof(arr)/sizeof(arr[0]);

    int res = peek(arr,n,0,n-1);
    cout<<"Peek element = "<<res<<endl ;

    return 0 ;
}

