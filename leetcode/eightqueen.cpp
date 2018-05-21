//
// Created by niubin on 18-1-3.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(size_t n) {

        vector<vector<string>> results;
        string s(n, '.');
        cout << s << endl;
        vector<string> chess{n, s};
        backTrack(results, chess, 0, n);
        return results;

    }

private:
    void backTrack(vector<vector<string>> &results, vector<string> &chess, size_t row, size_t n) {
        if (row == n) {
            return results.push_back(chess);
        }
        for (size_t i = 0; i < n; i++) {
            if (isOK(chess, row, i, n)) {
                chess[row][i] = 'Q';
                backTrack(results, chess, row + 1, n);
                chess[row][i] = '.';

            }

        }


    }

private:
    bool isOK(vector<string> &chess, int row, int col, int n) {

        for (int i = 0; i < row; i++) {
            if (chess[i][col] == 'Q')
                return false;
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < n; j++) {
                if (abs(col - j) == abs(row - i) && chess[i][j] == 'Q') {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<vector<string>> result = solution.solveNQueens(8);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
        }
        cout << endl;

    }


}
