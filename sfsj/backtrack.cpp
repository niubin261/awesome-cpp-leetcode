//
// Created by niubin on 18-5-16.
//
#include <fstream>
#include <iostream>

using namespace std;


bool isOK(int **arr, int row, int col, int m, int n) {
    int k = arr[row][col];
    for (int i = 0; i < n && i != col; i++) {
        if (arr[row][i] == k) {
            return false;
        }
    }
    for (int i = 0; i < m && i != row; i++) {
        if (arr[i][col] == k) {
            return false;
        }
    }
    return true;
}

void backTrack(int **arr, int pos, int m, int n, int &result) {
    if (pos == m * n) {
        result = result + 1;
        return;
    }
    int row = pos / n;
    int col = pos % n;
    for (int i = 0; i < n; i++) {
        arr[row][col] = i;
        if (isOK(arr, row, col, m, n)) {
            pos++;
            backTrack(arr, pos, m, n, result);
            pos--;
        }
    }
}

int main() {
    ifstream in("input", ios::out | ios::in);
    int m, n;
    in >> m >> n;
//    m = 3;
//    n = 3;
    in.close();
    int result = 0;
    int **arr = new int *[m];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];

    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = -1;
        }
    }
    backTrack(arr, 0, m, n, result);
    cout << result;
    ofstream out("output", ios::in | ios::out);
    out << result;
    out.close();
}
