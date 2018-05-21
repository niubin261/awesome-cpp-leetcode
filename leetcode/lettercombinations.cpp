//
// Created by niubin on 17-10-11.
//
// Input:Digit string "23"
//Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
#include <vector>
#include <string>
#include <map>

#include <iostream>

using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result{};
        if (digits.empty())
            return result;
        map<char, string> buttons;
        buttons.insert(pair<char, string>{'0', " "});
        buttons.insert(pair<char, string>{'2', "abc"});
        buttons.insert(pair<char, string>{'3', "def"});
        buttons.insert(pair<char, string>{'4', "ghi"});
        buttons.insert(pair<char, string>{'5', "jkl"});
        buttons.insert(pair<char, string>{'6', "mno"});
        buttons.insert(pair<char, string>{'7', "pqrs"});
        buttons.insert(pair<char, string>{'8', "tuv"});
        buttons.insert(pair<char, string>{'9', "wxyz"});

        vector<string> vStr;
        vStr.push_back("");
        int len = digits.length();
        for (int i = 0; i < len; i++) {
            for (int j = vStr.size() - 1; j >= 0; j--) {
                for (int k = 0; k < buttons[digits[i]].length(); k++) {
                    if (k == buttons[digits[i]].length() - 1) {
                        vStr[j] += buttons[digits[i]][k];

                    } else { vStr.push_back(vStr[j] + buttons[digits[i]][k]) ;}
                }
            }

        }
        return vStr;
    }
};
int main(){
    Solution solution;
    string string1="23";
    vector<string>ret=solution.letterCombinations(string1);
    cout<<ret.size();
    for(int i=0;i<ret.size();i++){
        cout<<ret[i]<<endl;
    }
}