#include<iostream>
using namespace std ;

int partition(int arr[], int n, int s, int e)
{
    int start = s ;
    int end = e ;
    int pivot = s ; // Choosing the first element as pivot

    while(start <= end)
    {
        while(arr[start] <= arr[pivot])
        {
            start++ ;
        }
        while(arr[end] > arr[pivot])
        {
            end-- ;
        }
        if(start < end)
        {
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[s], arr[end]) ;
    return end ; // returning pivot index
}

void quickSort(int arr[], int n, int s, int e)
{
    if(s>=e) return ;

    int p = partition(arr,n,s,e) ;
    quickSort(arr,n,s,p-1) ;
    quickSort(arr,n,p+1,e) ;
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, n, 0, n-1);
    cout << "Sorted array is: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" " ;
    }
    cout<<endl ;
    return 0;
}








