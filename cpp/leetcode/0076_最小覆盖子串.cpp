//
// Created by 鲁红呈 on 2023/10/25.
//

#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need,window;
        for(char c:t) need[c]++;

        int left=0,right=0;
        int valid = 0;

        int start=0,len=INT_MAX;
        while(right<s.size()){
            char c=s[right];
            right++;
            if (need.count(c)){
                window[c]++;
                if(window[c]==need[c]) valid++;
            }

            printf("window (%d,%d)",left,right);
            // 判断左窗口是否需要收缩
            while(valid==need.size()){
                if(right-left<len){
                    start=left;
                    len=right-left;
                }
                char d=s[left];
                left++;
                if(need.count(d)){
                    if(window[d]==need[d]) valid--;
                    window[d]--;
                }
            }
        }
        return len==INT_MAX?"":s.substr(start,len);
    }
};


class Solution1 {
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