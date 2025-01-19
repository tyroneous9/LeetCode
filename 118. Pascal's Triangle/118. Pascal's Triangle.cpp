

#include <iostream>
#include <vector>
using namespace std;

/*
Given an integer numRows, return the first numRows of Pascal's triangle.
Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
*/

vector<int> getNextRow(vector<int>& row) {
    vector<int> next(row.size() + 1);
    next[0] = 1;
    for (int i = 1; i < row.size(); i++) {
        next[i] = row[i] + row[i - 1];
    }
    next[row.size()] = 1;
    return next;
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle(numRows);
    vector<int> row;
    for (int i = 0; i < numRows; i++) {
        row = getNextRow(row);
        triangle[i] = row;

    }
    return triangle;
}


int main()
{
    vector<vector<int>> triangle = generate(1);
    
    for (vector<int> v : triangle) {
        cout << 1;
    }
}