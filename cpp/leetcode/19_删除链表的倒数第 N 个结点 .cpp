//
// Created by 鲁红呈 on 2023/10/2.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *fast = dummy;
        ListNode *slow = dummy;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* delNode = slow->next;
        slow->next=slow->next->next;
        delete delNode;
        return dummy->next;
    }
};