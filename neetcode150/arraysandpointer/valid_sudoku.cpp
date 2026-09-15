#include<bits/stdc++.h>
using namespace std; 


// Approach 1 : Think is rows and cols. Need to logically divide the array into small 3x3 cubes 
// Three layer of validation - row, col and 3x3 cube
bool isValidSudoku_old(vector<vector<char>>& board) {
    set<pair<int, char>> col; // IMP pair : Userd when we need a pair value as set.

    // For the sub boxes, we are going to store the quadrant number and its respective set.
    unordered_map<int, unordered_set<char>> quad; 

    for (int i=0; i<9; i++) {
        unordered_set<char> row;
        for (int j=0; j<9; j++) {
            // row level checking
            if (row.find(board[i][j]) != row.end()) {
                return false; // duplicate element found
            }

            if (board[i][j] != '.') {
                row.insert(board[i][j]);
            }

            // For column level j will remain constant for each column, so we need to check within a set a combination of j and the element. 
            if (col.find({j, board[i][j]}) != col.end())  {
                // same element found in column
                return false;
            }

            if (board[i][j] != '.') {
                col.insert({j, board[i][j]});
            }

            // how to determine the quad number - (i/3) gives the row group, multiplying by 3 gives the starting position so we can calculate col offset by using (j/3).  
            // IMP : Catch of the problem.
            int box_number = (i/3) * 3 + (j/3);

            if (quad.find(box_number) != quad.end()) {
                if (quad[box_number].find(board[i][j]) != quad[box_number].end()) {
                    // eleement found in same quadrant 
                    return false;
                }
            }

            if (board[i][j] != '.') {
                quad[box_number].insert(board[i][j]);
            }

        }
    }

    return true;
}

// Practice
bool isValidSudoku(vector<vector<char>>& board) {
    set<pair<int, char>> col;
    unordered_map<int, unordered_set<char>> quad;

    for (int i =0 ; i<9; i++) {
        unordered_set<char> row; 
        for (int j = 0; j<9; j++) {
            
            // for row
            if (row.find(board[i][j]) != row.end())
                return false;

            if (board[i][j] != '.') row.insert(board[i][j]);
            
            // for col
            if (col.find({j, board[i][j]}) != col.end()) return false;
            
            if (board[i][j] != '.') col.insert({j, board[i][j]});
            
            // for quad 
            int box = (i/3) * 3 + (j/3);
            if (quad.find(box) != quad.end()) {
                if (quad[box].find(board[i][j]) != quad[box].end()) { 
                    return false;
                }
            }
            
            if (board[i][j] != '.') quad[box].insert(board[i][j]);
        }
    }

    return true;
}


int main() { 
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    bool ans = isValidSudoku(board);
    cout << ans << endl;
}