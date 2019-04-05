/*
题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//运行时间：4ms
//占用内存：476k
//一定要想到递归,一次通过haha
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() == 0){
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[0]);

        auto position = find(vin.begin(),vin.end(),pre[0]);
        vector<int> vinl(vin.begin(),position);
        vector<int> vinr(position+1,vin.end());

        pre.erase(pre.begin(),pre.begin()+1);
        vector<int> prel(pre.begin(),pre.begin()+(position-vin.begin()));
        vector<int> prer(pre.begin()+(position-vin.begin()),pre.end());

        root->left = reConstructBinaryTree(prel,vinl);
        root->right = reConstructBinaryTree(prer,vinr);
        return root;
    }
};
int main() {
    Solution s;
    TreeNode *treeNode = s.reConstructBinaryTree(vector<int>{1,2,4,7,3,5,6,8}, vector<int>{4,7,2,1,5,3,8,6});
    return 0;
}
