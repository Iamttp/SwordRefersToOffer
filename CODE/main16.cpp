/*
 * 题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
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
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
        // 头结点
        ListNode *res = new ListNode(0);
        ListNode *resTemp = res;
        while (pHead1 && pHead2) {
            if (pHead1->val < pHead2->val) {
                resTemp->next = pHead1;
                resTemp = resTemp->next;
                pHead1 = pHead1->next;
            } else {
                resTemp->next = pHead2;
                resTemp = resTemp->next;
                pHead2 = pHead2->next;
            }
        }
        if (pHead1 == NULL)
            resTemp->next = pHead2;
        else if (pHead2 == NULL)
            resTemp->next = pHead1;
        return res->next;
    }
};

int main() {
    Solution s;
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(2);
    ListNode *l5 = new ListNode(4);
    ListNode *l6 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;

    l4->next = l5;
    l5->next = l6;
    ListNode *res = s.Merge(l1, l4);
    while (res) {
        cout << res->val;
        res = res->next;
    }
    return 0;
}
