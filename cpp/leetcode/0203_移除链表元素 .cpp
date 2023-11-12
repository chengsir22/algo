//
// Created by 鲁红呈 on 2023/10/1.
//
#include <iostream>
#include <vector>
#include <stack>
#include <array>
#include <algorithm>
#include <numeric>  // for accumulate
#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next=head;
        ListNode* cur = dummyHead;
        while(cur->next){
            ListNode* tmp = cur->next;
            if(tmp->val==val){
                cur->next=tmp->next;
                delete tmp;
            }else{
                cur=tmp;
            }
        }
        head=dummyHead->next;
        delete dummyHead;
        return  head;
    }
};

int main(int, char **) {
    Solution s;

}
