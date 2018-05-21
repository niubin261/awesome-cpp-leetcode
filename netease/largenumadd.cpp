//
// Created by niubin on 17-12-1.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> num2Vec(int num) {

}

string vec2String(vector<int> nums) {

}

vector<int> multiply(vector<int> nums1, vector<int> nums2) {

}

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int len1 = num1.length();
        int len2 = num2.length();
        vector<int> result(len1 + len2 - 1, 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                result[i + j] = result[i + j] + ((int) (num1[i] - '0') * (int) (num2[j] - '0'));

            }
        }
        int carry = 0;
        for (int i = 0; i < len1 + len2 - 1; i++) {
            int sum = carry + result[i];
            result[i] = (sum) % 10;
            carry = sum / 10;
        }
        int i = 0;
        while (carry != 0) {

            result.insert(result.begin() + (len1 + len2 - 1 + i), carry % 10);
            carry = carry / 10;
            i++;
        }


        reverse(result.begin(), result.end());
        int len = result.size();
        string ret(len, '0');
        for (int i = 0; i < len; i++) {
            ret[i] = result[i] + '0';
        }
        return ret;
    }
};

int main() {
    Solution solution;
    string ret = solution.multiply("9999", "99");
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i];
    }

}