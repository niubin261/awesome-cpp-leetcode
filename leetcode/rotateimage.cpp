//
// Created by niubin on 18-2-1.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>reault(n,vector<int>(10,0));
        if(n == 0)return ;
        for(int i = 0;i < n;i ++ ){
            for (int j = 0;j< n;j ++){
                reault[i][j] = matrix[j][n - 1 - i];
            }
        }
        matrix = reault;
    }
};
int main(){
    vector<vector<int>>matrix {{1,2,3},{4,5,6},{7,8,9}};
    Solution solution;
    solution.rotate(matrix);
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            cout<<matrix[i][j];
        }
    }
}