/*
 * 题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <list>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        list<TreeNode*> l, r;
        vector<int> res;
        if (root == nullptr)
            return res;
        res.push_back(root->val);
        l.push_back(root->left);
        r.push_back(root->right);
        while (l.size() && r.size()) {
            auto np = l.front();
            l.pop_front();
            if (np) {
                res.push_back(np->val);
                l.push_back(np->left);
                r.push_back(np->right);
            }

            np = r.front();
            r.pop_front();
            if (np) {
                res.push_back(np->val);
                l.push_back(np->left);
                r.push_back(np->right);
            }
        }
        return res;
    }
};

int main() {
    auto* p1 = new TreeNode(1);
    /*auto* p2 = new TreeNode(2);
    auto* p3 = new TreeNode(3);
    auto* p4 = new TreeNode(4);
    auto* p5 = new TreeNode(5);
    auto* p6 = new TreeNode(6);
    auto* p7 = new TreeNode(7);
    auto* p8 = new TreeNode(8);
    auto* p9 = new TreeNode(9);
*/
    /*p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = p6;
    p3->right = p7;
    p7->left = p8;
    p8->right = p9;*/
    Solution s;
    s.PrintFromTopToBottom(p1);
    return 0;
}