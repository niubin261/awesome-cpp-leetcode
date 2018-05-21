//
// Created by niubin on 17-12-11.
//
#include <string>
#include <vector>
#include <iostream>


using namespace std;
int length(vector<string>ip){
    int len=0;
    for(int i=0;i<ip.size();i++){
        len+=ip[i].length();
    }
    return len;
}
void backTrack(int start,string candidate,vector<string>&ip,int k,vector<vector<string>>&results){
    int len=length(ip);
    if(k==4&&len==candidate.length()){
        return results.push_back(ip);
    }
    if(k==4&&len!=candidate.length()){
        return;
    }
    if(k!=4&&len==candidate.length()){
        return;
    }
    k=k+1;
    for(int i=1;i<=3;i++){
        string temp=candidate.substr(start,i);
        if(temp.length()!=i)continue;
        if(atoi(temp.c_str())>=256)continue;
        if(temp[0]=='0'&&i!=1)continue;
        ip.push_back(temp);
        start=start+i;
        backTrack(start,candidate,ip,k,results);
        start=start-i;
        ip.pop_back();
    }

}
int main(){
    string candidate="010010";
    vector<vector<string>>ret;
    vector<string>ip;
    backTrack(0,candidate,ip,0,ret);
    vector<string>result;

    for(int i=0;i<ret.size();i++){
        string temp="";
        for(int j=0;j<ret[i].size();j++){
            temp+=ret[i][j];
            temp+=".";
        }
        temp.pop_back();
        result.push_back(temp);
    }
    for(int i=0;i<result.size();i++){
        cout<<result[i];
        cout<<endl;
    }
}
