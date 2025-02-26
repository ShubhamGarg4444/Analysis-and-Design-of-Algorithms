#include<iostream>
using namespace std ;

void merge(int arr[], int n, int s, int e, int mid)
{
    int len1 = mid-s+1 ;
    int len2 = e-mid ;

    int* left = new int[len1] ;
    int* right = new int[len2] ;

    for(int i=0;i<len1;i++)
    {
        left[i] = arr[s+i] ;
    }

    for(int i=0;i<len2;i++)
    {
        right[i] = arr[mid+1+i] ;
    }

    int i=0, j=0, k=s ;
    while(i<len1 && j<len2)
    {
        if(left[i] <= right[j])
        {
            arr[k] = left[i] ;
            i++ ;
            k++ ;
        }
        else{
            arr[k] = right[j] ;
            j++ ;
            k++ ;
        }
    }
    while(i<len1)
    {
        arr[k] = left[i] ;
        i++ ;
        k++ ;
    }
    while(j<len2)
    {
        arr[k] = right[j] ;
        j++ ;
        k++ ;
    }
    delete[] left;  // Free allocated memory
    delete[] right;
}

void mergeSort(int arr[], int n, int s, int e)
{
    if(s>=e) return ;

    int mid = s + (e-s)/2 ;
    mergeSort(arr, n, s, mid) ;
    mergeSort(arr, n, mid+1, e) ;

    merge(arr,n,s,e,mid) ;
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;
    mergeSort(arr, n, 0, n-1) ;
    cout << "Sorted array is \n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}