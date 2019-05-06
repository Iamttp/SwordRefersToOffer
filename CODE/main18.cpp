/*
 * 题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    void doF(TreeNode *pRoot) {
        if (pRoot == nullptr) {
            return;
        }
        auto p = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = p;
        doF(pRoot->left);
        doF(pRoot->right);
    }

    void Mirror(TreeNode *pRoot) {
        doF(pRoot);
    }
};

int main() {
    return 0;
}