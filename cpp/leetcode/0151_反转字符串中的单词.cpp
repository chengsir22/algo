//
// Created by 鲁红呈 on 2023/11/2.
//
#include <string>

using namespace std;

class Solution {
public:
    void reverse(string& s,int l,int r){
        for(int i=l,j=r;i<j;i++,j--){
            swap(s[i],s[j]);
        }
    }
    string reverseWords(string s) {
        int l = 0, r = s.size() - 1;
        while (l <= r && s[l] == ' ') l++;
        while (l <= r && s[r] == ' ') r--;
        int slow =0; 
        while(l<=r){
            if(s[l]==' '&&s[l]==s[l-1]){
                l++;
            }else {
                s[slow++]=s[l++];
            }
        }

        reverse(s,0,slow-1);

        int start = 0;
        for(int i=0;i<slow;i++){
            if(s[i]==' '){
                reverse(s,start,i-1);
                start = i+1;
            }
        }
        reverse(s,start,slow-1);
        return s.substr(0,slow);
    }
};