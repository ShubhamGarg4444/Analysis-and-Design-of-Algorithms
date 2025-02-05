// Cosine similarity is a way to measure how similar two vectors are by calculating the cosine of the angle between them. 
// It's a key concept in data science and machine learning.

#include <bits/stdc++.h>
using namespace std ;

int computeDotProduct(map<string,int> &same1, map<string,int> &same2)
{
    int res = 0 ;
    for(const auto &entry : same1)
    {
        string word1 = entry.first ;
        int count1 = entry.second ;

        if(same2.find(word1) != same2.end())
        {
           int count2 = same2[word1] ;
           res += count1 * count2 ;
        }
    }

    return res ;
}

int computeMagnitude(map<string,int> &same)
{
    int sum = 0 ;
    for(const auto &entry : same)
    {
        int count = entry.second ;
        sum += count * count ;
    }
    return sum ;
}

void cosineSim()
{
    ifstream f1("file1.txt") ;
    ifstream f2("file2.txt") ;

    string first, second, line1, line2 ;
    while(getline(f1, line1))
    {
       first.append(line1) ;
       first.append(" ");  // Added space to separate words
    }
    while(getline(f2, line2))
    {
        second.append(line2) ;
        second.append(" ");  // Added space to separate words
    }

    f1.close() ;
    f2.close() ;

    vector<string> stock = {"is","am","are","or","and","for","so","by","to","a","do","can","will","we","us","at","of",",","."} ;

    unordered_set<string> stockSet(stock.begin(), stock.end());

    map<string,int> same1 ;
    map<string,int> same2 ;

    stringstream ss1(first), ss2(second); // used a stringstream to extract words properly
    string word;

    while (ss1 >> word)   // Extract words from first string
    {
        if (stockSet.find(word) == stockSet.end()) 
        {
            same1[word]++ ;  // Correctly count occurrences of each word
        }
    }

    while (ss2 >> word)   // Extract words from second string
    {
        if (stockSet.find(word) == stockSet.end()) 
        {
            same2[word]++ ;
        }
    }

    int res = computeDotProduct(same1, same2) ;
    int mag1 = computeMagnitude(same1) ;
    int mag2 = computeMagnitude(same2) ;

    // jitni jyada cos theta ki value hogi, utni jyada similarity hogi files mai
    double cosine = (mag1 == 0 || mag2 == 0) ? 0.0 : (double)res / (sqrt(mag1) * sqrt(mag2)) ;

    cout << "answer of cos theta = " << cosine << endl ;
}

int main()
{
    cosineSim();
    return 0;
}

