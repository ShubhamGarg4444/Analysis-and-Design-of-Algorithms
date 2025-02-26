#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> matrixMultiply(vector<vector<int>> first, vector<vector<int>> second)
{
    int fr = first.size() ;
    int fc = first[0].size() ;

    int sr = second.size() ;
    int sc = second[0].size() ;

    if(fc != sr)
    {
        cout << "Matrices cannot be multiplied" << endl;
        return {};
    }

    vector<vector<int>> result(fr, vector<int>(sc, 0));

    for(int i=0;i<fr;i++)
    {
        for(int j=0;j<sc;j++)
        {
            int sum = 0 ;
            for(int k=0;k<fc;k++)
            {
                sum += first[i][k] * second[k][j] ;
            }
            result[i][j] = sum ;
        }
    }

    return result ;
}

void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> first = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> second = {{7, 8}, {9, 10}, {11, 12}};

    vector<vector<int>> result = matrixMultiply(first, second);

    if (!result.empty())
    {
        cout << "Resulting Matrix:\n";
        printMatrix(result);
    }

    return 0;
}

















