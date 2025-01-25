#include<iostream>
#include<chrono>
#include <vector>
#include <cstdlib> // for rand()
using namespace std;
using namespace std::chrono;

int partition(vector<int> &arr, int s, int e)
{
    int start = s ;
    int end = e ;
    int pivot = arr[s] ;

    while(start <= end)
    {
        while(arr[start] <= pivot)
        {
            start++ ;
        }
        while(arr[end] > pivot)
        {
            end-- ;
        }
        if(start < end)
        {
            swap(arr[start], arr[end]) ;
        }
    }
    swap(arr[s], arr[end]) ;
    return end ; // return the pivot index
}

void quickSort(vector<int> &arr,int s, int e)
{
    if(s>=e)
    return ;

    int p = partition(arr,s,e) ;
    quickSort(arr,s,p-1) ;
    quickSort(arr,p+1,e) ;
}

int main()
{
    int n = 1000 ;
    while(n <= 10000)
    {
    long long total_time = 0; // Store time in microseconds

    for(int i=1;i<10;i++)
    {
        // step 1 - generate a random array of size n
        vector<int> arr(n) ;
        for(int j=0;j<n;j++)
        {
            arr[j] = rand();
        }

        // measure the start time
        auto start_time = high_resolution_clock::now();

        // step 2 - sort the array using quick sort -- for avg case
        quickSort(arr,0,n-1) ;

        // measure the final time 
        auto end_time = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(end_time - start_time).count();

        total_time += duration;
    }
    double avg_time = total_time / 10.0 / 1000.0;

    // print - showing n on x-axis and avg_time on y-axis

    cout << "Size of array: " << n << " | Avg Time (ms): " << avg_time << endl;

    n+=1000 ;
    }
    return 0; 
}


