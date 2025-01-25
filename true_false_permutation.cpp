#include<iostream>
#include<vector>
using namespace std ;

void generateTF(vector<bool> &com, int n, int index)
{
   if(index == n)
   {
    for(bool i : com)
    {
        cout<<i<<" " ;  // 0 for false and 1 for true
    }
    cout<<endl ;
    return ;
   }
 
   com[index] = false ;
   generateTF(com,n,index+1) ;

   com[index] = true ;
   generateTF(com,n,index+1) ;
}

int main()
{
    int n ;
    cout<<"Enter the number of elements : ";
    cin>>n ;

    vector<bool> com(n) ;
    generateTF(com,n,0) ;

    return 0 ;
}