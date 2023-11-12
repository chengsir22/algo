//
// Created by 鲁红呈 on 2023/10/27.
//
#include <unordered_map>

using namespace std;


//*****************二刷******************
class LRUCache {
    struct Node {
        int key, val;
        Node *prev;
        Node *next;

        Node(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {}

        Node() : key(0), val(0), prev(nullptr), next(nullptr) {}
    };
private:
    Node *head;
    Node *tail;
    int size;
    int capacity;
    unordered_map<int, Node *> cache;
public:

    LRUCache(int capacity) : capacity(capacity), size(0) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        Node *node = cache[key];

        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = head;
        node->next = head->next;
        node->next->prev = node;
        head->next = node;

        return node->val;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            Node *node = new Node(key, value);
            cache[key] = node;
            size++;
            node->prev = head;
            node->next = head->next;
            node->next->prev = node;
            head->next = node;
            if (size > capacity) {
                Node *remove = tail->prev;
                tail->prev = remove->prev;
                remove->prev->next = tail;

                cache.erase(remove->key);
                delete remove;
                size--;
            }
        } else {
            Node *node = cache[key];
            node->val = value;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->prev = head;
            node->next = head->next;
            node->next->prev = node;
            head->next = node;
        }
    }
};


class LRUCache1 {
    struct DLinkedNode {
        int key, value;
        DLinkedNode *prev;
        DLinkedNode *next;

        DLinkedNode(int _key, int _val) : key(_key), value(_val), prev(nullptr), next(nullptr) {}

        DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    };

private:
    unordered_map<int, DLinkedNode *> cache;
    DLinkedNode *head;
    DLinkedNode *tail;
    int size;
    int capacity;
public:
    LRUCache1(int capacity) : capacity(capacity), size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        DLinkedNode *node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            DLinkedNode *node = new DLinkedNode(key, value);
            cache[key] = node;
            //  添加至双向链表头部
            node->prev = head;
            node->next = head->next;
            node->next->prev = node;
            head->next = node;
            size++;
            if (size > capacity) {
                DLinkedNode *removeNode = removeTail();
                cache.erase(removeNode->key);
                delete removeNode;
                size--;
            }
        } else {
            DLinkedNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    DLinkedNode *removeTail() {
        DLinkedNode *node = tail->prev;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        return node;
    }

    void moveToHead(DLinkedNode *node) {
        if (node->prev == head) {
            return;
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->prev = head;
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */