//
// Created by niubin on 17-9-27.
//
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.empty()&&needle.empty()){
            return 0;
        }
        if(haystack.empty()&&!needle.empty()){
            return -1;
        }
        if(needle.empty()&&!haystack.empty()){
            return 0;
        }
        int len1=haystack.length();
        int len2=needle.length();
        if(len2>len1)
            return  -1;
        int i=0;
        int j=0;
        while(i<len1&&j<len2){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }else{
                i=i-j+1;
                j=0;
            }

        }
        if(j==len2){

            return i-j;
        }
        else{
            return -1;
        }
    }
};
int main(){
    Solution solution;
    cout<<solution.strStr("mississippi","issip");
}