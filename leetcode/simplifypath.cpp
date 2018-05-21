//
// Created by niubin on 17-12-3.
//
#include <string>
#include <stack>
#include <vector>
#include <boost/algorithm/string.hpp>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {

        vector<string>vString;
        splitString(path,vString,"/");
        stack<string> stackString;
        int len=vString.size();
        for(int i=0;i<len;i++){
            if(vString[i]==".")
                continue;
            else if(vString[i]==".."){
                if(!stackString.empty())
                stackString.pop();
            }
            else{
                if(vString[i]!=""){
                    stackString.push(vString[i]);
                }

            }

        }
        vector<string>result;
        while(stackString.size()){

            string &temp=stackString.top();
            result.push_back(temp);
            stackString.pop();
        }
        reverse(result.begin(),result.end());
        return output(result);

    }
private:
    void splitString(std::string s, std::vector<std::string>& v, const std::string c) {
        string stemp(s.begin()+1,s.end());
        if (stemp[stemp.length()-1]!='/'){
            stemp+="/";
        }
        std::string::size_type pos1, pos2;
        pos2 = stemp.find(c);
        pos1 = 0;
        while(std::string::npos != pos2)
        {
            v.push_back(stemp.substr(pos1, pos2-pos1));

            pos1 = pos2 + c.size();
            pos2 = stemp.find(c, pos1);
        }
        if(pos1 != stemp.length())
            v.push_back(stemp.substr(pos1));
    }

private:
    string output(vector<string>input){
        string result;
        int len=input.size();
        if(len==0){
            return result+="/";
        }
        for(int i=0,j=0;i<input.size();i++){
            result+="/";
            result+=input[i];

        }
        return result;
    }
};
int main(){
    Solution solution;
    cout<<solution.simplifyPath("/abc/...");
}