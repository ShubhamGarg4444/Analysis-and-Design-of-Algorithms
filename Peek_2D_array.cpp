#include<iostream>
#include<vector>
using namespace std ;

int peek(vector<vector<int>> grid)
{
    int leftcol = 0 ; // starting index of column
    int rightcol = grid[0].size() - 1 ; // last index of column

    int midcol = leftcol + (rightcol-leftcol)/2 ; // middle column index
    int maxrow = 0 ; // row index of maximum element find at mid column

    for(int i=0;i<grid.size();i++)
    {
        if(grid[i][midcol] > grid[maxrow][midcol])
        {
            maxrow = i ;
        }
    }

    bool leftbig = (midcol > 0) && (grid[maxrow][midcol-1] > grid[maxrow][midcol]) ; // search space is left
    bool rightbig = (midcol < grid[maxrow][rightcol]) && (grid[maxrow][midcol+1] > grid[maxrow][midcol]) ; // search space is right

    if(!leftbig && !rightbig) // we are at peek element
    {
        return grid[maxrow][midcol] ;
    }
    if(rightbig)
    {
        leftcol = midcol+1 ; // move the search space in right
    }
    else{
        rightcol = midcol-1 ; // move the search space in left
    }
}

int main() {
    vector<vector<int>> arr = {{9, 8}, {2, 6}} ;

    int result = peek(arr) ;
    cout << "Peak element found : " << result << endl ;
    return 0 ;
}