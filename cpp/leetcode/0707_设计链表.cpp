//
// Created by 鲁红呈 on 2023/10/2.
//


class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode *prev;

        ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    };

    MyLinkedList() {
        head = new ListNode(0);
        tail = new ListNode(0);
        size = 0;
        head->next = tail;
        tail->prev = head;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        ListNode *cur;
        if (index < size - index) {
            cur = head;
            for (int i = 0; i <= index; i++) {
                cur = cur->next;
            }
        } else {
            cur = tail;
            for (int i = 0; i < size - index; i++) {
                cur = cur->prev;
            }
        }
        return cur->val;
    }

    void addAtHead(int val) {
        addAtIndex(0,val);
    }

    void addAtTail(int val) {
        addAtIndex(size,val);
    }

    void addAtIndex(int index, int val) {
        if (index > size) return;
        index = max(0, index);
        ListNode *prev, *succ;
        if (index <= size - index) {
            prev = head;
            for (int i = 0; i < index; i++) {
                prev = prev->next;
            }
            succ = prev->next;
        } else {
            succ = tail;
            for(int i =0 ;i<size-index;i++){
                succ = succ->prev;
            }
            prev = succ->prev;
        }

        size++;
        ListNode* newNode = new ListNode(val);
        newNode->prev = prev;
        prev->next = newNode;
        newNode->next= succ;
        succ->prev = newNode;
    }

    void deleteAtIndex(int index) {
        if(index<0|| index>=size)return;
        ListNode *prev ,*succ;
        if(index<=size-index){
            prev = head;
            for(int i =0;i<index;i++){
                prev=prev->next;
            }
            succ = prev->next->next;
        }else {
            succ =tail;
            for(int i =0;i<size-index-1;i++){
                succ = succ->prev;
            }
            prev = succ->prev->prev;
        }
        size--;
        ListNode *p = prev->next;
        prev->next = succ;
        succ->prev = prev;
        delete p;
    }

private:
    int size;
    ListNode *head;
    ListNode *tail;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */