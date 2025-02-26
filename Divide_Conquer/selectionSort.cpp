#include<iostream>
using namespace std ;

void SS(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int mini = i ;

        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < arr[mini])
            {
                mini = j ;
            }
        }
        swap(arr[i], arr[mini]) ;
    }
}

void print(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" " ;
    }
    cout<<endl;
}

int main()
{
    int arr[6] = {2,6,1,9,4,0} ;
    SS(arr,6) ;
    print(arr,6) ;

    return 0 ;
}
























