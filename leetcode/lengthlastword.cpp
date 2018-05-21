//
// Created by niubin on 17-10-23.
//
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty())return 0;
        int len=s.length();
        if(len==0)return 0;
        while(len>=0&&s[--len]==' '){}
        int i=len;
        while(s[i]!=' '&&i>=0){
            i--;
        }
        return len-i;

    }
};
int main(){
    Solution solution;
    cout<<solution.lengthOfLastWord("a ip ");
}