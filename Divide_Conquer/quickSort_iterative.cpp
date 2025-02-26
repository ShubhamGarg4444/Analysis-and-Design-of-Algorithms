#include <iostream>
#include <stack>
using namespace std;

int partition(int arr[], int s, int e)
{
    int start = s ;
    int end = e ;
    int pivot = s ; 

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

void quickSort(int arr[], int n) {
    stack<int> st;
    int s = 0, e = n - 1;

    st.push(s);
    st.push(e);

    while (!st.empty()) {
        e = st.top(); 
        st.pop();
        s = st.top(); 
        st.pop();

        int p = partition(arr, s, e);

        if (p - 1 > s) { // Left side
            st.push(s);
            st.push(p - 1);
        }

        if (p + 1 < e) { // Right side
            st.push(p + 1);
            st.push(e);
        }
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, n);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
