//
// Created by niubin on 17-9-18.
//
//
//http://www.cnblogs.com/theskulls/p/5131947.html
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int index=0;
        int size=strs.size();
        if(size == 0) {
            return "";
        }
        //TODO reference binding to null pointer of type ‘struct value_type’
        std::cout<<strs[0].substr(0,0)<<'\n';
        int len=strs[0].size();

        for(int i=0;i<len;i++){
            for(int j=1;j<size;j++){
                if(strs[j][i]=='\0'){
                    return strs[0].substr(0,i);
                }
                if(strs[0].substr(0,i+1)!=strs[j].substr(0,i+1)){
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }

};
int main(){
    Solution solution;
    vector<string>strs{"aaa","aab"};
    cout<<solution.longestCommonPrefix(strs);
}