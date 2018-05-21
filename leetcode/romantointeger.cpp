//
// Created by niubin on 17-9-18.
//
#include <string>
#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int graph[256]={0};
        graph['I']=1;
        graph['V']=5;
        graph['X']=10;
        graph['L']=50;
        graph['C']=100;
        graph['D']=500;
        graph['M']=1000;
        int result=graph[s[0]];
        int len=s.size();
        for(int i=0;i<len;i++){
            if(graph[s[i+1]]<=graph[s[i]]){
                result=result+graph[s[i+1]];
            }else{
                result=result+graph[s[i+1]]-2*graph[s[i]];
            }
        }
        return result;
    }
};
int main(){
    Solution solution;
    cout<<solution.romanToInt("DCXXI");
    return 0;
}