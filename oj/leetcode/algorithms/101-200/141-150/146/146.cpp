#include <bits/stdc++.h>

using namespace std;

class LRUCache {
    int cap, sz;

    struct Node {
        int key, val;
        Node *last, *next;

        explicit Node(int k, int v) {
            key = k, val = v;
            last = nullptr, next = nullptr;
        }
    };

    Node *head, *tail;
    unordered_map<int, Node *> map;

    void move_to_last(Node *node) {
        auto l = node->last, r = node->next;
        l->next = r, r->last = l;

        l = tail->last, r = tail;
        node->last = l, l->next = node;
        node->next = r, r->last = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity, sz = 0;
        head = new Node(-1, -1), tail = new Node(-1, -1);
        head->next = tail, tail->last = head;
    }

    int get(int key) {
        if (!map.count(key)) {
            return -1;
        }
        move_to_last(map[key]);
        return map[key]->val;
    }

    void put(int key, int value) {
        if (map.count(key)) {
            move_to_last(map[key]);
            map[key]->val = value;
        } else {
            sz++;
            auto node = new Node(key, value);
            auto l = tail->last, r = tail;
            node->last = l, l->next = node;
            node->next = r, r->last = node;
            map[key] = node;
            if (sz > cap) {
                auto to_delete = head->next;
                auto last = head, next = to_delete->next;
                last->next = next, next->last = last;
                map.erase(to_delete->key);
                delete to_delete;
            }
        }
    }
};