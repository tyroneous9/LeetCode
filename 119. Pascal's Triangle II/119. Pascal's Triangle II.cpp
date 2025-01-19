// 119. Pascal's Triangle II.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
Example 1:
Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:
Input: rowIndex = 0
Output: [1]

Example 3:
Input: rowIndex = 1
Output: [1,1]
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> getNextRow(vector<int>& row) {
    vector<int> next(row.size() + 1);
    next[0] = 1;
    for (int i = 1; i < row.size(); i++) {
        next[i] = row[i] + row[i - 1];
    }
    next[row.size()] = 1;
    return next;
}

vector<int> getRow(int rowIndex) {
    vector<int> row;
    for (int i = -1; i < rowIndex; i++) {
        row = getNextRow(row);
    }
    return row;
}


int main()
{
    vector<int> triangle = getRow(1);

    for (int n : triangle) {
        cout << n << " ";
    }
}
