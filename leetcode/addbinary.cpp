//
// Created by niubin on 17-10-24.
//

/*
 * Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
 */
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int aInt=0;
        int bInt=0;
        int aLength=a.length();
        int bLength=b.length();
        for(int i=0;i<aLength;i++){
            aInt=aInt+(a[i]-'0')*pow(2,aLength-i-1);
        }
        for(int i=0;i<bLength;i++){
            bInt=bInt+(b[i]-'0')*pow(2,bLength-i-1);
        }
        int result=aInt+bInt;
        string resultString="0";
        int tmp=0;
        int pos=0;
        while(result){
            tmp=result%2;
            if(tmp==1){
                resultString.replace(pos,1,"1");
                pos++;
            }
            if(tmp==0){
                resultString.replace(pos,1,"0");
                pos++;
            }
            result=result/2;
        }
        reverse(resultString.begin(),resultString.end());
        return resultString;

    }
    string _addBinary(string a, string b){
        int aLen=a.length();
        int bLen=b.length();
        int len=max(aLen,bLen);
        string result;
        int carryBit=0;
        for(int i=0;i<len;i++){
            int tmp=0;
            if(i>=aLen){
               tmp=(b[bLen-i-1]-'0')+carryBit;
            }else if(i>=bLen){
                tmp=a[aLen-i-1]-'0'+carryBit;
            }else{
                tmp=(b[bLen-i-1]-'0')+carryBit+(a[aLen-i-1]-'0');
            }
            switch (tmp){
                case 0:
                    result.push_back('0');
                    carryBit=0;
                    break;
                case 1:
                    result.push_back('1');
                    carryBit=0;
                    break;
                case 2:
                    result.push_back('0');
                    carryBit=1;
                    break;
                case 3:
                    result.push_back('1');
                    carryBit=1;
                    break;
                default:
                    break;
            }
        }
        if(carryBit==1)
            result.push_back('1');

        reverse(result.begin(),result.end());
        return result;
    }
};
int main(){
    Solution solution;
    cout<<solution._addBinary("011","10");
}