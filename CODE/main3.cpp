/*
 * 题目描述
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
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

// 法一：
//class Solution {
//public:
//    vector<int> printListFromTailToHead(ListNode *head) {
//        vector<int> vi;
//        ListNode *headTemp = head;
//        while (headTemp) {
//            vi.push_back(headTemp->val);
//            headTemp = headTemp->next;
//        }
//        reverse(vi.begin(), vi.end());
//        return vi;
//    }
//};

//测试没有问题呀
//但是您的代码已保存
//段错误:您的程序发生段错误，可能是数组越界，堆栈溢出（比如，递归调用层数太多）等情况引起
//QAQ

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode *head) {
        if (head->next == NULL)
            return vector<int>{head->val};
        ListNode *l = NULL, *c = head, *r = head->next;

        //画图理解反转链表
        while (c) {
            c->next = l;
            l = c;
            c = r;
            if (r)
                r = r->next;
        }
        head = l;

        vector<int> vt;
        while (l) {
            vt.push_back(l->val);
            l = l->next;
        }
        return vt;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(3);
    ListNode *se = new ListNode(5);
    ListNode *th = new ListNode(7);
    ListNode *fo = new ListNode(2);
    ListNode *se1 = new ListNode(5);
    ListNode *se2 = new ListNode(8);

    head->next = se, se->next = th, th->next = fo;
    fo->next = se1, se1->next = se2;
    vector<int> x = s.printListFromTailToHead(head);
    for(auto it:x)
        cout << it;
    return 0;
}
