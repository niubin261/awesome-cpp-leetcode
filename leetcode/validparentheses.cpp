//
// Created by niubin on 17-9-18.
//
#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                charStack.push(s[i]);
            }
            if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (charStack.empty()) {
                    return false;
                }
                if (charStack.top() != '(' && s[i] == ')'
                    || (charStack.top() != '[' && s[i] == ']')
                    || (charStack.top() != '{' && s[i] == '}')) {
                    return false;
                }
                charStack.pop();
            }

        }
        if (charStack.empty()) {
            return true;
        } else {
            return false;
        }

    }
};

int main() {
    string s = "]";
    Solution solution;
    cout << solution.isValid(s);
}