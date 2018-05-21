//
// Created by niubin on 17-10-4.
//
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {

        if(n<1)return "";
        if(n==1)return "1";
        string s="1";
        for(int i=0;i<n-1;i++){
            int alpha=1;//chu xian de ci shu
            int beta=0;// shi ji
            string tmpstr;
            char currentChar=s[0];
            s.push_back('*');
            for(int i=1;i<s.size();i++){
                if(currentChar==s[i]){
                    alpha++;

                }else{
                    tmpstr+=to_string(alpha);
                    tmpstr.push_back(currentChar);
                    currentChar=s[i];
                    alpha=1;
                }
            }
            s=tmpstr;

        }
        return s;
    }
};
int main(){
    Solution solution;
    cout<<solution.countAndSay(2);
}