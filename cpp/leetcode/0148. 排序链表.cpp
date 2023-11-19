//
// Created by 鲁红呈 on 2023/11/19.
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *midNode = middleNode(head);
        ListNode *rightHead = midNode->next;
        midNode->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        return mergeTwoLists(left,right);
    }

    // 0876 变
    ListNode *middleNode(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head->next->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // 0021
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        curr->next = list1 != nullptr ? list1 : list2;
        return dummy->next;
    }
};