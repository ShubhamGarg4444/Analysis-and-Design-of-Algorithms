#include<bits/stdc++.h>
using namespace std ;

bool isSafe(vector<int> &weight, int m, int n, int ci, int i, vector<int> &ans)
{
    // check the bounding condition
    // check that including k itens and the next item sum would not exceed m

    int ws = 0 ;
    for(int k=0; k<n; k++)
    {
        if(ans[k] == 1)
        {
            ws += weight[k] ;
        }
    }

    if(i-1 >=0 && i-1 < n)
    {
        ws += weight[i-1] ;
    }

    if(ws > m)
    return false ;

    return true ;
}

bool sumSubsets(vector<int> &weight, int m, int n, int ci, vector<int> &ans)
{
    // basically mai current index(ci) pr hun, ab mujhe dekhna hai ki mai iss index ki item ko include kru ya nhi
    // weight represents the vector elements
    // n is size of weight vector (or number of items)
    // m is the total sum which is given
    // ans is vector which stores that item is included or not (1 - included, 0 - not included)


    if(ci > n)  // 1-based indexing
    {   
        // check if the current subset forms the exact sum m.
        int total = 0 ;
        for(int k=0; k<n; k++)
        {
            if(ans[k] == 1)
            total += weight[k] ;
        }

        return (total == m) ;
    }


    // Include current element
    if(isSafe(weight,m,n,ci,ci,ans))
    {
        ans[ci-1] = 1 ;

        if(sumSubsets(weight,m,n,ci+1,ans))
        {
            return true ;
        }

        ans[ci-1] = 0 ; // backtrack
    }


    // exclude current item
    ans[ci-1] = 0 ;
    if(sumSubsets(weight,m,n,ci+1,ans))
    {
        return true ;
    }

    return false ;
}

int main()
{
    vector<int> weight = {5,10,12,13,15,18} ;
    int m = 30, n = weight.size() ;

    vector<int> ans(n,0) ;

    if(sumSubsets(weight,m,n,1,ans))
    {
        cout<<"1 means item included, 0 means item not included"<<endl ;
        cout<<"One valid solution: "<<endl ;
        for(int i=0; i<ans.size(); i++)
        {
            cout<<ans[i]<<" " ;
        }
        cout<<endl ;
    }
    else{
        cout<<"No solution exist"<<endl ;
    }

    return 0 ;
}