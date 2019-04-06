/*题目描述
输入一个链表，输出该链表中倒数第k个结点。
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
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k) {
        if(pListHead==NULL)
            return NULL;
        ListNode *l = pListHead, *r = pListHead;
        while (k--) {
            if (r != NULL)
                r = r->next;
            else
                return NULL;
        }
        while (r) {
            r = r->next;
            l = l->next;
        }
        return l;
    }
};

int main() {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    l1->next = l2;
    l2->next = l3;
    Solution s;
    s.FindKthToTail(l1, 3);
    return 0;
}
