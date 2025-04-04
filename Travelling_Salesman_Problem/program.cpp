#include<bits/stdc++.h>
using namespace std ;

const int INF = 1e9 ;
int n ;
vector<vector<int>> dist ;
map<pair<int, set<int>>, int> memo ; // memoization table
// i - current city
// set<int> - stores the unvisited set of cities
// map value - stores the minimum cost of visiting all cities in S starting from city i.

int g(int i, set<int>S)
{
    // i is source city 
    // S contains the cities which is to be visited (excluding source city)

    // base case : if all cities are visited, means S becomes empty and we have to return to starting city, then return cost to return home
    if(S.empty()) return dist[i][0] ;

    // if result (means cost) is stored, return it
    if(memo.find({i,S}) != memo.end()) return memo[{i,S}] ;

    int minCost = INF ;  

    // visit all cities which are in S
    for(int j : S)
    {
        set<int> newS = S ;
        newS.erase(j) ;

        minCost = min(minCost, dist[i][j] + g(j,newS)) ;
    }

    return memo[{i,S}] = minCost ;
}

int main() {
    n = 4; // Number of cities

    dist = {
        {0, 16, 11, 6},
        {8, 0, 13, 16},
        {4, 7, 0, 9},
        {5, 12, 2, 0}
    };

    // Set of all cities except the starting one (0)
    set<int> S = {1, 2, 3};

    // Solve TSP starting from city 0
    int minCost = g(0, S);

    cout << "Minimum cost of Travelling Salesman Tour = " << minCost << endl;
    return 0;
}
