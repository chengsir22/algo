//
// Created by 鲁红呈 on 2023/10/25.
//

#include <string>
#include <unordered_map>

using namespace std;

//https://leetcode.cn/problems/minimum-window-substring/solutions/258513/tong-su-qie-xiang-xi-de-miao-shu-hua-dong-chuang-k/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        for (const char &c: t) {
            ++need[c];
        }

        int needCnt = t.size();
        int n = s.size();

        int resL = 0, resR = INT_MAX;
        int r = 0, l = 0;
        for (; r < n; r++) {
            if (need[s[r]] > 0) {
                needCnt--;
            }
            need[s[r]]--;

            if (needCnt == 0) {
                while (true) {
                    if (need[s[l]] == 0) {
                        break;
                    }
                    need[s[l]]++;
                    l++;
                }
                if (r - l < resR - resL) {
                    resR = r;
                    resL = l;
                }
                need[s[l]]++;
                needCnt++;
                l++;
            }
        }
        return (resR == INT_MAX) ? string() : s.substr(resL, resR - resL + 1);
    }
};


int main() {
    Solution solution;


    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    std::string result = solution.minWindow(s, t);
    return 0;
}