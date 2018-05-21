//
// Created by niubin on 17-11-27.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        return dfs(0,0,m,n);
    }

private:
    int dfs(int posRow,int posCol,int m,int n){
        if(posCol==n-1&&posRow==m-1){
            return 1;
        }
        if(posCol>n-1||posRow>m-1){
            return 0;
        }
        return dfs(posRow+1,posCol,m,n)+dfs(posRow,posCol+1,m,n);
    }

public:
    int __uniquePaths(int m,int n){
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        for(int j=0;j<n;j++){
            dp[0][j]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];

    }
};
int main(){
    Solution solution;
    std::cout<<solution.__uniquePaths(2,2);
}