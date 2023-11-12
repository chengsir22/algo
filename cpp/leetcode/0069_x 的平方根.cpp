//
// Created by 鲁红呈 on 2023/10/1.
//
#include <vector>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
       int l=-1;
       long long r=(long long)x+1;
       int ret;
       while(l+1!=r){
           int mid = l + (r-l>>1);
           if((long long)mid*mid<=x){
               ret=mid;
               l=mid;
           }else{
               r=mid;
           }
       }
        return ret;
    }
};