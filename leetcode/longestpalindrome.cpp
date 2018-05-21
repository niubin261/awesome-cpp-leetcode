//
// Created by niubin on 17-10-7.
//
#include <string>
#include <iostream>
#include <cstring>

using namespace std;
class Solution {
public:
    string _longestPalindrome(string s) {
        unsigned long len=s.length();
        unsigned long lenTmp=0;
        string sTmp="";
        string result="";
        for(int i=0;i<len;i++){
            for(int j=1;i+j<=len;j++){
                sTmp=s.substr(i,j);
                if(isPalindrome(sTmp)){
                    if(sTmp.length()>lenTmp){
                        lenTmp=sTmp.length();
                        result=sTmp;
                    }
                }
            }
        }
        return result;
    }

private:
    bool isPalindrome(string s){
        unsigned long len=s.length();
        for(int i=0;i<len;i++){
            if(s[i]==s[len-i-1]){

            }else{
                return false;
            }
        }
        return true;

    }
//
public:
    string longestPalindrome(string s){
        if(s.empty())return NULL;
        size_t  len=s.length();
        bool dp[len][len];
        memset(dp,0,sizeof(dp));
        size_t resultLen=1;
        size_t start=0;
        dp[0][0]=1;
        for(int i=1;i<len;i++){
            dp[i][i]=1;

        }
        for(size_t i=0;i<len;i++){
            for(size_t j=0;j<i;j++){
                if(i-j==1&&s[i]==s[j]){
                    dp[j][i]=1;
                }
                if(s[i]==s[j]&&dp[j+1][i-1]==1&&i-j>1){
                    dp[j][i]=1;
                }
                if(dp[j][i]==1){
                    if(resultLen<i-j+1){
                        resultLen=i-j+1;
                        start=j;
                    }
                }
            }
        }
        return s.substr(start,resultLen);
    }
};
int main(){
    Solution solution;
    cout<<solution.longestPalindrome("abcba");

}