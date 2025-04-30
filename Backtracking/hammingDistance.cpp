// C++ program to find hamming distance b/w two string 
#include<bits/stdc++.h>
using namespace std ;

int hd(string num1, string num2)
{
    int len1 = num1.length() ;
    int len2 = num2.length() ;

    if(len1 < len2)
    {
        num1 = string(len2-len1, '0') + num1 ;
    }
    else if(len1 > len2)
    {
        num2 = string(len1-len2, '0') + num2 ;
    }
    
    cout<<"final strings (after padding are added or not): "<<endl ;
    cout<<num1<<endl<<num2<<endl ;

    int i=0, count=0 ;
    while(num1[i] != '\0')
    {
        if(num1[i] != num2[i])
        count++ ;

        i++ ;
    }

    return count ;
}

int main()
{
    string num1, num2 ;

    cout<<"enter two strings of numbers (in binary format): "<<endl ;
    cin>>num1>>num2 ;

    int res = hd(num1,num2) ;
    cout<<"Hamming distance between two strings: "<<res<<endl ;

    return 0 ;
}