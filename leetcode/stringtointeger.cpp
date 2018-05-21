//
// Created by niubin on 17-10-21.
//
#include <string>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int len=str.length();
        int sign=1;
        long long result=0;
        int i=0;
        while(str[i]==' '){
            i++;
        }
        if(str[i]=='-'){
            sign=-1;
            i++;
        }
        else if(str[i]=='+'){
            sign=1;
            i++;
        }else{}

        for(int j=i;j<len&&(str[j]>='0'&&str[j]<='9');j++){

            result=(result*10+(str[j]-'0'));

            if(sign==1&&result>=2147483648){
                return INT_MAX;
            }
            if(sign==-1&&result>2147483648){
                return INT_MIN;
            }
        }

        return result*sign;
    }
};
int main(){
    Solution solution;
    int result=solution.myAtoi("-9223372036854775809");
    cout<<result;
}