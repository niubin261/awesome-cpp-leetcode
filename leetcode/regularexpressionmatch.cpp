//
// Created by niubin on 17-10-23.
//

/*'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true*/
#include<string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())return s.empty();
        if(p.size()==1&&s.size()==1){
            if(p[0]==s[0]||p[0]=='.')
                return true;
        }
        if(p[1]!='*'){
            if(s.empty())return false;
            if(p[0]==s[0]||p[0]=='.')
                return isMatch(p.substr(1),s.substr(1));
        }
        if(p[1]=='*'){
            while(s.empty()||p[0]==s[0]||p[0]=='.'){
                if(isMatch(s,p.substr(2)))
                    return true;
                s=s.substr(1);

            }
            return isMatch(s,p.substr(2));
        }


    }
private :
    bool match(char a,char b){
        return a == b ||(a == '.' || b == '.');

    }
};
int main(){
    Solution solution;
    std::cout<<solution.isMatch("aaab","a*b");
}