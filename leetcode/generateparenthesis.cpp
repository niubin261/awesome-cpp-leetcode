//
// Created by niubin on 17-10-13.
//


//[
//"((()))",
//"(()())",
//"(())()",
//"()(())",
//"()()()"
//]
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ret;
        dfsSearch(ret,n,0,0,"");
        return ret;
    }

private:
    void dfsSearch(vector<string>&ret,int n,int left,int right,string result){
        if(left==n){
            result.append(n - right, ')');
            ret.push_back( result);
            return;
        }
        if(left<n){
            dfsSearch(ret,n,left+1,right,result+"(");
        }
        if(left>right){
            dfsSearch(ret,n,left,right+1,result+")");
        }

    }
};
int main(){
        Solution s;
        vector<string>ret=s.generateParenthesis(3);
    for(int i=0;i<ret.size();i++){
        cout<<ret[i]<<'\n';
    }
};