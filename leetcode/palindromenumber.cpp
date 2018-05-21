//
// Created by niubin on 17-9-17.
//
#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {//no space allowed
        if(x<0){
            return false;
        }
        long long alpha=x;
        long long result=0;//must long long
        while(x!=0){
            result=result*10+x%10;
            x=x/10;
        }
        cout<<result;
        return  (result==alpha);
    }
};
int main(){
    Solution solution;
    cout<<solution.isPalindrome(-2147447412);
    return 0;
};