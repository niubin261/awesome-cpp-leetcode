//
// Created by niubin on 17-10-4.
//
#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>vecStr;
        for(int i=0;i<numRows;i++){
            vecStr.push_back("");
        }
        string result="";
        int len = s.length();
        int i=0;
        while(i<len){
            for(int j=0;j<numRows&&i<len;j++){
                vecStr[j].push_back(s[i]);
                i++;
            }
            for(int k=numRows-2;k>0&&i<len;k--){
                vecStr[k].push_back(s[i]);
                i++;
            }
        }
        for(int i=0;i<vecStr.size();i++){
            result+=vecStr[i];
        }
        return result;

    }
};
int main(){
    Solution solution;
    cout<<solution.convert("",3);
}