/*
 * 题目描述
输入一个链表，反转链表后，输出新链表的表头。
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode *ReverseList(ListNode *pHead) {
        if (pHead == NULL || pHead->next == NULL)
            return pHead;
        ListNode *l = NULL, *c = pHead, *r = pHead->next;
        while (c) {
            c->next = l;
            l = c;
            c = r;
            if (r != NULL)
                r = r->next;
        }
        return l;
    }
};

int main() {
    Solution s;
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    ListNode *res = s.ReverseList(l1);
    while (res) {
        cout << res->val;
        res = res->next;
    }
    return 0;
}
