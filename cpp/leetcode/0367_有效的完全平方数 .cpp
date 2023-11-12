//
// Created by 鲁红呈 on 2023/10/1.
//
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = -1 ;
        long long r = num;
        r++;
        while(l+1!=r){
            int mid=l+(r-l>>1);
            if((long long)mid*mid<=num){
                l=mid;
            }else{
                r=mid;
            }
        }
        return l*l==num;
    }
};