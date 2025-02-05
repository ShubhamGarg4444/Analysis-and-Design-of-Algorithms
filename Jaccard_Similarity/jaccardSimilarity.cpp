// The Jaccard similarity measures the similarity between two sets of data to see which members are shared and distinct. 
// The Jaccard similarity is calculated by dividing the number of observations in both sets by the number of observations in either set. 
// In other words, the Jaccard similarity can be computed as the size of the intersection divided by the size of the union of two sets.


#include <bits/stdc++.h>
using namespace std ;
void jaccard(vector<int> arr1, vector<int> arr2)
{
    int len1 = arr1.size() ;
    int len2 = arr2.size() ;

    int intersect = 0 ;
    int uni = 0 ;

    for(int i=0;i<len1;i++)
    {
        for(int j=0;j<len2;j++)
        {
            if(arr1[i] == arr2[j])
            {
                intersect++ ;
            }
        }
    }

    uni = len1 + len2 - intersect ;

    cout<<"Jaccard coefficient of similarity = "<<(double)intersect/uni<<endl ;
}

int main()
{
    vector<int> arr1 = {0,1,2,5,6} ;
    vector<int> arr2 = {0,2,3,4,5,7,9} ;

    jaccard(arr1,arr2) ;

    return 0 ;
}







