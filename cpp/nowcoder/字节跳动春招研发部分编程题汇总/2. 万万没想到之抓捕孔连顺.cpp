//
// Created by 鲁红呈 on 2023/10/18.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    vector<int> builds(N);
    for (int i = 0; i < N; i++) {
        cin >> builds[i];
    }
    long long count = 0;
    int right = 2, left = 0;
    while (left < N - 2) {
        while(right<N && builds[right]-builds[left]<=D){
            right++;
        }
        if (right-1-left>=2){
            long long num = right-1-left;
            count +=  num*(num-1)/2;
        }
        left++;
    }
    cout<<count%99997867;
    return 0;
}
// 64 位输出请用 printf("%lld")