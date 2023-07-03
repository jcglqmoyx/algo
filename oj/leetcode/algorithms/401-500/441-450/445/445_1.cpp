#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr, *cur = head;
        while (cur) {
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        l1 = reverse(l1), l2 = reverse(l2);
        auto dummy = new ListNode(-1), cur = dummy;
        int sum, carry = 0;
        while (l1 && l2) {
            sum = l1->val + l2->val + carry;
            cur->next = new ListNode(sum % 10);
            carry = sum / 10;
            cur = cur->next, l1 = l1->next, l2 = l2->next;
        }
        while (l1) {
            sum = l1->val + carry;
            cur->next = new ListNode(sum % 10);
            carry = sum / 10;
            cur = cur->next, l1 = l1->next;
        }
        while (l2) {
            sum = l2->val + carry;
            cur->next = new ListNode(sum % 10);
            carry = sum / 10;
            cur = cur->next, l2 = l2->next;
        }
        if (carry) cur->next = new ListNode(1);
        auto res = dummy->next;
        delete dummy;
        return reverse(res);
    }
};