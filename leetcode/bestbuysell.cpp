//
// Created by niubin on 17-11-14.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int _maxProfit(vector<int>& prices) {
        int maxProfile=0;
        int len=prices.size();
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                int profile=prices[j]-prices[i];
                if(profile>maxProfile){
                    maxProfile=profile;
                }
            }
        }
        return maxProfile>0 ? maxProfile:0;
    }

public:
    int maxProfit(vector<int>&prices){
        int len=prices.size();
        if(len==0)return -1;
        int maxProfile=0;
        int minimum=prices[0];
        for(int i=0;i<len-1;i++){
           int tmp=prices[i+1]-minimum;
            if(tmp>maxProfile){
                maxProfile=tmp;
            }
            if(prices[i+1]<minimum){
                minimum=prices[i+1];
            }
        }
        return maxProfile;
    }
public:
    int _maxProfile_(vector<int>&prices){
        int len=prices.size();//
        if(len==0)return 0;
        int maxProfile=0;
        //maxprofile=(5-1)+(6-3)+(7-6)
        for(int i=1;i<len;i++){
            if(prices[i]>prices[i-1]){
                maxProfile+=prices[i]-prices[i-1];
            }
        }
        return maxProfile;


    }
};
int main(){
    vector<int>prices{7, 1, 5, 3, 6, 7};
    Solution solution;
    cout<<solution._maxProfile_(prices);
}