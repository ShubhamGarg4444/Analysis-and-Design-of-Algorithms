// A Magic Square is a n x n matrix of the distinct elements from 1 to n2 where the sum of any row, column, or diagonal is always equal to the same number.

#include <iostream>
#include <vector>
using namespace std;

bool isMagicSquare(vector<vector<int>>& grid) 
{
    int n = grid.size(); // square matrix

    if (n == 0) 
    return false; 

    int sum1 = 0, sum2 = 0;

    // Sum of primary diagonal
    for (int i = 0; i < n; i++)
        sum1 += grid[i][i];

    // Sum of secondary diagonal
    for (int i = 0; i < n; i++)
        sum2 += grid[i][n - i - 1];

    if (sum1 != sum2)
        return false;

    // Checking rows and columns
    for (int i = 0; i < n; i++) 
    {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < n; j++) 
        {
            rowSum += grid[i][j];
            colSum += grid[j][i];
        }
        if (rowSum != sum1 || colSum != sum1 || rowSum != colSum)
        return false;
    }

    return true;
}

int main() {
    vector<vector<int>> grid = {
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8}
    };

    if (isMagicSquare(grid))
        cout << "Magic Square" << endl;
    else
        cout << "Not a Magic Square" << endl;

    return 0;
}
