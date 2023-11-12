//
// Created by 鲁红呈 on 2023/11/4.
//

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) :val(x),next(nullptr){}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur){
            ListNode* next = cur->next;
            cur->next = prev;
            prev= cur;
            cur=next;
        }
        return prev;
    }

    ListNode* reverseList2(ListNode* head) {
        if(!head||!head->next){
            return head;
        }
        ListNode *newhead = reverseList2(head->next);
        head->next->next = head;
        head->next= nullptr;
        return newhead;
    }
};