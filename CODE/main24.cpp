/*
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)*/
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

/*
 * 不确定这样就可以了
 * */
class Solution {
public:
    vector<vector<int> > res;
    vector<int> myVec;

    void myFindPath(TreeNode *root, int expectNumber) {
        if (root == nullptr)
            return;
        myVec.push_back(root->val);
        expectNumber -= root->val;
        if (expectNumber == 0 && (root->left == nullptr && root->right == nullptr)) {
            res.push_back(myVec);
        }
        myFindPath(root->left, expectNumber);
        myFindPath(root->right, expectNumber);
        myVec.pop_back();
    }

    vector<vector<int> > FindPath(TreeNode *root, int expectNumber) {
        myFindPath(root, expectNumber);
        return res;
    }
};

int main() {
    Solution s;
    TreeNode *root1 = new TreeNode(1);
    TreeNode *root2 = new TreeNode(2);
    TreeNode *root3 = new TreeNode(3);
    TreeNode *root4 = new TreeNode(4);
    TreeNode *root5 = new TreeNode(5);
    TreeNode *root6 = new TreeNode(6);
    root1->left = root2;
    root1->right = root3;
    root2->left = root4;
    root2->right = root5;
    root3->left = root6;
    s.FindPath(root1, 8);
    return 0;
}