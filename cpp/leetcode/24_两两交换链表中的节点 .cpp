//
// Created by 鲁红呈 on 2023/10/2.
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if( head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *subHead = swapPairs(head->next->next);
        ListNode *headNext = head->next;
        headNext->next = head;
        head->next = subHead;
        return headNext;
    }
};