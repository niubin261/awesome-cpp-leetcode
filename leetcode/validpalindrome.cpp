//
// Created by niubin on 18-1-30.
//
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        if(len == 0)return true;
        s = clean(s);
        len = s.length();
        int i = 0;
        int j = len - 1;
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            else {
                i++;
                j--;
            }
        }
        return true;
    }
private:
    string clean(string s){
        string result="";
        int len=s.length();

        for(int i=0;i<len;i++){
            if(isalpha(s[i])){
                if(islower(s[i])){
                    result+=s[i];
                }
                if(isupper(s[i])){
                    string temp(1,s[i]+32);
                    result+=temp;
                }

            }
            if (isdigit(s[i])){
                result+=s[i];
            }

        }
        return result;
    }



};
int main(){
    Solution solution;
    string s = "0p";
    cout<<solution.isPalindrome(s);
}