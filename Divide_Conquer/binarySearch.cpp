#include<iostream>
using namespace std ;

bool binarySearch(int arr[], int n, int key, int s, int e)
{
    if (s > e) return false; // Base case: element not found

    int mid = s + (e-s)/2 ;
    
    if(key == arr[mid]) return true ;

    if(key < arr[mid])
    {
        return binarySearch(arr, n, key, s, mid-1) ;
    }

    if(key > arr[mid])
    {
        return binarySearch(arr, n, key, mid+1, e) ;
    }
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;
    int key = 10 ;
    bool ans = binarySearch(arr,n,key,0,n-1) ;

    if(ans)
    {
        cout<<"Element found"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }

    return 0 ;
}