//
// Created by niubin on 17-11-5.
//
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carryBit=1;
        vector<int>result{};
        int len=digits.size();
        int i=len-1;
        while(i>=0&&carryBit!=0){
           digits[i]=digits[i]+carryBit;
            if(digits[i]==10){
                digits[i]=0;
                carryBit=1;
            }else{

                carryBit=0;
            }
            i--;
        }
        if(carryBit==1){
            result.push_back(1);
            for(int i=0;i<len;i++){
                result.push_back(digits[i]);
            }

            return result;
        }
        else{
            return digits;
        }


    }
};
int main(){
    Solution solution;
    vector<int>digits{128};
    vector<int>ret=solution.plusOne(digits);
    for(int i=0;i<ret.size();i++){
        cout<<ret[i];

    }
}